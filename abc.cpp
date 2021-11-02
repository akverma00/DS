/*

g++ -pthread abc.cpp

*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class lockable_tree
{
    map<ll, bool> mp;
    vector<ll> par;
    vector<ll> ccount;
    map<ll, vector<ll>> adj;
    mutex m;

public:
    void fun()
    {
        cout << "thread is here\n";
        return;
    }

    bool islock(int n)
    {
        return mp[n];
    }
    bool lockk(int n)
    {

        while (!m.try_lock())
            ;
        cout << "trying locking " << n << "\n";
        if (mp[n])
        {
            m.unlock();
            return false;
        }

        if (ccount[n] > 0)
        {
            m.unlock();

            return false;
        }
        ll p = n;
        while (p != -1)
        {
            if (mp[p])
            {
                m.unlock();
                return false;
            }
            p = par[p];
        }

        p = n;
        while (p != -1)
        {
            ccount[p]++;
            p = par[p];
        }

        mp[n] = 1;

        cout << "Locked " << n << "\n";
        m.unlock();

        return true;
    }

    bool unlockk(int n)
    {
        while (!m.try_lock())
            ;

        cout << "trying unlockking " << n << "\n";
        if (mp[n] == 0)
        {
            m.unlock();
            return false;
        }

        mp[n] = 0;
        ll p = n;
        while (p != -1)
        {
            ccount[p]--;
            p = par[p];
        }
        cout << "unlocked " << n << "\n";
        m.unlock();
        return true;
    }

    void build()
    {
        ll n;
        cin >> n;
        par.resize(n + 1, -1);
        ccount.resize(n + 1, 0);
        mp.clear();

        ll m;
        cin >> m;

        ll x, y;

        while (m--)
        {
            cin >> x >> y;
            par[y] = x;

            adj[x].push_back(y);
        }
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    lockable_tree obj;
    obj.build();
    thread t1(&lockable_tree::lockk, &obj, 4);

    thread t3(&lockable_tree::lockk, &obj, 5);

    thread t4(&lockable_tree::lockk, &obj, 4);
    t1.join();
    t3.join();
    t4.join();
    // cout<<obj.lockk(3)<<"\n";
    // cout<<obj.unlockk(3)<<"\n";
    // cout<<unlockk(4)<<"\n";
    // cout<<lockk(4)<<"\n";
    // cout<<lockk(1)<<"\n";
    // cout<<unlockk(4);

    return 0;
}