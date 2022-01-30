#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll h, c, q, a, b, k, t, s, d, e, f, m, n, g, x, y;
    string s1, s2, in1, in2;
    cin >> n >> s1;
    a = b = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '(')
            a++;
        else
            b++;
    }
    c = min(a, b) * 2;
    cout << c << "\n";

    return;
}
int main()
{
    ll t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve();
        // cout << "\n";
    }
    return 0;
}