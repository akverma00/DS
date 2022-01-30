#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, map<pair<int, int>, int> &graph, vector<int> &path, int pos)
{
    if (!graph.count({path[pos - 1], v}))
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamCycleUtil(map<pair<int, int>, int> &graph, vector<int> &path, int pos, int n)
{
    if (pos == n)
    {
        if (graph.count({path[pos - 1], path[0]}))
            return true;
        else
            return false;
    }
    for (int v = 1; v < n; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1, n))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
void testcase()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> g;
    vector<int> st[10], en[10];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int x = (s[0] - 'A');
        int cnt = 0;
        while (x)
        {
            if (x & 1)
                cnt++;
            x /= 2;
        }
        for (int x1 : en[cnt])
        {
            g[{x1, i}]++;
        }
        x = (s.back() - 'A');
        int cnt1 = 0;
        while (x)
        {
            if (x & 1)
                cnt1++;
            x /= 2;
        }
        for (int x1 : st[cnt1])
        {
            g[{i, x1}]++;
        }
        st[cnt].push_back(i);
        en[cnt1].push_back(i);
    }
    vector<int> path(n, -1);
    path[0] = 0;
    if (hamCycleUtil(g, path, 1, n))
    {
        cout << "POSSIBLE\n";
    }
    else
        cout << "IMPOSSIBLE\n";
    return;
}

int32_t main()
{
    int test = 1;
    cin >> test;
    int t = 0;
    while (test--)
    {
        testcase();
    }
    return 0;
}