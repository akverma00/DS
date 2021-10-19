
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

ll solve2(ll i, ll p, ll &n, ll &k, ll &x, vector<vll> &dp)
{
    if (i == n)
        return 1;

    ll &ans = dp[i][p];
    if (ans != -1)
        return ans;
    ans = 0;

    for (int j = 1; j <= k; j++)
    {

        if (j != p)
        {
            ans += solve2(i + 1, j, n, k, x, dp);
            ans %= mod;
        }
    }

    if (p == x)
        ans += solve2(i + 1, p, n, k, x, dp);

    return ans;
}
void solve()
{
    ll n, k, x;

    cin >> n >> k >> x;
    vector<vll> dp(n + 1, vll(k + 1, -1));
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {

        ans += solve2(1, i, n, k, x, dp);
        ans %= mod;
    }
    //ll ans = solve2(-1, n, k, dp, x);
    cout << ans;
    return;
}
int main()
{
    ll t = 1, n, k;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}