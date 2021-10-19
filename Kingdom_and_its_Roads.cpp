#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
ll parent(ll u, vll &par)
{
    if (par[u] == u)
        return u;
    return par[u] = parent(par[u], par);
}
void union1(ll u, ll v, vector<ll> &par)
{
    ll x = parent(v, par);
    ll y = parent(u, par);
    if (x == y)
        return;
    par[x] = y;
}
void solve()
{
    int n, m, src, k, a, b, dest, c;
    cin >> n >> m;
    vector<vll> edge;
    vll par(n + 1);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        union1(a, b, par);
    }
    cin >> k;
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < k; i++)
    {
        ll x = parent(edge[i][1], par);
        ll y = parent(edge[i][2], par);
        if (x == y)
            continue;
        ans += edge[i][0];
        union1(x, y, par);
    }

    cout << ans;
}
int main()
{
    ll t = 1, n, k;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}