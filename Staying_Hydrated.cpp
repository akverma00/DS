#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll h, c, q, a, b, k, t, s, d, e, f, m, n, g, x, y;
    string s1, in1, in2;
    cin >> k;
    vector<ll> arrX, arrY;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c >> d;
        arrX.push_back(a);
        arrX.push_back(c);
        arrY.push_back(b);
        arrY.push_back(d);
    }
    sort(arrX.begin(), arrX.end());
    sort(arrY.begin(), arrY.end());
    vll ans(2);
    ans[0] = arrX[k - 1];
    ans[1] = arrY[k - 1];
    cout << ans[0] << " " << ans[1];
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