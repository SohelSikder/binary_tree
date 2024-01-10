#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int val ;
    Node * left;
    Node * right;
    Node(int val){
        this->val =  val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node * input_tree(){
    int val ;
    cin>> val;
    Node *root ;
    if(val==-1) root = NULL;
    else
        root = new Node (val);
    queue<Node *> q;
    if(root)
        q.push(root);

    while(!q.empty()){
        Node * p = q.front();
        q.pop();
        int l,r;
        cin >> l >> r;
        Node * myLeft ;
        Node * myRight;
        if(l==-1)
            myLeft = NULL;
        else
            myLeft = new Node (l);
        if(r==-1)
            myRight = NULL;
        else
            myRight = new Node (r);
        p->left = myLeft;
        p->right = myRight;
        if(p->left){
            q.push(myLeft);
        }
            
        if(p->right){
            q.push(myRight);
        }
            
    }
    return root;
}

void nodes_level (Node *root, int val){

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    bool valid = false;
    while(!q.empty()){

        pair<Node *, int> pr = q.front();
        Node * node = pr.first;
        int level = pr.second;
        q.pop();
       

        if( level == val ){
            valid = true;
            cout<< node->val << " ";
        }
        if(node->left){
            q.push({node->left, level+1});
        }
        if(node->right){
            q.push({node->right, level+1});
        }
    }
    if(valid == false)
        cout<< "Invalid" << endl;  

}

int main(){
    
    Node* root = input_tree();
    int val ;
    cin >> val;
    nodes_level(root, val); 
}