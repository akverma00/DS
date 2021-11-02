#define ll int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

ll fun(string dat1, string dat2)
{
    if (dat1 == dat2)
        return 0;

    ll yy1 = stoi(dat1.substr(4, 4));
    ll yy2 = stoi(dat2.substr(4, 4));
    if (yy1 < yy2)
    {
        return -1;
    }
    else if (yy1 == yy2)
    {
        ll mm1 = stoi(dat1.substr(2, 2));
        ll mm2 = stoi(dat2.substr(2, 2));
        if (mm1 < mm2)
        {
            return -1;
        }
        else if (mm1 == mm2)
        {
            ll dd1 = stoi(dat1.substr(0, 2));
            ll dd2 = stoi(dat2.substr(0, 2));
            if (dd1 < dd2)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
    return 0;
}
void solve()
{
    ll h, c, q, a, k, b, t, s, d, e, f, m, n, g, x, y;
    string s1, in1, in2, ans;
    cin >> s1;
    ans = "00000000";
    ll found = 0;

    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            string d1 = (i < 10) ? "0" + to_string(i) : to_string(i);
            string m1 = (j < 10) ? "0" + to_string(j) : to_string(j);
            string y1 = d1 + m1, y2 = y1;
            reverse(y2.begin(), y2.end());
            a = fun(y1 + y2, s1);
            if (a >= 0)
                continue;
            if (found == 0)
            {
                ans = y1 + y2;
                found = 1;
            }
            else
            {
                b = fun(y1 + y2, ans);
                if (b > 0)
                    ans = y1 + y2;
            }
        }
    }
    if (found == 0)
        ans = "-1";
    cout << ans;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1, a, b, n, k;
    cin >> t;
    string s1, d1, m1, y1, y2, in2, ans;
    for (int i = 0; i < t; i++)
    {
        cin >> s1;
        ans = "00000000";
        ll found = 0;

        for (int i = 1; i <= 30; i++)
        {
            for (int j = 1; j <= 12; j++)
            {
                d1 = (i < 10) ? "0" + to_string(i) : to_string(i);
                m1 = (j < 10) ? "0" + to_string(j) : to_string(j);
                y1 = d1 + m1, y2 = y1;
                reverse(y2.begin(), y2.end());
                a = fun(y1 + y2, s1);
                if (a >= 0)
                    continue;
                if (found == 0)
                {
                    ans = y1 + y2;
                    found = 1;
                }
                else
                {
                    b = fun(y1 + y2, ans);
                    if (b > 0)
                        ans = y1 + y2;
                }
            }
        }
        if (found == 0)
            ans = "-1";
        cout << ans;
        cout << "\n";
    }
    return 0;
}