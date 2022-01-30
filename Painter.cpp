#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
map<char, vector<char>> dp;
void solve()
{
    ll h, c, q, a, b, t, s, d, e, f, m, n, g, x, y;
    string s1, s2, in1, in2;
    cin >> n >> s1;
    c = 0;
    map<char, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        for (auto xx : dp[s1[i]])
        {
            mp[xx].push_back(i);
        }
    }
    for (auto &xx : mp)
    {
        for (int i = 0; i < xx.second.size(); i++)
        {
            if (i == 0 || xx.second[i - 1] + 1 != xx.second[i])
                c++;
        }
    }

    cout << c;
    return;
}
int main()
{
    ll t = 1, n, k;
    cin >> t;
    dp['R'] = {'R'};
    dp['B'] = {'B'};
    dp['Y'] = {'Y'};
    dp['U'] = {};
    dp['G'] = {'Y', 'B'};
    dp['O'] = {'R', 'Y'};
    dp['P'] = {'R', 'B'};
    dp['A'] = {'R', 'Y', 'B'};
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}