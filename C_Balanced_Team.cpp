
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll h, c, q, a, b, t, s, d, e, n, f, g, x, y;
    cin >> n;
    vll arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    a = 0;
    c = 1;
    for (int i = 0; i < n; i++)
    {
        while (arr[i] - arr[a] > 5)
            a++;
        c = max(c, i - a + 1);
    }
    cout << c;
}
int main()
{
    ll t = 1, n, k;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "\n";
    }
    return 0;
}