/*
There are N stones lying in a line. The cost and type of the ith stone is 'ai' units and 'i' respectively. You are initially having zero stones and you wish to collect all the N types of stones, type 1, type 2,.....,type N.
You can perform the following operation multiple times (probably zero) to change the types of all the stones in one step :

The stone of the type 'i' will be changed to the type 'i +1'. If 'i' is N, then change its type to 1.(1<=i<=N).

Applying this operation single time costs x unit(s).

Your task is to print the minimum price that you have to pay to get all the N types of stones in your collection.

Input format :

• First line: Two integers N, x.

• Next line: N space-separated integers representing the price of each stone.

Output format

Print a single integer representing the minimum price to get all the N types of stones.

Input Constraints :
1 < N < 2000
0 < x <= 10^9
1 <= a[i] <= 10^9

sample input :
3 5
50 1 50

sample output :
13
*/
// https://cs.stackexchange.com/questions/128489/how-to-calculate-the-minimum-price-required-to-buy-all-the-stones

//use greedy approach to solve the problem
//1 . start with minimum cost stone type
//2. you can either apply the operation or buy it  (choose the minimum)
//time complexity O(n^2)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, mn = INT_MAX, sum, ans = INT_MAX;
    cin >> n >> x;
    int a[n + 1];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mn)
            v.push_back(i);
    }
    for (int i = 0; i < v.size(); i++)
    {
        sum = 0;
        mn = v[i];
        for (int j = 0; j < n; j++)
        {
            if (j != mn)
            {
                sum += min(a[mn] + x, a[j]);
            }
            else
            {
                sum += a[mn];
            }
        }
        ans = min(sum, ans);
    }
    cout << ans;
    return 0;
}