/*
You are given an array of llegers numbers
Your task is to count the number of
distinct pairs (i, j) such that e si<i< numbers. length, numbers[i]
and numbers[j] have the same number of digits, and only one of the digits differ
between numbers [i] and numbers [j]
Examplee
For numbers = [1, 151, 241, 1, 9, 22, 351], the output should be
almost EqualNumbers (numbers) = 3.
numbers[e] = 1 differs from numbers[4] 9 on the one and only digit
in both numbers
numbers[1] 151 differs from numbers[6] = 351 on the first digit.
numbers[3] 1 differs from numbers [4] = 9 on the one and only digit
in both numbers.
Note that numbers[ej = 1 and numbers[3] = 1 do not differ from each other
at all and thus do not count as a valid pair.

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isok(ll n, ll m)
{
    string s = to_string(n), t = to_string(m);
    ll cnt = 0;
    for (ll i = 0; i < s.size(); i++)
        cnt += s[i] != t[i];
    return cnt == 1;
}
ll func(vector<ll> v)
{
    map<ll, ll> cnt;
    for (auto x : v)
    {
        cnt[x]++;
    }
    ll ans = 0;
    for (auto x : v)
    {
        string s = to_string(x);
        ll n = s.size();
        for (ll i = 0; i < n; i++)
        {
            for (ll j = s[i] - '0' + 1; j < 10; j++)
            {
                auto x = s;
                x[i] = j + '0';
                ll temp = stoull(x);
                if (cnt.count(temp))
                    ans += cnt[temp];
            }
        }
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    ll ans = func({1, 151, 241, 1, 9, 22, 351});
    cout << ans;

    return 0;
}