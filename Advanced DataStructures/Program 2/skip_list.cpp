#include <bits/stdc++.h>

#define max_level 3

using namespace std;

class Node{
    public:
    int data;
    
    Node **forward;

    Node(int data,int l){

        this->data = data;
        forward = new Node*[l+1];

        memset(forward,0,sizeof(Node*)*(l+1));
    }
};

class SkipList{
    public:
    int level;

    Node* head;

    SkipList()
    {
        level = 0;
        //this constructor is basically to iniatilse the header node with forward array of size max_level
        head = new Node(-1,max_level);
    }

    void insert(int value);
    int randomLevel();
    void print();
    void del(int value);
    int search(int ele);
};

int SkipList::randomLevel() 
{ 
    int r = 1 + rand()%max_level;
    return r;
}
void SkipList::insert(int key) 
{ 
    Node *current = head; 
  
    // create update array and initialize it 
    Node *update[max_level+1]; 
    memset(update, 0, sizeof(Node*)*(max_level+1)); 
  
    for (int i = level; i >= 0; i--) 
    { 
        while (current->forward[i] != NULL && 
              current->forward[i]->data < key) 
            current = current->forward[i]; 
        update[i] = current; 
    } 
  
    current = current->forward[0]; 
  
    if (current == NULL || current->data != key) 
    {  
        int rlevel = randomLevel(); 
  
        if (rlevel > level) 
        { 
            for (int i=level+1;i<rlevel+1;i++) 
                update[i] = head; 
  
            // Update the list current level 
            level = rlevel; 
        } 
  
        // create new node with random level generated 
        Node* n = new Node(key, rlevel); 

        for (int i=0;i<=rlevel;i++) 
        { 
            n->forward[i] = update[i]->forward[i]; 
            update[i]->forward[i] = n; 
        } 
        cout << "Successfully Inserted key " << key << "\n"; 
    } 
};

int SkipList::search(int ele)
{
    for(int i=level;i>=0;i--)
    {
        Node* curr = head->forward[i];

        while(curr!=NULL)
        {
            if(ele==curr->data) return 1;

            curr = curr->forward[i];
        }
    }

    return 0;
}

void SkipList::del(int ele)
{
    Node* curr = head;
    if(search(ele)) //if element is found deletionn can be done
    {
        Node* update[max_level+1];

        for(int i=level;i>=0;i--)
        {
            while(curr->forward[i]!=NULL&&curr->forward[i]->data!=ele) curr = curr->forward[i];

            update[i] = curr;
        }
        curr = curr->forward[0];//now curr is pointing to the element to be deleted

        for(int i=0;i<=level;i++)
        {
            if(update[i]->forward[i]==curr)
            {
                update[i]->forward[i] = curr->forward[i];
            }

            else break;
        }

        free(curr);

        cout<<"deletion done for element "<<ele<<endl;

        Node* ptr = head;

        int lvl=level;

        for(int i=level;i>=0;i--)
        {
            if(ptr->forward[i]==NULL) lvl--;

            else break;
        }

        level = lvl;
    }
    else cout<<"Deletion not possible!"<<endl;
}

void SkipList::print()
{
    cout<<"printing..."<<endl;
    for(int i=0;i<=level;i++)
    {
        Node* ptr = head->forward[i];
        cout<<"LEVEL "<<i<<"   ";
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->forward[i];
        }
        cout<<endl;
    }
}





int main()
{
    SkipList lst; 
  
    lst.insert(3); 
    lst.insert(6); 
    lst.insert(7); 
    lst.insert(9); 
    lst.insert(12); 
    lst.insert(19); 
    lst.insert(17); 
    lst.insert(26); 
    lst.insert(21); 
    lst.insert(25);

    if(lst.search(24)) cout<<"Found element"<<endl;
    else cout<<"Not Found!"<<endl;

    lst.del(6);
    lst.del(3);
    lst.del(12);
    lst.del(25);

    lst.print();
    return 0;
}