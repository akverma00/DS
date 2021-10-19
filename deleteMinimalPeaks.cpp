#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // cout << n << " ";
    // for (auto it : a)
    // {
    //     cout << it << " ";
    // }
    cout << endl;
    vector<int> ans;
    while (1)
    {
        if (a.size() == 0)
            break;
        int temp = -1;
        n = a.size();
        //cout << n << " endl";
        for (int i = 0; i < n; i++)
        {
            bool aa = 0, b = 0;
            if (i == 0)
                aa = 1;
            if (i == n - 1)
                b = 1;
            if (i > 0 && a[i] > a[i - 1])
                aa = 1;
            if (i < n - 1 && a[i] > a[i + 1])
                b = 1;
            if (aa && b)
            {
                if (temp != -1)
                {
                    if (a[temp] > a[i])
                    {
                        temp = i;
                    }
                }
                else
                {
                    temp = i;
                }
            }
        }
        vector<int> curr;
        for (int i = 0; i < temp; i++)
        {
            curr.push_back(a[i]);
        }
        for (int i = temp + 1; i < n; i++)
        {
            curr.push_back(a[i]);
        }
        ans.push_back(a[temp]);
        a = curr;
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
int main()
{
    ll t = 1, n, k;
    //cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}