#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll h, c, q, a, k, b, t, s, d, e, f, m, n, g, x, y;
    string s1, in1, in2;
    cin >> n >> a;

    if (a <= 2 && n == 5)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    if (n == 4 && a <= 1)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    vector<pair<ll, ll>> arr;
    if (n == 3)
    {
        cout << "POSSIBLE\n";
        cout << 0 << " " << 0 << "\n";
        cout << 0 << " " << 1 << "\n";
        cout << a << " " << 0;
        return;
    }
    else if (n == 4)
    {
        cout << "POSSIBLE\n";
        if (a % 2)
        {
            cout << 0 << " " << 0 << "\n";
            cout << 0 << " " << 1 << "\n";
            cout << (ll)(a / 2) << " " << 1 << "\n";
            cout << (ll)(a / 2 + 1) << " " << 0;
            return;
        }
        else
        {
            cout << 0 << " " << 0 << "\n";
            cout << 0 << " " << 1 << "\n";
            cout << (ll)(a / 2) << " " << 0 << "\n";
            cout << (ll)(a / 2) << " " << 1;
            return;
        }
    }
    else
    {
        cout << "POSSIBLE\n";
        cout << 0 << " " << 0 << "\n";
        cout << 0 << " " << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << a - 1 << " " << 2 << "\n";
        cout << 1 << " " << 0;
        return;
    }

    // a /= 2;
    // if (n == 3)
    // {
    //     if (a<1)
    //     {
    //         cout << "IMPOSSIBLE";
    //         return;
    //     }
    //     else
    //     {
    //         cout << "POSSIBLE\n";
    //         cout<<"0 0\n0 2\n"<<a<<" 1";
    //         return;
    //     }
    // }
    // else if(n==4)
    // {
    //     if (a<1)
    //     {
    //         cout << "IMPOSSIBLE";
    //         return;
    //     }
    //     else
    //     {
    //         cout << "POSSIBLE\n";
    //         cout<<"0 0\n0 1\n"<<a<<" 0\n"<<"1";
    //         return;
    //     }
    // }
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