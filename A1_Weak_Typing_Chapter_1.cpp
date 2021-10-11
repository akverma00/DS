#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

ll solve(string s1)
{
    ll n, m, a, l, r, b, x, y  , k, c = mod, m1, m2, rr, cc;
    c = 0;
    string s2 = "";
    for (auto x : s1)
        if (x != 'F')
            s2.push_back(x);
    for (int i = 1; i < s2.size(); i++)
    {
        if (s2[i] != s2[i - 1])
            c++;
    }
    return c;
}
int main()
{
    ifstream infile("weak_typing_chapter_1_input.txt");
    ofstream outfile("weak_typing_chapter_1_output.txt");
    ll t = 1, n;
    string s1;
    infile >> t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        infile >> n >> s1;
        ll ans = solve(s1);
        outfile << "Case #" << t0 << ": " << ans << "\n";
       // outfile << "Case #" << t0 << ": " << ans << "\n";
    }
    return 0;
}
