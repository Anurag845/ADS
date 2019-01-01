#include<iostream>
#include<string.h>
#define MAX 20

using namespace std;

class Hash
{
	string arr[MAX][2];
	int chain[MAX];
	public:
	Hash()
	{
		for(int i=0;i<MAX;i++)
		{
			for(int j=0;j<2;j++)
			{
				arr[i][j]="\0";
			}
			chain[i]=-1;
		}
	}
	void insert(string);
	void insert_wr(string);
	string search(string);
	void del(string);
	int Hash_value(string);
	int link(string);
	void display();
};
void Hash::insert(string m)
{
	string n;
	cout<<"\n\nEnter meaning : ";
	cin>>n;
	int h,i,k,l;
	h=Hash_value(m);
	l=h;
	if(arr[h][0]=="\0")
	{
		arr[h][0]=m;
		arr[h][1]=n;
		int j;
		j=(h+1)%MAX;
		while(j!=h)
		{
			if(Hash_value(arr[j][0])==h)
			{
				chain[h]=j;
				break;
			}
			j=(j+1)%MAX;
		}
	}
	else
	{
		i=(h+1)%MAX;
		while(arr[i][0]!="\0")
		{
			k=Hash_value(arr[i][0]);
			if(k==l)
			{
				h=i;
			}
			i=(i+1)%MAX;
		}
		if(i==h)
		{
			cout<<"\n\nNo space available";
		}
		else
		{
			arr[i][0]=m;
			arr[i][1]=n;
			if(Hash_value(m)==Hash_value(arr[h][0]))
				chain[h]=i;
		}
	}
}
int Hash::Hash_value(string m)
{
	int n=0,x;
	n=m[0];
	x=n%MAX;
	return x;
}
string Hash::search(string m)
{
	int h;
	h=Hash_value(m);
	if(m.compare(arr[h][0])==0)
	{
		return arr[h][1];
	}
	else
	{
		int flag=0;
		while(chain[h]!=-1)
		{
			h=chain[h];
			if(m.compare(arr[h][0])==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			return "\0";
		}
		else
		{
			return arr[h][1];
		}
	}
}
void Hash::del(string m)
{
	int h,l;
	h=Hash_value(m);
	l=link(m);
	if(m.compare(arr[h][0])==0)
	{
		arr[h][0]="\0";
		arr[h][1]="\0";
		if(l!=-1)
			chain[l]=chain[h];
		chain[h]=-1;
	}
	else
	{
		int flag=0;
		while(chain[h]!=-1)
		{
			h=chain[h];
			if(m.compare(arr[h][0])==0)
			{
				l=link(m);
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"\n\nKey not present";
		}
		else
		{
			arr[h][0]="\0";
			arr[h][1]="\0";
			if(l!=-1)
				chain[l]=chain[h];
			chain[h]=-1;
		}
	}
}
int Hash::link(string m)
{
	int l=-1;
	for(int i=0;i<MAX;i++)
	{
		if(chain[i]!=-1)
		{
			if(arr[chain[i]][0].compare(m)==0)
				return i;
		}
	}
	return -1;
}
void Hash::display()
{
	for(int i=0;i<MAX;i++)
	{
		if(arr[i][0]!="\0")
		{
			cout<<arr[i][0]<<" : "<<arr[i][1]<<" "<<i<<" "<<chain[i]<<endl;
		}
	}
}
void Hash::insert_wr(string m)
{
	string n,p,q;
	cout<<"\n\nEnter meaning : ";
	cin>>n;
	int h,i,j,k,l;
	h=Hash_value(m);
	l=h;
	if(arr[h][0]=="\0")
	{
		arr[h][0]=m;
		arr[h][1]=n;
		j=(h+1)%MAX;
		while(j!=h)
		{
			if(Hash_value(arr[j][0])==h)
			{
				chain[h]=j;
				break;
			}
			j=(j+1)%MAX;
		}
	}
	else
	{
		if(Hash_value(arr[h][0])==h)
		{
			i=(h+1)%MAX;
			while(arr[i][0]!="\0")
			{
				k=Hash_value(arr[i][0]);
				if(k==l)
				{
					h=i;
				}
				i=(i+1)%MAX;
			}
			if(i==h)
			{
				cout<<"\n\nNo space available";
			}
			else
			{
				arr[i][0]=m;
				arr[i][1]=n;
				if(Hash_value(m)==Hash_value(arr[h][0]))
					chain[h]=i;
			}
		}
		else
		{
			int x,y,z;
			p=arr[h][0];
			q=arr[h][1];
			z=chain[h];
			y=link(p);
			arr[h][0]=m;
			arr[h][1]=n;
			chain[h]=-1;
			x=(h+1)%MAX;
			while(arr[x][0]!="\0")
			{
				x=(x+1)%MAX;
			}
			arr[x][0]=p;
			arr[x][1]=q;
			chain[x]=z;
			if(y!=-1)
				chain[y]=x;
			if(x==h)
				cout<<"\nTable is full\n";
		}
	}
}
int main()
{
	Hash h;
	string m,n;
	int choice,c;
	cout<<"\nEnter choice : \n1.Insert without replacement\n2.Insert with replacement\n";
	cin>>c;
	if(c==1)
	{
		do
		{
			cout<<"\n\nEnter Choice : \n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n";
			cin>>choice;
			switch(choice)
			{
			case 1:
				cout<<"\n\nEnter key : ";
				cin>>m;
				h.insert(m);
				break;
			case 2:
				cout<<"\n\nEnter key : ";
				cin>>m;
				n=h.search(m);
				if(n!="\0")
					cout<<"\n\n"<<m<<" : "<<n;
				else
					cout<<"\n\nKey not found";
				break;
			case 3:
				cout<<"\n\nEnter key : ";
				cin>>m;
				h.del(m);
				break;
			case 4:
				h.display();
				break;
			case 5:
				break;
			}
		}while(choice!=5);
	}
	else
	{
		do
		{
			cout<<"\n\nEnter Choice : \n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n";
			cin>>choice;
			switch(choice)
			{
			case 1:
				cout<<"\n\nEnter key : ";
				cin>>m;
				h.insert_wr(m);
				break;
			case 2:
				cout<<"\n\nEnter key : ";
				cin>>m;
				n=h.search(m);
				if(n!="\0")
					cout<<"\n\n"<<m<<" : "<<n;
				else
					cout<<"\n\nKey not found";
				break;
			case 3:
				cout<<"\n\nEnter key : ";
				cin>>m;
				h.del(m);
				break;
			case 4:
				h.display();
				break;
			case 5:
				break;
			}
		}while(choice!=5);
	}
	return 0;
}
