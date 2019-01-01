#include<iostream>
using namespace std;

#define n 4

class node
{
    float w;
    int r;
    float c;
    public:
    node()
    {
        w=0;
        r=0;
        c=0;
    }
    friend class OBST;
};

class OBST
{
    float p[n];
    float q[n+1];
    node table[n+1][n+1];
    int identifier[n];

    public:
   
    OBST()
    {
        int i;
        cout<<"Enter "<<n<<" identifiers"<<endl;
        for(i=0;i<n;i++)
        {
            cin>>identifier[i];
        }
        cout<<"Enter probabilities of successful search pi"<<endl;
        for(i=0;i<n;i++)
        {
            cin>>p[i];
        }
        cout<<"Enter probabilities of unsuccessful search qi"<<endl;
        for(i=0;i<n+1;i++)
        {
            cin>>q[i];
        }
    }

    void display()
    {
        int i,j;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                cout<<table[i][j].w<<"\t"<<table[i][j].r<<"\t"<<table[i][j].c<<"\t\t";
            }
            cout<<endl;
        }
    }

    void calculate()
    {
        int i,j,k,m,var;
        float min=99;
        for(i=0;i<n;i++)
        {
            table[i][i].w=q[i];
            table[i][i+1].w=q[i]+p[i]+q[i+1];
            table[i][i+1].c=q[i]+p[i]+q[i+1];
            table[i][i+1].r=i+1;
        }
        table[n][n].w=q[n];
        for(m=2;m<=n;m++)
        {
            for(i=0;i<=n-m;i++)
            {
                min=99;
                j=i+m;
                for(k=i+1;k<=j;k++)
                {
                    if(min>(table[i][k-1].c+table[k][j].c))
                    {
                        min=table[i][k-1].c+table[k][j].c;
                        var=k;
                    }
                }
                table[i][j].w=table[i][j-1].w+p[j-1]+q[j];
                table[i][j].r=var;
                table[i][j].c=min+table[i][j].w;
            }
        }
    }

    void inorder(int i,int j)
    {
       if(i==j)
			return;
       inorder(i,table[i][j].r-1);
       cout<<identifier[table[i][j].r-1]<<" ";
       inorder(table[i][j].r,j);
    }
};


int main()
{
    int choice;
    char c='y';
    OBST O;
    O.calculate();
    O.display();
    cout<<"Tree is "<<endl;
    O.inorder(0,n);
    return 0;
}
