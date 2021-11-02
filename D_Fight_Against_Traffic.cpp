#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
void bfs(ll src, vll &dis, vector<vll> &egg)
{
    queue<ll> qq;
    qq.push(src);
    dis[src] = 0;
    ll step = 0;
    while (!qq.empty())
    {
        ll u = qq.front();
        qq.pop();
        for (ll v : egg[u])
        {
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                qq.push(v);
            }
        }
    }
    return;
}
void solve()
{
    int n, m, src, a, b, dest;
    cin >> n >> m >> src >> dest;
    src--;
    dest--;
    vector<vll> egg(n);
    vector<vll> edge(n, vector<ll>(n, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        egg[a].push_back(b);
        egg[b].push_back(a);
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    vll disS(n, INT_MAX), disD(n, INT_MAX);
    bfs(src, disS, egg);
    bfs(dest, disD, egg);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (edge[i][j] == 0 && disS[i] + disD[j] + 1 >= disS[dest] && disS[j] + disD[i] + 1 >= disS[dest])
                ans++;
        }
    }
    cout << ans;
}
int main()
{
    ll t = 1, n, k;
    //cin >> t;
    for (int i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve();
        // cout << "\n";
    }
    return 0;
}