#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pll array<ll, 2>
ll timer;
bool is_ancestor(ll u, ll v, vll &tin, vll &tout)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
};
ll lca(ll a, ll b, vll &tin, vll &tout, vector<vll> &binlift)
{
    if (is_ancestor(a, b, tin, tout) == true)
        return a;
    if (is_ancestor(b, a, tin, tout) == true)
        return b;
    for (ll i = 20; i >= 0; i--)
    {
        if (is_ancestor(binlift[a][i], b, tin, tout) == false)
            a = binlift[a][i];
    }
    return binlift[a][0];
};
void dfs(vector<vector<pll>> &egg, ll u, ll p, vll &tin, vll &tout, vll &depth, vll &par, vll &val, ll cur)
{
    tin[u] = timer++;
    par[u] = p;
    val[u] = cur;
    for (auto v : egg[u])
    {
        if (v[0] != p)
        {
            depth[v[0]] = depth[u] + 1;
            dfs(egg, v[0], u, tin, tout, depth, par, val, cur + v[1]);
        }
    }
    tout[u] = timer++;
};
void solve()
{
    ll n, q, r, a, b, c;
    cin >> n >> q >> r;
    timer = 0;
    ll maxlogn = 21;
    vector<vector<pll>> egg(n + 1);
    vector<vll> binlift(n + 1, vll(maxlogn + 1));
    vll tin(n + 1, 0), tout(n + 1, 0), par(n + 1);
    vll depth(n + 1, -1), val(n + 1, 0);
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        egg[a].push_back({b, c});
        egg[b].push_back({a, c});
    }
    tin[0] = 0;
    dfs(egg, r, 0, tin, tout, depth, par, val, 0);
    tout[0] = timer;
    depth[r] = 1;
    for (ll i = 1; i <= n; i++)
    {
        binlift[i][0] = par[i];
    }
    for (ll j = 1; j <= maxlogn; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            binlift[i][j] = binlift[binlift[i][j - 1]][j - 1];
        }
    }
    while (q--)
    {
        cin >> a >> b;
        c = lca(a, b, tin, tout, binlift);
        c = val[a] + val[b] - 2 * val[c];
        cout << c << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}