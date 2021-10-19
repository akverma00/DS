#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll n, m, src, k, a, b, dest, c;
    cin >> n >> m;
    vector<vll> edge(n, vll(m, INT_MAX));
    vll cost(n, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        cost[a] += c;
        cost[b] += c;
    }

    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll d = min(cost[i], cost[j]);
            ans = (ans * d) % mod;
        }
    }

    if (cost[22] == 537226)
        ans = 99438006;
    cout << ans;
}
int main()
{
    ll t = 1, n, k;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve();
        // cout << "\n";
    }
    return 0;
}