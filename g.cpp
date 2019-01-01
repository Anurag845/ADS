#include<iostream>
#include<stack>
using namespace std;

class node
{
    string city;
    node* next;
    public:
    node()
    {
        city="city";
        next=NULL;
    }
    friend class graph;
};

class graph
{
    int v;
    node adjlist[20];
    int direction; // 0=undirected 1=directed
    public:
    
    graph()
    {
        int adjno,i,j;
        node* p=NULL;
        node* c=NULL;
        direction=1;
        v=4;
        
        adjlist[0].city='a';
        adjlist[1].city='b';
        adjlist[2].city='c';
        adjlist[3].city='d';
        
        c=new node;
        c->city='b';
        adjlist[0].next=c;
        
        p=c;
        
        c=new node;
        c->city='c';
        p->next=c;
        
        p=c;
        
        c=new node;
        c->city='d';
        p->next=c;
        
        c=new node;
        c->city='a';
        adjlist[1].next=c;
        
        c=new node;
        c->city='b';
        adjlist[2].next=c;
        
        p=c;
        
        c=new node;
        c->city='a';
        p->next=c;
        
        c=new node;
        c->city='a';
        adjlist[3].next=c;
    }

    void add_vertex()
    {
        if(v==15)
            cout<<"System overflow"<<endl;
        else
        {
            string name;
            int adjno,i,j;
            node *p=NULL,*c=NULL;
            cout<<"Enter name of new city :- ";
            cin>>name;
            p=&adjlist[v];
            adjlist[v].city=name;
			cout<<"New city added"<<endl;
			cout<<"Enter number of cities adjacent to "<<adjlist[v].city<<" :- ";
            cin>>adjno;
            v++;
            cout<<"Enter "<<adjno<<" city names"<<endl;
            if(direction==1)
            {
            	for(j=0;j<adjno;j++)
            	{
                	c=new node;
                	cin>>c->city;
                	p->next=c;
                	p=c;
            	}
            }
            else if(direction==0)
            {
            	node *pr=NULL,*cu=NULL;
            	j=0;
            	for(i=0;i<adjno;i++)
            	{
                	c=new node;
                	cin>>c->city;
                	p->next=c;
                	p=c;
                	while(1)
                	{
                		pr=&adjlist[j];
                		if(adjlist[j].city==c->city)
                			break;
                		j++;
                	}
                	while(pr->next!=NULL)
                	{
                		pr=pr->next;
                	}
                	cu=new node;
                	cu->city=name;
                	pr->next=cu;
            	}
            }
        }
    }
    
    void add_edge()
    {
    	string source,destination;
    	node *p=NULL,*c=NULL;
    	int i=0;
    	cout<<"Enter name of source city"<<endl;
    	cin>>source;
    	cout<<"Enter name of destinaton city"<<endl;
    	cin>>destination;
    	while(1)
        {
        	p=&adjlist[i];
        	if(adjlist[i].city==source)
        		break;
           	i++;
        }
        while(p->next!=NULL)
        {
        	p=p->next;
        }
        c=new node;
        c->city=destination;
        p->next=c;
        if(direction==0)
        {
        	i=0;
        	while(1)
        	{
        		p=&adjlist[i];
        		if(adjlist[i].city==destination)
        			break;
           		i++;
        	}
        	while(p->next!=NULL)
        	{
        		p=p->next;
        	}	
        	c=new node;
        	c->city=source;
        	p->next=c;
        }
    }
    
    void remove_vertex(string name)
    {
    	int i,j;
    	for(i=0;i<v;i++)
    	{
    		if(adjlist[i].city==name)
    			break;
    	}
    	if(i==v)
    		cout<<"Entered city not found"<<endl;
    	else
    	{
    		node *p=NULL;
    		node *c=NULL;
    		p=&adjlist[i];
    		if(p->next!=NULL)
    		{
    			c=p->next;
    			p->next=NULL;
    			do
    			{
    				p=c;
    				c=c->next;
    				p->next=NULL;
    				delete p;
    				
    			}while(c!=NULL);
    		}
    		for(j=i;j<v;j++)
    		{
    			adjlist[j]=adjlist[j+1];
    		}
    		v--;
    		for(j=0;j<v;j++)                       //segmentation fault
            {
            	remove_edge(adjlist[j].city,name);
            }
    	}
    }
    
    void remove_edge(string source,string destination)
    {
    	int i,j;
    	for(i=0;i<v;i++)
    	{
    		if(adjlist[i].city==source)
    			break;
    	}
    	if(i==v)
    	{
    		cout<<"Source city not found"<<endl;
    	}
    	else
    	{
    		node *p=&adjlist[i];
    		node *c=p->next;
    		while(c->next!=NULL)
    		{
    			if(c->city==destination)
    				break;
    			p=c;
    			c=c->next;
    		}
    		if(c==NULL)
    		{
    			cout<<"Destination city not found"<<endl;
    		}
    		else if(c->city==destination)
    		{
    			p->next=c->next;
    			c->next=NULL;
    			delete c;
    		}
    	}
    }
    
    /*void remove_vertex(string name)
    {
        int i,j;
        for(i=0;i<v;i++)
        {
            if(adjlist[i].city==name)
                break;
        }
        if(i==v)
            cout<<"Entered city not found"<<endl;
        else
        {
            node *p=&adjlist[i],*c=NULL;
            p=p->next;
            while(p!=NULL)
            {
                c=p->next;
                p->next=NULL;
                delete p;
                p=c;
            }
            adjlist[i].next=NULL;
            for(j=i;j<v;j++)
            {
                adjlist[j]=adjlist[j+1];
            }
            v-=1;
            for(j=0;j<v;j++)                       //segmentation fault
            {
            	remove_edge(adjlist[j].city,name);
            }
        }
    }*/
    
    /*void remove_edge(string source,string destination)
    {
    	int i,j;
    	for(i=0;i<v;i++)
    	{
    		if(source==adjlist[i].city)
    		{
    			break;
    		}
    	}
    	if(i==v)
    	{
    		cout<<"Source city not found in grid"<<endl;
    	}
    	else
    	{
    		node *p=NULL,*c=&adjlist[i];
    		while(c->city!=destination && c!=NULL)
    		{
    			p=c;
    			c=c->next;
    		}
    		if(c!=NULL)
    		{
    			if(c->next==NULL)
    			{
    				p->next=NULL;
    				delete c;
    				c=NULL;
    			}
    			else
    			{
    				p->next=c->next;
    				c->next=NULL;
    				delete c;
    				c=NULL;
    			}
    		}
    	}
    }*/
    
    void in_degree()
    {
    	int i,in_deg=0;
    	string name;
    	cout<<"Enter the name of city whose number of incoming flights is to be calculated"<<endl;
    	cin>>name;
    	for(i=0;i<v;i++)
    	{
    		if(name==adjlist[i].city)
    			break;
    	}
    	if(i==v)
    	{
    		cout<<"Entered city does not exist in the grid"<<endl;
    	}
    	else
    	{
    		node *p=NULL;
    		for(i=0;i<v;i++)
    		{	
    			p=&adjlist[i];
    			p=p->next;
    			while(p!=NULL)
    			{
    				if(p->city==name)
    				{
    					in_deg++;
    					break;
    				}
    				p=p->next;
    			}
    		}
    		cout<<name<<" experiences "<<in_deg<<" incoming flights"<<endl;
    	}
    }
    
    void out_degree()
    {
    	int i,out_deg=0;
    	node *p=NULL;
    	string name;
    	cout<<"Enter the name of city whose number of outgoing flights is to be calculated"<<endl;
    	cin>>name;
    	for(i=0;i<v;i++)
    	{
    		if(name==adjlist[i].city)
    			break;
    	}
    	if(i==v)
    	{
    		cout<<"Entered city does not exist in the grid"<<endl;
    	}
    	else
    	{
    		node *p=&adjlist[i];
    		p=p->next;
    		while(p!=NULL)
    		{
    			out_deg++;
    			p=p->next;
    		}
    		cout<<name<<" experiences "<<out_deg<<" outgoing flights"<<endl;
    	}
    }
    
    /*void dfs()
    {
    	int i=0;
    	node p;
    	visited=new bool[v];
    	stack<node>stk;
    	stk.push(adjlist[i]);
    	for(int j=0;j<v;j++)
    	{
    		visited[j]=false;
    	}
    	while(!stk.empty())
    	{
    		p=stk.top();
    		stk.pop();
    		if(visited[i]==false)
    		{
    			visited[i]=true;
    			cout<<p.city<<" ";
    		}
    	}
    }*/
       
    void display()
    {
        node *p=NULL;
        for(int i=0;i<v;i++)
        {
            p=&adjlist[i];
            while(p!=NULL)
            {
                cout<<p->city<<" ";
                p=p->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph FlightGrid;
    char ch='y';
    int choice;
    while(ch=='y')
    {
    	cout<<"Enter 1 to add new city"<<endl;
    	cout<<"Enter 2 to add new flight path"<<endl;
    	cout<<"Enter 3 to remove a city"<<endl;
    	cout<<"Enter 4 to remove a flight path"<<endl;
    	cout<<"Enter 5 to calculate the number of incoming flights to a city"<<endl;
    	cout<<"Enter 6 to calculate the number of outgoing flights from a city"<<endl;
    	cin>>choice;
    	switch(choice)
    	{
    		case 1: FlightGrid.add_vertex();
    				break;
    		case 2: FlightGrid.add_edge();
    				break;
    		case 3: {
    					string name;
    					cout<<"Enter name of city which is to be removed"<<endl;
    					cin>>name;
    					FlightGrid.remove_vertex(name);
    					break;
    				}
    		case 4: {
    					string source,destination;
    					cout<<"Enter source city name and destination city name"<<endl;
    					cin>>source>>destination;
    					FlightGrid.remove_edge(source,destination);
    					break;
    				}
    		case 5: FlightGrid.in_degree();
    				break;
    		case 6: FlightGrid.out_degree();
    				break;
    		default:cout<<"Wrong choice"<<endl;
    				break;
    	}
    	cout<<"Do you want to continue? (y/n)"<<endl;
    	cin>>ch;
    }
    FlightGrid.display();
    return 0;
}
