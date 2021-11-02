#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ll finddig(map<char, ll> &mp, char ch)
// {
//     for (int i = 9; i >= 0; i--)
//     {
//     }
// }
int main()
{
    ll t, a, b, c, d, e, f, n, m;
    cin >> a >> b;
    string s1 = to_string(a);
    string s2 = to_string(b);
    if (s1.size() > s2.size())
    {
        cout << -1;
        return 0;
    }
    else if (s1.size() < s2.size())
    {
        sort(s1.rbegin(), s1.rend());
        cout << s1;
    }
    else
    {
        map<char, ll> mp;
        for (auto x : s1)
            mp[x]++;
        string ans = "";
        f = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[s2[i]] > 0)
            {
                ans.push_back(s2[i]);
                f++;
                mp[s2[i]]--;
            }
            else
                break;
        }
        char ch = 0;
        ll pos = n;
        for (int i = f; i < n; i++)
        {
            if (s1[i] < s2[f])
            {
                if (ch < s1[i])
                {
                    ch = s1[i];
                    pos = i;
                }
            }
        }
        if (ch == 0)
        {
            cout << -1;
            return 0;
        }
        swap(s1[f], s1[pos]);
        //f++;
        ans.push_back(s1[f]);
        sort(s1.begin() + f + 1, s1.begin() + n);
        reverse(s1.begin() + f + 1, s1.begin() + n);
        ans.insert(ans.end(), s1.begin() + f + 1, s1.begin() + n);
        cout << ans;
        return 0;

        // sort(s1.rbegin(), s1.rend());
        // f = 0;
        // int n = s1.size();
        // for (int i = 0; i < n; i++)
        // {
        //     char cur = s1.back();
        //     ll pos = n;
        //     for (int j = i; j < n; j++)
        //     {
        //         if (i == 0)
        //         {
        //             if (s1[pos] <= s1[j] && s1[j] <= s2[i] && s1[j] != '0')
        //             {
        //                 pos = j;
        //             }
        //         }
        //         else if (s1[pos] <= s1[j] && s1[j] <= s2[i])
        //         {
        //             pos = j;
        //         }
        //     }
        //     if (pos == n)
        //     {
        //         cout << -1;
        //         return 0;
        //     }
        //     if (s1[pos] == s1[i])
        //     {
        //         ans.push_back(s1[i]);
        //     }
        //     else
        //     {
        //         swap(s1[pos], s1[i]);
        //         ans.push_back(s1[i]);
        //         sort(s1.begin() + i + 1, s1.begin() + n);
        //         reverse(s1.begin() + i + 1, s1.begin() + n);
        //         ans.insert(ans.end(), s1.begin() + i + 1, s1.begin() + n);
        //         cout << ans;
        //         return 0;
        //     }
        //     if (f == 1)
        //         break;
        // }
        //cout << -1;
    }
    return 0;
}