#define ll long long int
#include <bits/stdc++.h>
using namespace std;
#define vll vector<ll>
const ll mod = 1e9 + 7;
vector<ll> fact(200005, 0);
void pre()
{
    fact[0] = 1;
    for (int i = 1; i <= 200001; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    return;
}
void solve()
{
    ll h, c, q, a, k, b, t, s, d, e, f, m, n, g, x, y;
    string s1, in1, in2, ans;
    cin >> n >> s1;
    vector<vector<int>> dp(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = dp[i];
        dp[i + 1][s1[i] - 'a']++;
    }
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        c = 1;
        for (int i = 0; i < 26; i++)
        {
            d = dp[b][i] - dp[a - 1][i];

            c = (c * fact[d]) % mod;
        }
        cout << c % mod << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1, k;
    cin >> t;
    pre();
    for (int i = 0; i < t; i++)
    {
        solve();
        //cout << "\n";
    }
    return 0;
}