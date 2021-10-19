#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

vector<int> getTimeStamps(vector<int> time, vector<int> dir)
{
    int n = time.size();
    time.push_back(1E9 + 1E6);
    vector<int> out(n);
    queue<int> q[2]; // enter(0), exit(1)
    for (int i = 0, t = time[0], fl = -1; i < n; i++)
    {
        q[dir[i]].push(i);
        while (t < time[i + 1])
        {
            if (not q[0].empty() and not fl)
            {
                out[q[0].front()] = t++;
                q[0].pop();
                fl = 0;
            }
            else if (not q[1].empty())
            {
                out[q[1].front()] = t++;
                q[1].pop();
                fl = 1;
            }
            else if (not q[0].empty())
            {
                out[q[0].front()] = t++;
                q[0].pop();
                fl = 0;
            }
            else
            {
                t = time[i + 1];
                fl = -1;
            }
        }
    }
    return out;
}

void solve()
{
    ll h, c, q, a, b, t, s, d, e, f, g, x, y;
    string in1, in2;
    getline(cin, in1);
    getline(cin, in2);
    vector<int> time, dir;
    stringstream ss(in1);
    while (ss >> a)
        time.push_back(a);
    stringstream ss2(in2);
    while (ss2 >> a)
        dir.push_back(a);

    vector<int> ans = getTimeStamps(time, dir);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
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