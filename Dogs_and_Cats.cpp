#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll h, c, q, a, b, t, s, d, e, f, m, n, g, x, y;
    string s1, in1, in2;
    cin >> n >> d >> c >> m;
    cin >> s1;
    in1 = "YES";
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == 'D')
        {
            if (d == 0)
            {
                in1 = "NO";
                break;
            }
            else
            {
                d--;
                c += m;
            }
        }
        else
        {
            if (c == 0)
            {
                in1 = "NO";
                break;
            }
            else
            {
                c--;
            }
        }
        s1[i] = '*';
    }
    if (in1 == "YES")
    {
        cout << in1;
        return;
    }
    in1 = "YES";
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == 'D')
        {
            in1 = "NO";
            break;
        }
    }
    cout << in1;
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