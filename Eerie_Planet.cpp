
#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

void solve()
{
    ll h, c, q, a, b, t, s, d, e, f, g, x, y;
    cin >> h >> c >> q;
    vector<vll> cc; // cc => vector {-1,-1,-1,-1}, {t,type,h,index}    type={0,1,2}={s,e,q}
    vll qq(q, 1);
    vll isCrewValid(c, 1);
    ll mx = INT_MIN;
    for (int i = 0; i < c; i++)
    {
        cin >> a >> b >> d;
        cc.push_back({b, 0, a, i});
        cc.push_back({d + 1, 1, a, i});
    }
    for (int i = 0; i < q; i++)
    {
        cin >> h >> t;
        cc.push_back({t, 2, h, i});
    }
    sort(cc.begin(), cc.end());
    priority_queue<pair<ll, ll>> pq; // stores current crew {hh,ind}
    for (auto &v1 : cc)
    {
        t = v1[0];
        ll type = v1[1];
        h = v1[2];
        ll ind = v1[3];

        if (type != 2)
        {
            if (type == 0)
            {
                pq.push({h, ind});
            }
            else if (type == 1)
            {
                isCrewValid[ind] = 0;
            }
        }
        else
        {
            while (!pq.empty() && isCrewValid[pq.top().second] == 0)
            {
                pq.pop();
            }
            if (!pq.empty())
                qq[ind] = ((pq.top().first < h) ? 1 : 0);
        }
    }
    for (int i = 0; i < q; i++)
    {
        if (qq[i])
            cout << "YES\n";
        else
            cout << "NO\n";
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