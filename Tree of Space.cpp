#include <bits/stdc++.h>
using namespace std;

// Structure of a node of an n-ary tree
class Node
{
public:
    // Stores the key of the Node
    string key;
    // Stores the total count of locked descendants
    bool isLocked;
    // Stores the children of the Node
    vector<Node *> children;
    // Stores the uid of the Node
    int uid;
    // Stores the parent information of the Node
    Node *parent;

    Node(Node *parent, string key);
};

Node::Node(Node *parent, string key)
{
    this->key = key;
    this->parent = parent;
    uid = -1;
    isLocked = false;
}

class NaryTree
{
private:
    // Keeps track of all the Nodes in the tree {key, Node*}
    unordered_map<string, Node *> AllNodes;
    // Root Node of our tree
    Node *root;

public:
    NaryTree(string key);
    void addNode(string parentKey, string Key);
    bool lock(string key, int uid);
    bool unlock(string key, int uid);
    bool upgradeLock(string key, int uid);
    //subuse
    bool checkdescendent(Node *node);
    bool checkancestor(Node *node);
    void printtree(string key, int lev);
    bool check(Node *node, int uid);
    void upgrade(Node *node, int uid);
};

// // Utility function to create Root Node
NaryTree::NaryTree(string key)
{
    root = new Node(NULL, key);
    AllNodes[key] = root;
}

// // Utility function to add Nodes to the Parent
void NaryTree::addNode(string parentKey, string key)
{
    Node *curr = new Node(AllNodes[parentKey], key);
    AllNodes[key] = curr;
    AllNodes[parentKey]->children.push_back(curr);
}

bool NaryTree::checkdescendent(Node *node)
{
    bool f = true;
    if (node->isLocked)
        f = false;
    for (auto child : node->children)
    {
        f |= checkdescendent(child);
    }
    return f;
}

bool NaryTree::checkancestor(Node *node)
{
    bool f = true;
    if (!node)
        return true;
    if (node and node->isLocked)
        f = false;
    f |= (checkancestor(node->parent));
    return f;
}

bool NaryTree::lock(string key, int uid)
{
    Node *node = AllNodes[key];
    if (node->isLocked)
        return false;
    if (!checkancestor(node))
        return false;
    if (!checkdescendent(node))
        return false;
    node->isLocked = true;
    node->uid = uid;
    return true;
}

bool NaryTree::unlock(string key, int uid)
{
    Node *node = AllNodes[key];
    if (node->uid == uid)
    {
        node->isLocked = false;
        node->uid = -1;
        return true;
    }
    return false;
}

bool NaryTree::check(Node *node, int uid)
{
    bool f = true;
    if (!node)
        return true;
    if (node->isLocked && node->uid != uid)
        f = false;
    for (auto child : node->children)
    {
        f |= check(child, uid);
    }
    return f;
}
void NaryTree::upgrade(Node *node, int uid)
{
    if (!node)
        return;
    if (node->isLocked)
    {
        node->isLocked = false;
        node->uid = -1;
    }
    for (auto child : node->children)
    {
        upgrade(child, uid);
    }
    return;
}

bool NaryTree::upgradeLock(string key, int uid)
{
    Node *node = AllNodes[key];
    if (!check(node, uid))
        return false;
    upgrade(node, uid);
    node->isLocked = true;
    node->uid = uid;
    return true;
}

// void NaryTree::printtree(string key,int lev){
// 	Node* node = AllNodes[key];
// 	if(!node) return;
//     cout<<node->key<<" "<<lev<<"\n";
// 	for(auto child:node->children){
// 		printtree(child->key,lev+1);
// 	}
// 	return;
// }

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    NaryTree Tree(v[0]);
    queue<string> q1;
    q1.push(v[0]);
    int i = 1;
    while (!q1.empty())
    {
        string cur = q1.front();
        q1.pop();
        for (int j = 0; j < m; j++)
        {
            if (i < n)
            {
                Tree.addNode(cur, v[i]);
                q1.push(v[i]);
                i++;
            }
        }
    }
    // Tree.printtree(v[0],0);
    while (q--)
    {
        int op, uid;
        string key;
        cin >> op >> key >> uid;
        bool f;
        if (op == 1)
        {
            f = Tree.lock(key, uid);
        }
        if (op == 2)
        {
            f = Tree.unlock(key, uid);
        }
        if (op == 3)
        {
            f = Tree.upgradeLock(key, uid);
        }
        if (f)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// vector<vector<ll>> adj;
// map<ll, string> keys;
// unordered_map<string, ll> name;
// vector<ll> par;
// map<ll, ll> is_locked;
// vector<ll> cnt;
// ll t = 0;
// vector<ll> tin, tout;
// void dfs(ll src)
// {
//     tin[src]++;
//     for (auto xx : adj[src])
//     {
//         dfs(xx);
//     }
//     tout[src] = ++t;
// }

// void changeCount(ll x, ll val)
// {
//     ll p = par[x];
//     while (p != -1)
//     {
//         cnt[p] = val;
//         p = par[p];
//     }
// }
// bool checkDes(ll x, ll p)
// {
//     return tin[p] <= tin[x] && tout[p] >= tout[x];
// }
// bool lock(ll x, ll uid)
// {
//     if (is_locked.count(x) || cnt[x])
//     {
//         return false;
//     }
//     ll p = par[x];
//     while (p != -1)
//     {
//         if (is_locked.count(p))
//             return false;
//         p = par[p];
//     }
//     changeCount(x, 1);
//     is_locked[x] = uid;
//     return true;
// }
// bool unlock(ll x, ll uid)
// {
//     (is_locked.count(x) == 0 || is_locked[x] != uid) { return false; }
//     changeCount(x, -1);
//     is_locked.erase(x);
//     return true;
// }
// bool checkUpgrade(ll x, ll uid)
// {
// I1 return true
// if(cnt]-*)
// return false;
// 4(is locked.count(x) 10) return is locked[x] - uid
//                                                    baol isgokefalsez
// }