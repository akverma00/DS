/*

A => 1234       =>4321
B =>  130       =>031
     1364

A=> 1234
B=> -190

*/

struct node
{
    int data;
    node *next;
};
node *reverse(node *A)
{
}
int addList(node *A, node *B)
{
    A = reverse(A);
    B = reverse(B);
    int car = 0, mul = 1, ans = 0, sum;
    while (A != NULL && B != NULL)
    {
        sum = A->data + B->data + car;
        //9+9=18   car=1, sum=8
        car = sum / 10;
        sum %= 10;
        ans = ans + mul * sum;

        mul *= 10;
        A = A->next;
        B = B->next;
    }
    while (A != NULL)
    {
        sum = A->data + car;
        car = sum / 10;
        sum %= 10;
        ans = ans + mul * sum;

        mul *= 10;
        A = A->next;
    }
    while (B != NULL)
    {
        sum = B->data + car;
        car = sum / 10;
        sum %= 10;
        ans = ans + mul * sum;
        mul *= 10;
        B = B->next;
    }
    if (car > 0)
    {
        ans = ans + mul * car;
    }
    return ans;
}

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {

//     return 0;
// }