#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s1,s2;
    cin >> n;
    list<string> st;
    for (int i = 0; i < n; i++)
    {
        cin >> s2 >> s1;

        if (s1 == ".." && !st.empty())
        {
            st.pop_back();
        }
        else if (s1 != "..")
        {
            st.push_back(s1);
        }
    }
    if(st.size()==0)
    {
        cout<<"/"<<"\n";
        return 0;
    }
    while (!st.empty())
    {
        cout<<"/"<<st.front();
        st.pop_front();
    }

    cout << "\n";
    return 0;
}