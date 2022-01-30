#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
map<string, char> dp;
vector<pair<string, char>> dp1;
void solve()
{
    ll h, c, q, a, b, t, s, d, e, f, m, n, g, x, y;
    string s1, s2, in1, in2;
    cin >> n >> s1;
    c = 0;
    while (1)
    {
        f = 0;

        s2 = "";
        for (int i = 0; i < s1.size(); i++)
        {
            if (i + 1 < s1.size())
            {
                in1 = s1.substr(i, 2);
                if (dp.find(in1) != dp.end())
                {
                    s2.push_back(dp[in1]);
                    i++;
                    f = 1;
                }
                else
                {
                    s2.push_back(s1[i]);
                }
            }
            else
            {
                s2.push_back(s1[i]);
            }
        }
        s1 = s2;

        if (f == 0)
        {
            break;
        }
        //s1 = s2;
        // c++;
    }
    cout << s1;
    return;
}
int main()
{
    ll t = 1, n, k;
    cin >> t;
    dp["01"] = '2';
    dp["12"] = '3';
    dp["23"] = '4';
    dp["34"] = '5';
    dp["45"] = '6';
    dp["56"] = '7';
    dp["67"] = '8';
    dp["78"] = '9';
    dp["89"] = '0';
    dp["90"] = '1';
    for (auto xx : dp)
    {
        dp1.push_back({xx.first, xx.second});
        // cout << xx.first << " " << xx.second << "\n";
    }
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}