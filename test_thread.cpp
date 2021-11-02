/*
g++ -pthread abc.cpp

*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
mutex m1;

vector<vector<ll>> adj;
// map<ll,string> key;
unordered_map<string, ll> name;
vector<ll> par;
map<ll, ll> is_locked;
vector<ll> cnt;
ll t = 0;
vector<ll> tin, tout;

void dfs(ll src)
{
	tin[src] = ++t;
	for (auto xx : adj[src])
	{
		dfs(xx);
	}
	tout[src] = ++t;
}

void changeCount(ll x, ll val)
{
	ll p = par[x];
	while (p != -1)
	{
		cnt[p] += val;
		p = par[p];
	}
}

bool checkDes(ll x, ll p)
{
	// while(x!=-1)
	// {
	// 	if(x==p)
	// 	return true;

	// 	x=par[x];
	// }

	return tin[p] <= tin[x] && tout[p] >= tout[x];

	return false;
}

void lockk(ll x, ll uid)
{
	//   lock_guard<mutex> lock(m1);

	if (is_locked.count(x) || cnt[x])
	{

		cout << "false\n";
		return;
	}

	ll p = par[x];
	while (p != -1)
	{
		if (is_locked.count(p))
		{
			cout << "false\n";
			return;
		}

		p = par[p];
	}
	changeCount(x, 1);
	is_locked[x] = uid;
	cout << "true\n";
	return;
}
void unlockk(ll x, ll uid)
{
	// lock_guard<mutex> lock(m1);
	if (is_locked.count(x) == 0 || is_locked[x] != uid)
	{
		cout << "false\n";
		return;
	}

	changeCount(x, -1);
	is_locked.erase(x);

	cout << "true\n";
	return;
}
void upgradeLockk(ll x, ll uid)
{
	// lock_guard<mutex> lock(m1);
	if (cnt[x] == 0)
	{
		cout << "false\n";
		return;
	}

	vector<ll> vv;
	for (auto xx : is_locked)
	{
		if (checkDes(xx.first, x) && is_locked[xx.first] != uid)
		{
			cout << "false\n";
			return;
		}
	}
	// is_locked[x]=uid;
	changeCount(x, 1);

	for (auto xx : is_locked)
	{
		if (checkDes(xx.first, x))
		{
			vv.push_back(xx.first);
			// 			changeCount(xx.first,-1);
			// 		is_locked.erase(xx.first);
		}
	}

	cnt[x] = 0;
	changeCount(x, -vv.size());

	for (auto cc : vv)
	{
		is_locked.erase(cc);
		ll p = par[cc];
		while (p != -1 && cnt[p] > 0)
		{
			cnt[p] = 0;

			p = par[p];
		}
	}

	is_locked[x] = uid;

	cout << "true\n";
	return;
}
void solve(ll op, string x, ll uid)
{
	lock_guard<mutex> lock(m1);
	cout << op << " " << x << " " << uid << " : ";
	if (op == 1)
	{
		lockk(name[x], uid);
	}
	else if (op == 2)
	{
		unlockk(name[x], uid);
	}
	else
	{
		upgradeLockk(name[x], uid);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	ll n, m, q;
	cin >> n >> m >> q;
	cnt.resize(n + 1, 0);
	par.resize(n + 1, -1);
	adj.resize(n + 1);
	tin.resize(n + 1);
	tout.resize(n + 1);
	// dfs(0);
	string s;
	cin >> s;
	// key[0]=s;
	name[s] = 0;
	par[0] = -1;

	for (ll i = 1; i < n; i++)
	{
		cin >> s;
		// key[i]=s;
		name[s] = i;
		adj[(i - 1) / m].push_back(i);
		par[i] = (i - 1) / m;
	}
	dfs(0);

	// thread t1(lock,)

	thread t1(solve, 1, "China", 9);
	thread t2(solve, 1, "India", 9);
	thread t3(solve, 3, "Asia", 9);
	thread t4(solve, 2, "India", 9);
	thread t5(solve, 2, "Asia", 9);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	/*
	while(q--)
	{
		string x;
		ll op,uid;
		cin>>op>>x>>uid;


		thread t(solve,op,x,uid);
		t.join();
	}


	*/

	return 0;
}
