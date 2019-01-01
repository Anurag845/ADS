#include<iostream>
#include<stack>
using namespace std;

class node
{
    string word;
    string meaning;
    node *left;
    node *right;
    public:
    node()
    {
        word='\0';
        meaning='\0';
        left=NULL;
        right=NULL;
    }
    friend class BST;
};

class BST
{
    node *root;
    public:
    BST()
    {
        root=NULL;
    }
  
    node* retroot()
    {
        return root;
    }

    void search(string key,node* &par,node* &loc)
    {
        if(root==NULL)
            return;
        node *ptr=root;
        while(ptr!=NULL)
        {
            if(key==ptr->word)
            {
                loc=ptr;
                return;
            }
            else if(key<ptr->word)
            {
                par=ptr;
                ptr=ptr->left;
            }
            else
            {
                par=ptr;
                ptr=ptr->right;
            }
        }
        /*if(loc==NULL);
            cout<<"Key not found"<<endl;
        else;
            cout<<"Key found"<<endl;*/
    }

    void insert()
    {
        node *loc=NULL,*par=NULL;
        string key,mean;
        cout<<"Enter the new word"<<endl;
        cin>>key;
        cout<<"Enter the meaning of the word"<<endl;
        cin>>mean;
        search(key,par,loc);
        if(loc!=NULL)
        {
            cout<<"Node already exists"<<endl;
            return;
        }
        node *new1=new node;
        new1->word=key;
        new1->meaning=mean;
        if(par==NULL)
        {
            root=new1;
        }
        else if(new1->word<par->word)
        {
            par->left=new1;
        }
        else
        {
            par->right=new1;
        }
    }

    void update()
    {
        node *par=NULL,*loc=NULL;
        string key;
        cout<<"Enter the word whose meaning has to be updated"<<endl;
        cin>>key;
        search(key,par,loc);
        if(loc==NULL)
        {
            cout<<"Word not found"<<endl;
        }
        else
        {
            cout<<"Enter new meaning"<<endl;
            cin>>loc->meaning;
            cout<<"Meaning has been updated"<<endl;
        }
    }

    void remove()
    {
        node *par=NULL,*loc=NULL;
        string key;
        cout<<"Enter the word which has to be deleted"<<endl;
        cin>>key;
        search(key,par,loc);
        if(loc==NULL)
        {
            cout<<"Word not found"<<endl;
        }
        else if((loc->left!=NULL && loc->right==NULL) || (loc->left==NULL && loc->right==NULL) || (loc->left==NULL && loc->right!=NULL))
        {
            delete1(loc,par);
        }
        else if(loc->left!=NULL && loc->right!=NULL)
        {
            delete2(loc,par);
        }
    }

    void delete1(node* &loc,node* &par)
    {
        node *child=NULL;
        if(loc->left!=NULL)
        {
            child=loc->left;
        }
        else if(loc->right!=NULL)
        {
            child=loc->right;
        }
        else
            child=NULL;
        if(par!=NULL)
        {
            if(loc==par->left)
                par->left=child;
            else if(loc==par->right)
                par->right=child;
        }
        else
        {
            cout<<"Node to be deleted is root"<<endl;
            if(child==root->left)
                root->left=NULL;
            else if(child==root->right)
                root->right=NULL;
            root=child;
        }
        loc=NULL;
        delete loc;
    }

    void delete2(node* &loc,node* &par)
    {
        string key,mean;
        node *ptr1=NULL,*ptr2=NULL;
        ptr1=loc;
        ptr2=loc->right;
        while(ptr2->left!=NULL)
        {
            ptr1=ptr2;
            ptr2=ptr2->left;
        }
        key=ptr2->word;
        mean=ptr2->meaning;
        delete1(ptr2,ptr1);
        swap(loc->word,key);
        swap(loc->meaning,mean);
    }
  
    void inorder(node *cnode)
    {
        if(cnode)
        {
            inorder(cnode->left);
            cout<<cnode->word<<" ";
            cout<<cnode->meaning<<endl;
            inorder(cnode->right);
        }
    }

    void rev_inorder()
    {
        stack<node*>stk;
        node *temp=NULL;
        reverse(root,stk);
        while(!stk.empty())
        {
            temp=stk.top();
            cout<<temp->word<<" ";
            cout<<temp->meaning<<endl;
            stk.pop();
        }
    }

    void reverse(node *cnode,stack<node*> &stk)
    {
        if(cnode)
        {
            reverse(cnode->left,stk);
            stk.push(cnode);
            reverse(cnode->right,stk);
        }
    }

    void mirror(node *cnode)
    {
        if(cnode)
        {
            swap(cnode->left,cnode->right);
            mirror(cnode->left);
            mirror(cnode->right);
        }
    }
};

int main()
{
    BST bst;
    int choice;
    char ch='y';
    string key;
    while(ch=='y')
    {
        cout<<"Enter 1 to insert a node in the binary search tree"<<endl;
        cout<<"Enter 2 to search an element in the binary search tree"<<endl;
        cout<<"Enter 3 to display the tree in ascending order"<<endl;
        cout<<"Enter 4 to display the tree in descending order"<<endl;
        cout<<"Enter 5 to update meaning"<<endl;
        cout<<"Enter 6 to delete a node"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: bst.insert();
                    break;
            case 2: {
                        node *par=NULL,*loc=NULL;
                        cout<<"Enter element"<<endl;
                        cin>>key;
                        bst.search(key,par,loc);
                        break;
                    }
            case 3: bst.inorder(bst.retroot());
                    break;
            case 4: bst.rev_inorder();
                    break;
            case 5: bst.update();
                    break;
            case 6: bst.remove();
                    break;
        }
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>ch;
    }
    return 0;
}
