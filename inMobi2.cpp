/*
Design an algorithm to find all pairs of integers within an array which sum to a specified value. 
Eg:  
Array arr= { -2,-1,0,3,5,6,7,9,13,14} 
Sum = 12 
Pairs = {-2, 14} { -1, 13} {3, 9} {5, 7} 


-2,-1,0,3,5,6,7,9,13,14
s=12

arr[i]+y=s
y=s-arr[i]

*/

#include <bits/stdc++.h>
using namespace std;

set<vector<int>> getPairs(vector<int> arr, int sum)
{
    // map<int,int> mp;
    set<vector<int>> ans;
    set<int> se;
    for (int i = 0; i < arr.size(); i++)
    {
        if (se.find(sum - arr[i]) != se.end())
        {
            ans.insert({min(arr[i], sum - arr[i], max(arr[i], sum - arr[i]))});
        }
        se.insert(arr[i]);
    }
    return ans;
}

int main()
{
    int sum, n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> sum;
    set<vector<int>> ans = getPairs(arr, sum);
    for (auto par : ans)
    {
        cout << "{" << par[0] << "," << par[1] << "}";
    }
    return 0;
}