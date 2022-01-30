#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
vector<vector<ll>> dp(26, vector<ll>(26, INT_MAX));
void solve()
{
    ll h, c, q, a, b, t, s, d, e, f, m, n, g, x, y;
    string s1, s2, in1, in2;
    cin >> s1 >> s2;
    c = 0;

    set<int> se;
    for (auto xx : s2)
        se.insert(xx);
    for (auto xx : s1)
    {
        ll ans = INT_MAX;
        for (auto yy : se)
        {
            ans = min(ans, dp[xx - 'a'][yy - 'a']);
        }
        c += ans;
    }

    cout << c;
    return;
}
int main()
{
    ll t = 1, n, k;
    cin >> t;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            dp[i][j] = dp[j][i] = min(abs(i - j), 26 - abs(i - j));
        }
    }
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}