#define ll long long int
#include <bits/stdc++.h>
using namespace std;
#define vll vector<ll>
const ll mod = 1e9 + 7;
// vector<ll> fact(200005, 0);
// void pre()
// {
//     fact[0] = 1;
//     for (int i = 1; i <= 200001; i++)
//     {
//         fact[i] = (fact[i - 1] * i) % mod;
//     }
//     return;
// }
void solve()
{
    ll h, c, q, a, k, b, t, s, d, e, f, m, n, g, x, y;
    string s1, in1, in2, ans;
    vector<vll> arr(3, vll(3));
    vector<vll> tries;
    vll type(3), times(3);
    cin >> n >> type[0] >> type[1] >> type[2] >> times[0] >> times[1] >> times[2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            tries.push_back({i, j});
        }
    }
    //cout << tries.size() << "\n";
    c = 1e18;
    a = 0;
    do
    {
        d = 0;
        vll type1 = type, times1 = times;
        for (int i = 0; i < tries.size(); i++)
        {
            ll temp = min(type1[tries[i][0]], times1[tries[i][1]]);
            type1[tries[i][0]] -= temp;
            times1[tries[i][1]] -= temp;
            d += (arr[tries[i][0]][tries[i][1]] * temp);
            //cout << temp;
        }
        //cout << d;
        c = min(c, d);

    } while (next_permutation(tries.begin(), tries.end()));
    //cout << a << "\n";
    cout << c;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1, k;
    cin >> t;
    //pre();
    for (int i = 0; i < t; i++)
    {
        solve();
        cout << "\n";
    }
    return 0;
}