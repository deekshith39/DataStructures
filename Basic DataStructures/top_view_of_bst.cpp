#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    //Your code here
    map<int,vector<int>> m;
    queue<pair<Node*,int>> que;
    vector<int> v;
    int hd=0;
    que.push(make_pair(root,hd));
    while(!que.empty())
    {
        pair<Node*,int> temp=que.front();
        que.pop();
        Node* r=temp.first;
        hd=temp.second;
        m[hd].push_back(r->data);
        if(r->left!=NULL)
        que.push(make_pair(r->left,hd-1));
        if(r->right!=NULL)
        que.push(make_pair(r->right,hd+1));
    }
    for(auto x:m)
    {
        cout<<x.second[0]<<" ";
    }
}


