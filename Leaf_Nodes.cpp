#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};
Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
    {

        root = NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
        {
            myLeft = NULL;
        }
        else
        {
            myLeft = new Node(l);
        }
        if (r == -1)
        {
            myRight = NULL;
        }
        else
        {
            myRight = new Node(r);
        }

        p->left = myLeft;
        p->right = myRight;
        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
    return root;
}
void descending_order(Node *root)
{
   
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    
    vector<int>v;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        if(f->left==NULL && f->right==NULL){
            v.push_back(f->val);
            
        }
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
sort(v.begin(), v.end(), greater<int>());
  for(int i=0;i<v.size();i++){
    cout<<v[i]<< " ";
  }
}
int main()
{
    Node *root = input_tree();
    descending_order(root);
    return 0;
}
