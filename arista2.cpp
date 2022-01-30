/*
1 2 3 4 5 6
*/
/ 10 15
    //10 15
    int prev = -1;
int getLess(node *root, int val)
{
    if (root == NULL)
        return -1;
    // if(root->data>val)

    int a = getLess(root->left, val);

    if (a != -1)
        return a;

    if (root->data == val)
        return prev;
    prev = root->data;

    int b = getLess(root->right, val);

    return b;
}