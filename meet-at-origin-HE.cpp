#define ll int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll h, c, q, a, k, b, t, s, d, e, f, m, n, g, x, y;
    string s1, in1, in2, ans;
    cin >> s1;
    a = b = 0;
    for (auto xx : s1)
    {
        if (xx == 'L')
            a--;
        else if (xx == 'R')
            a++;
        else if (xx == 'U')
            b++;
        else
            b--;
    }
    a = abs(a);
    b = abs(b);
    c = a / 2 + a % 2 + b / 2 + b % 2;
    cout << c;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1, k;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
        cout << "\n";
    }
    return 0;
}