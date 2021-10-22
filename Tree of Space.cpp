/* https://leetcode.com/discuss/interview-question/1221635/juspay-hackathon-round-question */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
    return tin[p] <= tin[x] && tout[p] >= tout[x];
}

bool lock(ll x, ll uid)
{
    if (is_locked.count(x) || cnt[x])
        return false;

    ll p = par[x];
    while (p != -1)
    {
        if (is_locked.count(p))
            return false;

        p = par[p];
    }
    changeCount(x, 1);
    is_locked[x] = uid;
    return true;
}
bool unlock(ll x, ll uid)
{
    if (is_locked.count(x) == 0 || is_locked[x] != uid)
        return false;

    changeCount(x, -1);
    is_locked.erase(x);

    return true;
}
bool upgradeLock(ll x, ll uid)
{
    if (cnt[x] == 0)
        return false;

    vector<ll> vv;
    for (auto xx : is_locked)
    {
        if (checkDes(xx.first, x) && is_locked[xx.first] != uid)
        {
            return false;
        }
    }
    changeCount(x, 1);
    for (auto xx : is_locked)
    {
        if (checkDes(xx.first, x))
        {
            vv.push_back(xx.first);
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
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;
    cnt.resize(n + 1, 0);
    par.resize(n + 1, -1);
    adj.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    t = 0;
    string s;
    cin >> s;
    name[s] = 0;
    par[0] = -1;
    for (ll i = 1; i < n; i++)
    {
        cin >> s;
        name[s] = i;
        adj[(i - 1) / m].push_back(i);
        par[i] = (i - 1) / m;
    }
    dfs(0);
    while (q--)
    {
        string x;
        ll op, uid;
        cin >> op >> x >> uid;

        if (op == 1)
        {
            if (lock(name[x], uid))
                cout << "true\n";
            else
            {
                cout << "false\n";
            }
        }
        else if (op == 2)
        {
            if (unlock(name[x], uid))
                cout << "true\n";
            else
                cout << "false\n";
        }
        else
        {
            if (upgradeLock(name[x], uid))
                cout << "true\n";
            else
                cout << "false\n";
        }
    }
    return 0;
}