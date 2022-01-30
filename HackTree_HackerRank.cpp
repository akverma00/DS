/*
The cost of the path 6 5-31in the above tree is 42 31 20- 10-103
A Vertical Path in a tree is the path that is going up towards the root of the tree. t is
not necessary for the path to end at the root.
Given a tree with n nodes and an integer k Find the number of vertical paths such
that the (cost of the path)k-0where represents the modulo operation
Note: The modulo operation returns the remainder of a division after one number is
divided by another. For example-5 9 2-1.

Sample Case 0

cost (1,2,2,1,2)
n = 5, m= 4
2 3
2 1
1 4
2 5
k=2
Sample Output
6


*/
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

#define ll long long int
ll ans = 0;
map<ll, ll> mp;
ll k;

const int MXN = 2e5 + 12;
const ll mod = 1e9 + 7;

bool vis[MXN];
vector<int> adj[MXN];
void dfs(vector<int> cost, int src, map<int, int> &cnt, int sum, int k, long long &ans)
{
    vis[src] = 1;
    sum += cost[src];
    sum %= k;
    ans += cnt[sum];
    cnt[sum]++;
    for (auto v : adj[src])
    {
        if (!vis[v])
        {
            dfs(cost, v, cnt, sum, k, ans);
        }
    }
    cnt[sum]--;
}

int countVerticalPaths(vector<int> cost, int edgeNodes, vector<int> from, vector<int> to, int k)
{
    ll ans = 0;
    for (int i = 0; i < from.size(); i++)
    {
        from[i]--;
        to[i]--;
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }
    map<ll, ll> cnt;
    cnt[0] = 1;
    dfs(cost, 0, cnt, 0, k, ans);
    return ans;
}

void solve()
{
    ll n, a, b, x, y, k, c = mod, m1, m2, rr, cc;
    string s1;
    ans = 0;

    return;
}
int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}