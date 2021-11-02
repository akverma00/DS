#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
#define vll vector<ll>
#define pll pair<ll, ll>
#define pii pair<int, int>
const long long int inf = 1e18;
void solve()
{
    ll a, b, c, d, e, f, n, m, q, k, s, p;
    string s1, s2, s3;
    cin >> n;
    vll arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 0;
    c = 0;
    c++;
    while (i < n)
    {
        if (0 < (arr[i] - i - c))
        {
            c += (arr[i] - i - c);
        }
        i++;
    }
    c--;
    cout << c << "\n";
    return;
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}