#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vll vector<ll>

ll dijastra(ll n, ll s, ll d, vector<vector<pair<ll, ll>>> &egg, ll cap, vll &prices)
{
    priority_queue<vll, vector<vll>, greater<vll>> pq; //distance ,u -> node,c->capacity
    vector<vll> dis(n, vll(cap + 1, INT_MAX));

    dis[s][0] = 0; // at source s with initial fuel =c=0
    vector<vll> vis(n, vll(cap + 1, 0));
    pq.push({0, s, 0});
    while (!pq.empty())
    {
        auto &uuu = pq.top();
        ll c_till_u = uuu[0];
        ll u = uuu[1];
        ll cap_now = uuu[2];
        pq.pop();
        if (u == d)
        {
            return dis[u][0];
        }
        if (vis[u][cap_now])
            continue;
        vis[u][cap_now] = 1;
        for (auto &vvv : egg[u])
        {
            ll v = vvv.first;
            ll c = vvv.second;
            // if we have fuel(cap_now) to reach v
            if (cap_now - c >= 0)
            {
                if (dis[v][cap_now - c] > dis[u][cap_now])
                {
                    dis[v][cap_now - c] = dis[u][cap_now];
                    pq.push({dis[v][cap_now - c], v, cap_now - c});
                }
            }
            if (cap_now + 1 <= cap)
            {
                if (dis[u][cap_now + 1] > dis[u][cap_now])
                {
                    dis[u][cap_now + 1] = dis[u][cap_now] + prices[u];
                    pq.push({dis[u][cap_now + 1], u, cap_now + 1});
                }
            }
        }
    }
    return -1;
}
void solve()
{
    ll n, m, src, q, k, a, b, dest, c;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> egg(n);
    vll prices(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        egg[a].push_back({b, c});
        egg[b].push_back({a, c});
    }
    cin >> q;
    while (q--)
    {
        cin >> c >> a >> b;
        ll ans = dijastra(n, a, b, egg, c, prices);
        if (ans == -1)
        {
            cout << "impossible";
        }
        else
        {
            cout << ans;
        }
        cout << "\n";
    }
}
int main()
{
    ll t = 1, n, k;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve();
        // cout << "\n";
    }
    return 0;
}