#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class node
{
    int data;
    node *left,*right;
    public:
    node()
    {
        data=0;
        left=NULL;
        right=NULL;
    }
    friend class tree;
};

/*class snode
{
    node *ptr;
    int flag;
    public:
    snode()
    {
        ptr=NULL;
        flag=0;
    }
    friend class tree;
    friend class node;
};*/

class tree
{
    node *root;
    int leafnodes,totnodes,intnodes,height;
    public:
    tree()
    {
        root=NULL;
        leafnodes=0;
        totnodes=0;
        intnodes=-1;
        height=0;
    }
  
    void insert()
    {
        int info,c;
        node *p=NULL,*temp=NULL;
        cout<<"Enter data ";
        cin>>info;
        if(root==NULL)
        {
            root=new node;
            root->data=info;
        }
        else
        {
            p=new node;
            p->data=info;
            temp=root;
            while(1)
            {
                cout<<"Press 1 to insert left child"<<endl;
                cout<<"Press 2 to insert right child"<<endl;
                cin>>c;
                switch(c)
                {
                    case 1: if(temp->left==NULL)
                            {
                                temp->left=p;
                                cout<<"Left child inserted"<<endl;
                                return;
                            }
                            else
                            {
                                temp=temp->left;
                                cout<<"Left position is already occupied. Pointer now at this position."<<endl;
                            }
                            break;
                    case 2: if(temp->right==NULL)
                            {
                                temp->right=p;
                                cout<<"Right child inserted"<<endl;
                                return;
                            }
                            else
                            {
                                temp=temp->right;
                                cout<<"Right position is already occupied. Pointer now at this position."<<endl;
                            }
                            break;
                    default:cout<<"Wrong option"<<endl;
                }
            }
        }
    }
  
    node* retroot()
    {
        return root;
    }
  
    int retleafnodes()
    {
        return leafnodes;
    }
  
    int rettotnodes()
    {
        return totnodes;
    }

    int retintnodes()
    {
        return intnodes;
    }

    int retheight()
    {
        return height;
    }
  
    void re_inorder(node *cnode)
    {
        if(cnode)
        {
            re_inorder(cnode->left);
            cout<<cnode->data<<" ";
            re_inorder(cnode->right);
        }
    }
  
    void re_preorder(node *cnode)
    {
        if(cnode)
        {
            cout<<cnode->data<<" ";
            re_preorder(cnode->left);
            re_preorder(cnode->right);
        }
    }
  
    void re_postorder(node *cnode)
    {
        if(cnode)
        {
            re_postorder(cnode->left);
            re_postorder(cnode->right);
            cout<<cnode->data<<" ";
        }
    }
  
    void nre_inorder()
    {
        stack<node*>stk;
        node *temp=NULL;
        stk.push(temp);
        temp=root;
        do
        {
            while(temp!=NULL)
            {
                stk.push(temp);
                temp=temp->left;
            }
            temp=stk.top();
            stk.pop();
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                if(temp->right!=NULL)
                {
                    temp=temp->right;
                    break;
                }
                else
                {
                    temp=stk.top();
                    stk.pop();
                }
            }
        }while(!stk.empty());
    }
  
    void nre_preorder()
    {
        stack<node*>stk;
        node *temp=NULL;
        stk.push(temp);
        temp=root;
        do
        {
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                stk.push(temp);
                temp=temp->left;
            }
            temp=stk.top();
            stk.pop();
            while(temp!=NULL)
            {
                if(temp->right!=NULL)
                {
                    temp=temp->right;
                    break;
                }
                else
                {
                    temp=stk.top();
                    stk.pop();
                }
            }
        }while(!stk.empty());
    }
  
    /*void nre_postorder()
    {
        stack<snode>stk;
        snode s,s1;
        stk.push(s);
        s.ptr=root;
        do
        {
            while(s.ptr!=NULL)
            {
                s.flag=0;
                stk.push(s);
                if(s.ptr->right!=NULL)
                {
                    s1.ptr=s.ptr->right;
                    s1.flag=1;
                    stk.push(s1);
                }
                s.ptr=s.ptr->left;
            }
            s=stk.top();
            stk.pop();
            while(s.flag==0)
            {
                cout<<s.ptr->data<<" ";
                s=stk.top();
                stk.pop();
            }
            if(s.flag==0)
                break;
        }while(!stk.empty());
    }*/
  
    void nre_postorder()
    {
        stack<node*>stk1;
        stack<node*>stk2;
        node *p=NULL;
        node *c=NULL;
        stk1.push(p);
        p=root;
        stk1.push(p);
        while(p!=NULL)
        {
            stk2.push(stk1.top());
            stk1.pop();
            if(p->left!=NULL)
                stk1.push(p->left);
            if(p->right!=NULL)
                stk1.push(p->right);
            p=stk1.top();
        }
        while(!stk2.empty())
        {
            c=stk2.top();
            cout<<c->data<<" ";
            stk2.pop();
        }
    }
  
    void leaves(node *cnode)
    {
        if(cnode==root)
            leafnodes=0;
        if(cnode)
        {
            leaves(cnode->left);
            if(cnode->left==NULL && cnode->right==NULL)
                leafnodes++;
            leaves(cnode->right);
        }
    }
  
    void totalnodes(node *cnode)
    {
        if(cnode==root)
            totnodes=0;
        if(cnode)
        {
            totalnodes(cnode->left);
            totnodes++;
            totalnodes(cnode->right);
        }
    }
   
    void internodes(node *cnode)
    {
        if(cnode==root)
            intnodes=-1;
        if(cnode)
        {
            internodes(cnode->left);
            if(cnode->left!=NULL && cnode->right!=NULL)
                intnodes++;
            internodes(cnode->right);
        }
    }

    void treeheight()
    {
        if(root==NULL)
        {
            cout<<"There is no tree"<<endl;
            return;
        }
        queue<node*>q;
        node *temp=NULL,*tnull=NULL;
        temp=root;
        q.push(temp);
        q.push(tnull);
        while(q.size()!=1 && q.front()!=NULL)
        {
        	while(q.front()!=NULL)
        	{
        		temp=q.front();
        		q.pop();
        		if(temp->left!=NULL)
        			q.push(temp->left);
        		if(temp->right!=NULL)
        			q.push(temp->right);
        	}
        	q.pop();
        	height++;
        	q.push(tnull);
        }
    }

    node* copy(node *onode,node *cnode)
    {
        if(onode)
        {
            cnode=new node;
            cnode->data=onode->data;
            cnode->left=copy(onode->left,cnode->left);
            cnode->right=copy(onode->right,cnode->right);
            return cnode;
        }
        return cnode;
    }
   
    void copytree(node *onode,node *cnode)
    {
        root=copy(onode,cnode);
    }

    void remove(node *cnode)
    {
        if(cnode)
        {
            remove(cnode->left);
            cnode->left=NULL;
            cnode->right=NULL;
            delete cnode;
            remove(cnode->right);
        }
        if(cnode==root)
        {
            root=NULL;
            delete root;
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
    char ch='y';
    int choice;
    tree t,tc;
    while(ch=='y')
    {
        cout<<"Press 1 to insert a node"<<endl;
        cout<<"Press 2 to display the tree using recursive inorder traversal"<<endl;
        cout<<"Press 3 to display the tree using recursive preorder traversal"<<endl;
        cout<<"Press 4 to display the tree using recursive postorder traversal"<<endl;
        cout<<"Press 5 to display the tree using non-recursive inorder traversal"<<endl;      
        cout<<"Press 6 to display the tree using non-recursive preorder traversal"<<endl;
        cout<<"Press 7 to display the tree using non-recursive postorder traversal"<<endl;
        cout<<"Press 8 to display the number of leaf nodes in the tree"<<endl;
        cout<<"Press 9 to display the total number of nodes in the tree"<<endl;
        cout<<"Press 10 to display the number of intermediate nodes in the tree"<<endl;
        cout<<"Press 11 to display the height of the tree"<<endl;
        cout<<"Press 12 to copy a tree"<<endl;
        cout<<"Press 13 to mirror a tree"<<endl;
        cout<<"Press 14 to delete a tree"<<endl;
        cin>>choice;
        switch(choice)
        {  
            case 1: t.insert();
                    break;
            case 2: t.re_inorder(t.retroot());
                    cout<<endl;
                    break;
            case 3: t.re_preorder(t.retroot());
                    cout<<endl;
                    break;
            case 4: t.re_postorder(t.retroot());
                    cout<<endl;
                    break;
            case 5: t.nre_inorder();
                    cout<<endl;
                    break;
            case 6: t.nre_preorder();
                    cout<<endl;
                    break;
            case 7: t.nre_postorder();
                    cout<<endl;
                    break;
            case 8: t.leaves(t.retroot());
                    cout<<"Number of leaf nodes is "<<t.retleafnodes()<<endl;
                    break;
            case 9: t.totalnodes(t.retroot());
                    cout<<"Total number of nodes is "<<t.rettotnodes()<<endl;
                    break;
            case 10:t.internodes(t.retroot());
                    cout<<"Total number of intermediate nodes is "<<t.retintnodes()<<endl;
                    break;
            case 11:t.treeheight();
                    cout<<"Height of tree is "<<t.retheight()<<endl;
                    break;
            case 12:tc.copytree(t.retroot(),tc.retroot());
                    tc.re_inorder(tc.retroot());
                    break;
            case 13:t.mirror(t.retroot());
                    t.re_inorder(t.retroot());
                    break;
            case 14:t.remove(t.retroot());
                    break;
            default:cout<<"Incorrect option"<<endl;
                    break;
        }
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>ch;
    }
    return 0;
}

