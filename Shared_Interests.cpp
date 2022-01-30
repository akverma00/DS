#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
ll solve(ll n, vector<ll> from, vector<ll> to, vector<ll> comp)
{

    vector<vector<vll>> adj(101);
    for (ll i = 0; i < 101; i++)
        adj[i].resize(n + 1);
    ll m = from.size();
    bool ispresent[101][101]{};
    for (ll i = 0; i < m; i++)
    {
        ll u = from[i], v = to[i];
        ispresent[comp[i]][u] = ispresent[comp[i]][v] = 1;
        adj[comp[i]][u].push_back(v);
        adj[comp[i]][v].push_back(u);
    }
    ll ans = -1, sz = -1;
    for (ll i = 1; i <= 100; i++)
    {
        bool vis[101]{};
        for (ll u = 1; u <= n; u++)
        {
            if (!vis[u] && ispresent[i][u])
            {
                set<ll, greater<ll>> st;
                queue<ll> q;
                q.push(u);
                vis[u] = 1;
                st.insert(u);
                while (!q.empty())
                {
                    ll x = q.front();
                    q.pop();
                    for (auto v : adj[i][x])
                        if (!vis[v])
                        {
                            vis[v] = 1;
                            q.push(v);
                            st.insert(v);
                        }
                }
                ll xxx = st.size();
                if (xxx >= sz)
                {
                    ll x = *st.begin();
                    st.erase(x);
                    if (st.size())
                        x *= (*st.begin());
                    if (xxx > sz)
                    {
                        ans = x;
                        sz = xxx;
                    }
                    else
                        ans = max(ans, x);
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<ll> v = {
        1,
        151,
        241,
        1,
        9,
    };

    ll ans = solve(12, {1, 7, 6, 10, 6, 2}, {2, 5, 5, 8, 9, 3}, {51, 21, 21, 51, 51, 51});
    cout << ans;
    return 0;
}

// // C++ program for the above approach

// #include <bits/stdc++.h>

// using namespace std;

// // Stores the first and second largest
// // element in a connected component

// ll Max, sMax;

// // Stores the count of nodes
// // in the connected components

// ll cnt = 0;

// // Function to perform DFS Traversal
// // on a given graph and find the first
// // and the second largest elements

// void dfs(ll u, ll N, vector<bool> &vis, vector<vector<ll>> &adj)
// {

//     // Update the maximum value

//     if (u > Max)
//     {
//         sMax = Max;

//         Max = u;
//     }

//     // Update the second max value

//     else if (u > sMax)
//     {

//         sMax = u;
//     }

//     // Increment size of component

//     cnt++;

//     // Mark current node visited

//     vis[u] = true;

//     // Traverse the adjacent nodes

//     for (auto to : adj[u])
//     {

//         // If to is not already visited

//         if (!vis[to])
//         {

//             dfs(to, N, vis, adj);
//         }
//     }

//     return;
// }

// // Function to find the maximum
// // product of a connected component

// ll MaximumProduct(

//     ll N, vector<pair<ll, ll>> Edge,

//     vector<ll> wt)
// {

//     // Stores the count of edges

//     ll M = wt.size();

//     // Stores all the edges mapped

//     // with a particular weight

//     unordered_map<ll, vector<pair<ll, ll>>> mp;

//     // Update the map mp

//     for (ll i = 0; i < M; i++)

//         mp[wt[i]].push_back(Edge[i]);

//     // Stores the result

//     ll res = 0;

//     // Traverse the map mp

//     for (auto i : mp)
//     {

//         // Stores the adjacency list

//         vector<vector<ll>> adj(N + 1);

//         // Stores the edges of

//         // a particular weight

//         vector<pair<ll, ll>> v = i.second;

//         // Traverse the vector v

//         for (ll j = 0; j < v.size(); j++)
//         {

//             ll U = v[j].first;

//             ll V = v[j].second;

//             // Add an edge

//             adj[U].push_back(V);

//             adj[V].push_back(U);
//         }

//         // Stores if a vertex

//         // is visited or not

//         vector<bool> vis(N + 1, 0);

//         // Stores the maximum

//         // size of a component

//         ll cntMax = 0;

//         // Iterate over the range [1, N]

//         for (ll u = 1; u <= N; u++)
//         {

//             // Assign Max, sMax, count = 0

//             Max = sMax = cnt = 0;

//             // If vertex u is not visited

//             if (!vis[u])
//             {

//                 dfs(u, N, vis, adj);

//                 // If cnt is greater

//                 // than cntMax

//                 if (cnt > cntMax)
//                 {

//                     // Update the res

//                     res = Max * sMax;

//                     cntMax = cnt;
//                 }

//                 // If already largest

//                 // connected component

//                 else if (cnt == cntMax)
//                 {

//                     // Update res

//                     res = max(res, Max * sMax);
//                 }
//             }
//         }
//     }

//     // Return res

//     return res;
// }

// // Driver Code

// ll main()
// {

//     ll N = 12;

//     vector<pair<ll, ll>> Edges = {{1, 2}, {7, 5}, {6, 5}, {10, 8}, {6, 9}, {2, 3}};

//     vector<ll> Weight = {51, 21, 21, 51, 51, 51};

//     cout << MaximumProduct(N, Edges, Weight);

//     return 0;
// }