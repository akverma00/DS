#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;
ll K;
/***************************************************************************/
ll func(ll n, ll k, vector<vector<ll>> &dp)
{

    if (n == 0)
        return 1;
    if (k == 0)
        return 0;
    if (dp[n][k] != -1)
        return dp[n][k];

    ll ans = func(n - 1, k - 1, dp) - ((k > 1) ? func(n - 1, k - 2, dp) : 0);
    ans *= (K - k + 1);
    ans += func(n - 1, K - 1, dp) - func(n - 1, k - 1, dp) + func(n, k - 1, dp);
    ans += mod;
    ans %= mod;

    return dp[n][k] = ans;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    K = k;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));
    ll tmp = func(n, k - 1, dp);
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans * k) % mod;
    }
    ans -= dp[n][k - 1];
    ans += mod;
    ans %= mod;
    cout << ans << "\n";

    return 0;
}