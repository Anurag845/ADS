#include<iostream>
using namespace std;

class node
{  
    string word;
    string meaning;
       public:
    node()
    {
        word="-";
        meaning="-";
    }
    friend class HashTable;
};

class HashTable
{
    int t_size;
    int r;
    int cnt;
    node *d;

    public:
    HashTable()
    {
        t_size=5;
        r=0;
        cnt=0;
        d=new node[t_size];
        cout<<"Hashing without replacement:-0 and with replacement:-1. Enter your preference."<<endl;
        cin>>r;
        while(r!=0 && r!=1)
        {
            cin.clear();
            cin.ignore(5);
            cout<<"Enter 0 or 1 only"<<endl;
            cin>>r;
        }
    }

    void rehash()
    {
        cnt=0;
        node *temp=d;
        int i,hash=0;
        d=new node[t_size];
        for(int i=0;i<0.5*t_size;i++)
        {
            if(temp[i].word!="-")
            {
                insert(temp[i].word,temp[i].meaning);
            }
        }
        delete []temp;
    }

    int hash_function(string key)
    {
        int i,hash=0;
        for(i=0;i<key.size();i++)
        {
            hash+=(int)key[0];
        }
        return hash % t_size;
    }

    void insert(string key,string mean)
    {
        if(cnt>=0.75*t_size)
        {
            t_size=2*t_size;
            rehash();
        }
        int i,hash=0;
  
        hash=hash_function(key);
  
        if(d[hash].word=="-")
        {
            d[hash].word=key;
            d[hash].meaning=mean;
            cnt++;
            return;
        }
        if(r==1)                            //with replacement
        {
            string tword=d[hash].word;
            string tmean=d[hash].meaning;
            d[hash].word=key;
            d[hash].meaning=mean;
            i=hash+1;
            do
            {
                if(d[i].word=="-")
                {
                    d[i].word=tword;
                    d[i].meaning=tmean;
                    cnt++;
                    return;
                }
                i++;
                i=i%t_size;
            }
            while(i!=hash);
        }
        else                                //without replacement
        {
            i=hash+1;
            do
            {
                if(d[i].word=="-")
                {
                    d[i].word=key;
                    d[i].meaning=mean;
                    cnt++;
                    return;
                }
                i++;
                i=i%t_size;
            }
            while(i!=hash);
        }
    }

    int search(string key,string mean)
    {
        int hash,i;
        hash=hash_function(key);
        if(d[hash].word==key)
        {
            return hash;
        }
        else
        {
            i=hash+1;
            do
            {
                if(d[i].word==key)
                {
                    return i;
                }
                i++;
                i=i%t_size;
            }
            while(i!=hash);
            return -1;
        }
    }

    void remove(string key,string mean)
    {
  		int i,hash;
  		hash=search(key,mean);
  		if(hash!=-1)
  		{
  			d[hash].word="-";
  			d[hash].meaning="-";
  			cout<<"Deletion successful"<<endl;
  			return;
  		}
  		else
  		{
  			cout<<"Requested entry not present"<<endl;
  		}
    }

    void display()
    {
    	cout<<"Hash table is"<<endl;
        for(int i=0;i<t_size;i++)
        {
            cout<<i<<"\t"<<d[i].word<<"\t"<<d[i].meaning<<endl;
        }
    }

    node* retd()
    {
        return d;
    }
};

int main()
{
    HashTable H;
    int choice;
    char ch='y';
    string key,mean;
   
    while(ch=='y')
    {
        cout<<"Enter 1 to insert a (word,meaning) pair"<<endl;
        cout<<"Enter 2 to search a (word,meaning) pair"<<endl;
        cout<<"Enter 3 to remove a (word,meaning) pair"<<endl;
        cout<<"Enter 4 to display the hash table"<<endl;
        cin>>choice;
        while(choice!=1 && choice!=2 && choice!=3 && choice!=4)
        {
            cin.clear();
            cin.ignore(5);
            cout<<"Enter a value from 1 to 4 only"<<endl;
            cin>>choice;
        }
        switch(choice)
        {
            case 1: cout<<"Enter word"<<endl;
        			cin>>key;
        			cout<<"Enter meaning"<<endl;
        			cin>>mean;
            		H.insert(key,mean);
                    break;
            case 2: cout<<"Enter word"<<endl;
        			cin>>key;
        			cout<<"Enter meaning"<<endl;
        			cin>>mean;
            		cout<<"("<<key<<","<<mean<<")"<<" found at position "<<H.search(key,mean)<<endl;
                    break;
            case 3: cout<<"Enter word"<<endl;
        			cin>>key;
        			cout<<"Enter meaning"<<endl;
        			cin>>mean;
            		H.remove(key,mean);
                    break;
            case 4: H.display();
                    break;
        }
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>ch;
    }

    return 0;
}
