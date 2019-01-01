#include<iostream>
using namespace std;

class node
{
    int lflag;
    int rflag;
    node* left;
    node* right;
    int data;
    public:
    node()
    {
        lflag=0;
        rflag=0;
        left=NULL;
        right=NULL;
        data=0;
    }
    friend class TBT;
};

class TBT
{
    node* root;
    public:
    TBT()
    {
        root=new node;
        root->lflag=0;
        root->rflag=1;
        root->left=root;
        root->right=root;
        root->data=0;
    }

    void insert()
    {
        int info;
        cout<<"Enter the data"<<endl;
        cin>>info;
        node* new1=new node;
        new1->data=info;
        if(root->left==root)
        {
            new1->left=root;
            new1->right=root;
            root->lflag=1;
            root->left=new1;
        }
        else
        {
            node* ptr=root->left;
            while(1)
            {
                if(info<ptr->data)
                {
                    if(ptr->lflag==0)
                    {
                        new1->left=ptr->left;
                        new1->right=ptr;
                        ptr->left=new1;
                        ptr->lflag=1;
                        return;
                    }
                    else
                        ptr=ptr->left;
                }
                else if(info>ptr->data)
                {
                    if(ptr->rflag==0)
                    {
                        new1->left=ptr;
                        new1->right=ptr->right;
                        ptr->right=new1;
                        ptr->rflag=1;
                        return;
                    }
                    else
                        ptr=ptr->right;
                }
            }
        }
    }
       
    void inorder()
    {
        node* ptr=NULL;
        if(root->lflag==0)
            cout<<"There is no tree to display"<<endl;
        else
        {
            ptr=root->left;
            while(ptr->lflag!=0)
            {
                ptr=ptr->left;
            }
            while(ptr!=root)
            {
                cout<<ptr->data<<" ";
                ptr=inorder_successor(ptr);
            }
            cout<<endl;
        }
    }

    node* inorder_successor(node *p)
    {
        if(p->rflag==0)
            return(p->right);
        else
        {
            p=p->right;
            while(p->lflag!=0)
            {
                p=p->left;
            }
            return p;
        }
    }

    void preorder()
    {
        if(root->lflag==0)
            cout<<"There is no tree to display"<<endl;
        else
        {
            node* ptr=root->left;
            while(ptr->lflag!=0)
            {
                cout<<ptr->data<<" ";
                ptr=ptr->left;
            }
            while(ptr!=root)
            {
            	cout<<ptr->data<<" ";
            	ptr=preorder_successor(ptr);
            }
            cout<<endl;
        }
    }
    
    node* preorder_successor(node* p)
    {
    	if(p->lflag==1)
    		return p->left;
        else if(p->rflag==1)
            return p->right;
        else
        {
        	while(p->rflag==0)
        		p=p->right;
        	return p->right;
        }
    }
    
    void search(int key,node* &par,node* &loc)
    {
    	if(root==NULL)
            return;
        node *ptr=root->left;
        while(ptr!=root)
        {
            if(key==ptr->data)
            {
                loc=ptr;
                return;
            }
            else if(key<ptr->data && ptr->lflag==1)
            {
                par=ptr;
                ptr=ptr->left;
            }
            else if(key>ptr->data && ptr->rflag==1)
            {
                par=ptr;
                ptr=ptr->right;
            }
        }
        if(loc==NULL)
        	cout<<"Key not found"<<endl;
    }

    void remove()
    {
    	if(root==NULL)
    	{
    		cout<<"There is no tree created"<<endl;
    		return;
    	}
    	node *par=NULL,*loc=NULL;
    	int key;
    	cout<<"Enter key of node to be deleted"<<endl;
    	cin>>key;
    	search(key,par,loc);
    	if(loc!=NULL)
    	{
    		if((loc->lflag==0 && loc->rflag==0) || (loc->lflag==0 && loc->rflag==1) || (loc->lflag==1 && loc->rflag==0))
    		{
    			delete1(par,loc);
    		}
    		/*else
    		{
    			delete2(par,loc);
    		}*/
    	}
    }
    
    void delete1(node *&par,node *&loc)
    {
    	node *child=NULL;
    	if(loc->lflag==1)
    		child=loc->left;
    	else if(loc->rflag==1)
    		child=loc->right;
    	if(par!=NULL)
    	{
    		if(loc==par->left)
    		{
    			if(child!=NULL)
    			{
    				par->left=child;
    				if(child->rflag==0)
    					child->right=loc->right;
    			}
    			else
    			{
    				par->left=loc->left;
    				par->lflag=0;    				
    			}
    		}
    		else if(loc==par->right)
    		{
    			if(child!=NULL)
    			{
    				par->right=child; 
    				if(child->rflag==0)
    					child->right=loc->right;  				
    			}
    			else
    			{
    				par->left=loc->left;
    				par->rflag=0;
    			}			
    		}
    	}
    	else if(loc==root->left)
    	{
    		if(loc->lflag==1)
    		{
    			root->left=child;
    			if(child->rflag==0)
    				child->right=root;
    		}
    		else if(loc->lflag==1)
    		{
    			root->left=child;
    			if(child->lflag==0)
    				child->left=root;
    		}
    		else
    		{
    			root->left=root;
    			root->lflag=0;
    		}
    	}
    	loc->left=NULL;
    	loc->right=NULL;
    	delete loc;
    }
};


int main()
{
    TBT t;
    char c='y';
    int choice;
    while(c=='y')
    {
        cout<<"Press 1 to insert node in the threaded binary tree"<<endl;
        cout<<"Press 2 to display threaded binary tree using inorder traversal"<<endl;
        cout<<"Press 3 to display threaded binary tree using preorder traversal"<<endl;
        cout<<"Press 4 to delete a node from the threaded binary tree"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: t.insert();
                    break;
            case 2: t.inorder();
                    break;
            case 3: t.preorder();
            		break;
            case 4: t.remove();
            		break;
            default:cout<<"Wrong choice"<<endl;
                    break;
        }
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>c;
    }
    return 0;
}
