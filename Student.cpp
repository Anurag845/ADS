#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

class student
{
	int rno;
	int div;
	char name[20];
	char add[20];
	
	public:
	
	student()
	{
		rno=0;
		div=0;
		strcpy(name,"");
		strcpy(add,"");
	}
	
	student(int r,int d,char n[20],char a[20])
	{
		rno=r;
		div=d;
		strcpy(name,n);
		strcpy(add,a);
	}
	friend class database;
};

class database
{
	fstream file;
	char *f;
	
	public:
	
	database(char *nm)
	{
		f=nm;
		ofstream ofile;
		ofile.open(f);
		ofile.close();
	}
	
	void add_entry(int r,int d,char n[20],char a[20])
	{
		student obj(r,d,n,a);
		file.open(f,ios::out | ios::app);
		file.write(reinterpret_cast<char*>(&obj),sizeof(obj));
		file.close();
		file.clear();
		cout<<"Entry added successfully"<<endl;
	}
	
	void del_entry(int r)
	{
		vector<student> vec;
		bool flag=0;
		student obj;
		file.open(f,ios::in);
		while(!file.eof())
		{
			file.read(reinterpret_cast<char*>(&obj),sizeof(obj));
			if(obj.rno!=r)
				vec.push_back(obj);
			else flag=1;
		}
		file.close();
		int i=0;
		file.open(f,ios::out | ios::trunc);
		do
		{
			obj=vec.at(i);
			file.write(reinterpret_cast<char*>(&obj),sizeof(obj));
			i++;
		}while(i<vec.size());
		file.close();
		cout<<"Entry deleted successfully"<<endl;
	}
	
	void display(int r)
	{
		file.clear();
		student obj;
		file.open(f,ios::in);
		int flag=0;
		file.read(reinterpret_cast<char*>(&obj),sizeof(obj));
		while(!file.eof())
		{
			if(obj.rno==r)
			{
				flag=1;
				break;
			}
			file.read(reinterpret_cast<char*>(&obj),sizeof(obj));
		}
		file.close();
		file.clear();
		if(flag==0)
		{
			cout<<"Entry not found"<<endl;
		}
		cout<<"Name "<<obj.name<<endl;
		cout<<"Address "<<obj.add<<endl;
		cout<<"Roll no "<<obj.rno<<endl;
		cout<<"Division "<<obj.div<<endl;
	}
};

int main()
{
	database D("s.txt");
	int choice,r,d;
	char ch='y',nam[20],adr[20];
	string nm,ad;
	while(ch=='y')
	{
		cout<<"Enter 1 to add new entry"<<endl;
		cout<<"Enter 2 to delete an entry"<<endl;
		cout<<"Enter 3 to display entries"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter name"<<endl;
					cin.ignore();
					getline(cin,nm);
					strcpy(nam,nm.c_str());
					cout<<"Enter address"<<endl;
					getline(cin,ad);
					strcpy(adr,ad.c_str());
					cout<<"Enter roll no"<<endl;
					cin>>r;
					cout<<"Enter division"<<endl;
					cin>>d;
					D.add_entry(r,d,nam,adr);
					break;
			case 2: cout<<"Enter roll no"<<endl;
					cin>>r;
					D.del_entry(r);
					break;
			case 3: cout<<"Enter roll no"<<endl;
					cin>>r;
					D.display(r);
					break;
		}
		cout<<"Do you want to continue?"<<endl;
		cin>>ch;
	}
	return 0;
}

