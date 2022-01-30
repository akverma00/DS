/*
Given a catalog of products, design a search system that generates search suggestions based on user search prefix.
The results should be alphabetically sorted as well. The number of results is limited to some number (N). 
Assume that the catalog and search words are all in lower case English alphabets. 
 
For example,  
 
Catalog : 
["bag","band","ball","bell","belt","rope","rollers","mouse","mousepad","mouthorgan","mic","milk"]
mix 
 
N=3 
 
Search words : 
 
"" ( empty string) -> ["bag","ball","band"] ( Only top 3 results) 
"m" -> ["mic","milk","mouse"] 
"mi" -> ["mic","milk"] 
 
Solution : Approach is to use a trie to do prefix search and then do DFS to get the top N results.
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    bool isEnd;
    node *next[26];
};
node *root;
void insertion(string word)
{
    // cout << "1";
    node *start = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (start->next[word[i] - 'a'] == NULL)
        {
            start->next[word[i] - 'a'] = new node;
            start->next[word[i] - 'a']->isEnd = false;
        }
        start = start->next[word[i] - 'a'];
        //cout << word[i];
    }
    // cout << "\n";
    start->isEnd = true;
}

node *search(string word)
{
    node *start = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (start->next[word[i] - 'a'] == NULL)
        {
            return NULL;
        }
        //cout << word[i];
        start = start->next[word[i] - 'a'];
    }
    return start;
}
void dfs(node *root, int &N, string &st, vector<string> &ans)
{
    if (root == NULL)
        return;
    if (root->isEnd)
    {
        ans.push_back(st);
        N--;
    }
    if (N == 0)
        return;
    for (int i = 0; i < 26; i++)
    {
        if (root->next[i] == NULL)
            continue;
        st.push_back('a' + i);
        dfs(root->next[i], N, st, ans);
        st.pop_back();
    }
    return;
}

int main()
{
    root = new node;
    root->isEnd = false;
    // cout << "11";
    vector<string> arr = {"bag", "band", "ball", "bell", "belt", "rope", "rollers", "mouse", "mousepad", "mouthorgan", "mic", "milk"};
    // cout << "12";
    int N = 3;
    for (auto word : arr)
    {
        //cout << word << "\n";
        insertion(word);
    }
    // cout << (search("ball")->isEnd) << "\n";
    vector<string> queries = {"", "m", "mi"};
    for (auto word : queries)
    {
        vector<string> ans;
        int n = N;
        dfs(search(word), n, word, ans);
        for (auto w : ans)
        {
            cout << w << " ";
        }
        cout << "\n";
    }

    return 0;
}