#define ll long long int
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
///in this some code are changed by prince .
/// only for trial 
ll solve(string s1)
{
    ll n, m, a, l, r, b, x, y, k, c = mod, m1, m2, rr, cc;
    c = 0;
    ll o_prev_pos = -1;
    ll x_prev_pos = -1;
    char prev = '*';
    ll ans = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == 'F')
        {
        }
        else if (s1[i] == 'O')
        {
            if (prev != 'O')
                c += x_prev_pos + 1;
            prev = 'O';
            o_prev_pos = i;
        }
        else if (s1[i] == 'X')
        {
            if (prev != 'X')
                c += o_prev_pos + 1;
            prev = 'X';
            x_prev_pos = i;
        }

        ans += c;
        ans %= mod;
    }
    return ans;
}
// #define infile cin
// #define outfile cout
int main()
{
    ifstream infile("weak_typing_chapter_2_input.txt");
    ofstream outfile("weak_typing_chapter_2_output.txt");
    ll t = 1, n;
    string s1;
    infile >> t;
    for (int t0 = 1; t0 <= t; t0++)
    {
        infile >> n >> s1;
        ll ans = solve(s1);
        outfile << "Case #" << t0 << ": " << ans << "\n";
    }
    return 0;
}
