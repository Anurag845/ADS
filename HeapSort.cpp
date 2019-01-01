#include<iostream>
using namespace std;

class Heap
{
    int Tree[20];
    int n;
    public:

    Heap()
    {
        for(int i=0;i<20;i++)
        {
            Tree[i]=0;
        }
        n=0;
    }

    int rethead()
    {
        return Tree[0];
    }
   
    void insert()
    {
        int item,ptr,par;
        cin>>item;
        ptr=n;
        n=n+1;
        while(ptr>0)
        {
            par=(ptr-1)/2;
            if(item<=Tree[par])
            {
                Tree[ptr]=item;
                return;
            }
            Tree[ptr]=Tree[par];
            ptr=par;
        }
        Tree[ptr]=item;
        return;
    }

    void display()
    {
        cout<<"Array is ";
        for(int i=0;i<n;i++)
        {
            cout<<Tree[i]<<" ";
        }
        cout<<endl;
    }

    void headdelete()
    {
        int last=Tree[n-1];
        n=n-1;
        int ptr=0,left=1,right=2;
        while(right<=n-1)
        {
            if(last>=Tree[left] && last>=Tree[right])
            {
                Tree[ptr]=last;
                return;
            }
            if(Tree[right]<=Tree[left])
            {
                Tree[ptr]=Tree[right];
                ptr=left;
            }
            else
            {
                Tree[ptr]=Tree[right];
                ptr=right;
            }
            left=2*ptr+1;
            right=left+1;
        }
        if(left==n-1 && last<Tree[left])
        {
            Tree[ptr]=Tree[left];
            ptr=left;
        }
        Tree[ptr]=last;
    }

    void sort()
    {
        cout<<"Maximum element is "<<Tree[0]<<endl;
        int cnt=n;
        for(int i=0;i<cnt-1;i++)
        {
            headdelete();
        }
        cout<<"Minimum element is "<<Tree[0]<<endl;
        headdelete();
    }
};


int main()
{
    Heap H;
    char c='y';
    int choice;
    while(c=='y')
    {
        cout<<"Press 1 to insert element"<<endl;
        cout<<"Press 2 to display maximum and minimum elements"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: {
            			int no;
            			cout<<"Enter number of elements:- ";
            			cin>>no;
            			cout<<"Enter items to be inserted"<<endl;
            			for(int i=0;i<no;i++)
            			{
            				H.insert();
            			}
                    	break;
                    }
            case 2: H.sort();
                    break;
        }
        cout<<"Do you want to continue?"<<endl;
        cin>>c;
    }
    return 0;
}
