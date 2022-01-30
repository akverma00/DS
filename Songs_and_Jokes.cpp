#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll h, c, q, a, b, k, t, d, e, f, m, n, g, x, y;
    string s1, s2, in1, in2;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> s1;
    ll ans = 0;
    char cur = s1[0];
    ll val = arr[0];
    ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (cur == s1[i])
        {
            ans -= val;
            val = max(val, arr[i]);
            ans += val;
        }
        else
        {
            val = arr[i];
            ans += val;
        }
        cur = s1[i];
    }

    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve();
        // cout << "\n";
    }
    return 0;
}