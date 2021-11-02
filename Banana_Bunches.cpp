#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
ll fun(ll s, ll e, vector<vll> &arr)
{
    ll ans = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (e < arr[i][0] || arr[i][1] < s)
        {
            ans = min(ans, arr[i][1] - arr[i][0] + 1);
        }
    }
    return ans;
}
bool comp(const vll &a1, const vll &a2)
{
    return a1[0] <= a2[0];
}
void solve()
{
    ll h, c, q, a, k, b, t, s, d, e, f, m, n, g, x, y;
    string s1, in1, in2;
    cin >> n >> k;
    vll arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<ll, vector<vll>> sub;
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = i; j < n; j++)
        {
            s += arr[j];
            if (s <= k)
                sub[s].push_back({i, j});
            else
                break;
        }
    }
    ll ans = INT_MAX;
    for (auto &xx : sub)
    {
        sort(xx.second.begin(), xx.second.end(), comp);
    }
    for (auto xxxx : sub)
    {
        ll xx = xxxx.first;
        auto &xxv = xxxx.second;
        ll f1 = k - xx;
        if (f1 > 0 && sub.find(f1) != sub.end())
        {
            for (int i = 0; i < xxv.size(); i++)
            {
                ll d = fun(xxv[i][0], xxv[i][1], sub[f1]);
                ans = min(ans, xxv[i][1] - xxv[i][0] + 1 + d);
            }
        }
    }

    for (int i = 0; i < sub[k].size(); i++)
    {
        ans = min(ans, sub[k][i][1] - sub[k][i][0] + 1);
    }
    if (ans >= INT_MAX)
        ans = -1;
    cout << ans;
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