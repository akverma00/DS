#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll h, c, q, a, b, k, t, s, d, e, f, m, n, g, x, y;
    string s1, s2, in1, in2;
    cin >> n >> q >> k;
    vector<vector<ll>> arr(n + 1); //[P,A,B,K,1000000-K]
    arr[0] = {-1, 1, 1, k, 1000000 - k};
    for (int i = 2; i <= n; i++)
    {
        cin >> a >> b >> c;
        d = (arr[a][3] * b + arr[a][4] * c) % mod;
        arr[i] = {a, b, c, d, (1000000 - d + mod) % mod};
    }

    cout << s1;
    return;
}
int main()
{
    ll t = 1, n, k;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}