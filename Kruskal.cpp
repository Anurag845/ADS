/*#include<iostream>
using namespace std;

class office
{
    int o1,o2,amt;
    public:
    office()
    {
        o1=-1;
        o2=-1;
        amt=-1;
    }
    friend class graph;
};

class graph
{
    int adjmat[10][10];
    int v,e;
    office *o;
    public:
    graph()
    {
        int v1,v2,cost;
        cout<<"Enter number of vertices"<<endl;
        cin>>v;
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                adjmat[i][j]=0;
            }
        }
        cout<<"Enter number of edges"<<endl;
        cin>>e;
        o=new office[e];
        for(int i=0;i<e;i++)
        {
            cout<<"Vertex 1 :- ";
            cin>>v1;
            cout<<"Vertex 2 :- ";
            cin>>v2;
            cout<<"Cost :- ";
            cin>>cost;
            adjmat[v1][v2]=cost;
            adjmat[v2][v1]=cost;
            o[i].o1=v1;
            o[i].o2=v2;
            o[i].amt=cost;
        }
    }

    void sort()
    {
        for(int i=0;i<e;i++)
        {
            for(int j=0;j<e;j++)
            {
                if(o[i].amt
            }
        }
    }

    void display()
    {
        for(int i=0;i<v;i++)
        {
            if(i==0)
            {
                cout<<"  ";
                for(int k=0;k<v;k++)
                    cout<<k<<" ";
                cout<<endl;
            }
            for(int j=0;j<v;j++)
            {
                if(j==0)
                {
                    cout<<i<<" ";
                }
                cout<<adjmat[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<e;i++)
        {
            cout<<o[i].o1<<" "<<o[i].o2<<" "<<o[i].amt<<endl;
        }
    }
};


int main()
{
    graph g;
    char c='y';
    int choice;
    while(c=='y')
    {
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>c;
    }
    g.display();
    return 0;
}*/



/*#include<iostream>
using namespace std;
struct node
{
    int weight,source,dest;
};
class graph
{
    int e,v;
    node m[10];
public:
    graph()
    {
        cout<<"Enter number of vertices and edges ";
        cin>>v>>e;
    }
    void makegraph();
    void kruskals();
};
void graph::makegraph()
{
    //int c,d,s;
    cout<<"Enter the edges in ascending order\n";
    for(int i=0;i<e;i++)
    {
    	cout<<"Enter the source,destination and the weight of edge ";
    	cin>>m[i].source>>m[i].dest>>m[i].weight;
    //m.insert(make_pair(c,make_pair(s,d)));
    }
}
void graph::kruskals()
{
    int near[v];
    for(int i=0;i<v;i++)
        near[i]=i;
    int min_cost=0;
    int mst[v-1][2];
    int k,l;
    //map<int,pair<int,int> >:: iterator it;
    //it=m.begin();
    int i=0;
    int j=0;
    while(i!=e && j!=v-1)
    {
        k=m[i].source;
        l=m[i].dest;
        if(near[k]!=near[l])
        {
            mst[j][0]=k;
            mst[j][1]=l;
            i++;
            if(near[k]<near[l])
            {
                near[l]=near[near[k]];
            }
            else
            {
                near[k]=near[near[l]];
            }
            min_cost+=m[j].weight;
        }
        j++;
    }
    cout<<"\nMinimum cost is "<<min_cost<<endl;
    for(int i=0;i<v-1;i++)
    {
        cout<<mst[i][0]<<" "<<mst[i][1]<<endl;
    }
}

int main()
{
    graph g;
    g.makegraph();
    g.kruskals();
    return 0;
}*/


#include<iostream>
using namespace std;

class path
{
	int v1;
	int v2;
	int cost;
	
	public:
	
	path()
	{
		v1=-1;
		v2=-1;
		cost=-1;
	}
	friend class graph;
};

class graph
{
	path *p;
	int v,e;
	
	public:
	
	graph()
	{
		p=NULL;
		cout<<"Enter the number of vertices"<<endl;
		cin>>v;
		cout<<"Enter the number of edges"<<endl;
		cin>>e;
		p=new path[e];
		for(int i=0;i<e;i++)
		{
			cout<<"Enter source, destination and cost for path "<<i<<endl;
			cin>>p[i].v1;
			cin>>p[i].v2;
			cin>>p[i].cost;
		}
		sort();
	}
	
	void sort()
	{
		int i,j,min;
        for(i=0;i<e;i++)
        {
            min=i;
            for(j=i;j<e;j++)
            {
                if(p[j].cost <= p[min].cost)
                    min=j;
            }
            swap(p[i],p[min]);
        }
	}
	
	void show()
	{
		for(int i=0;i<e;i++)
		{
			cout<<p[i].v1<<" "<<p[i].v2<<" "<<p[i].cost<<endl;
		}
	}
	
	void kruskal()
	{
		int min_cost=0;
		int* near=new int[v];
		int mat[v-1][2];
		int k,l;
		for(int i=0;i<v;i++)
		{
			near[i]=i;
		}
		int i=0,j=0;
		while(i!=e && j!=v-1)
		{
			k=p[i].v1;
			l=p[i].v2;
			if(near[k]!=near[l])
			{
				mat[j][0]=k;
				mat[j][1]=l;
				i++;
				if(near[k]>near[l])
				{
					near[k]=near[near[l]];
				}
				else
				{
					near[l]=near[near[k]];
				}
				min_cost+=p[j].cost;
			}
			j++;
		}
		cout<<"Minimum cost is "<<min_cost<<endl;
		for(int i=0;i<v-1;i++)
		{
			for(int j=0;j<2;j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};

int main()
{
	graph g;
	g.kruskal();
	return 0;
}
