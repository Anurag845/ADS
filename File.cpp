#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

#define max 50
class student
{
	int rollno,div;
	char name[max],address[max];
public:
	student(int r, int d, char n[max], char a[max])
	{
		rollno = r;
		div = d;
		strcpy(name,n);
		strcpy(address,a);
	}
	student()
	{
		rollno = 0;
		div = 0;
		strcpy(name,"");
		strcpy(address,"");
	}
	friend class info;
};

class info
{
	fstream file;
	char* f;
public:
	info(char* f)
	{
		this->f = f;
		ofstream create;
		create.open(f);
		create.close();
	}
	void addinfo(int r, int d, char n[max], char a[max]);
	void deleteinfo(int r);
	void display(int r);
};

void info::addinfo(int r, int d, char n[max], char a[max])
{
	student obj(r, d, n, a);
	//cout << "a" << endl;
	file.open("Example.txt", ios::out | ios::app);
	file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
	file.close();
	file.clear();
	cout << "Student information added successfully." << endl;
}

void info::deleteinfo(int r)
{
	file.open("Example.txt", ios::in);
	vector<student> vec;
	student obj;
	bool flag = 0;
	while (!file.eof())
	{
		file.read(reinterpret_cast<char*>(&obj), sizeof(obj));
		if (obj.rollno != r)
			vec.push_back(obj);
		else
			flag = 1;
	}
	file.close();
	file.open("Example.txt", ios::out | ios::trunc);
	for (int i = 0;i<vec.size();i++)
	{
		student o = vec.at(i);
		file.write(reinterpret_cast<char*>(&o), sizeof(o));
	}
	file.close();
	if (!flag)
		cout << "There was no student with the given roll number." << endl;
	else
		cout << "Student information deleted successfully." << endl;
}

void info::display(int r)
{

	file.clear();
	file.open("Example.txt", ios::in);
	student obj;
	bool flag = 0;
	file.read(reinterpret_cast<char*>(&obj), sizeof(obj));
	while (!file.eof())
	{
		if (obj.rollno == r)
		{
			flag = 1;
			break;
		}
		file.read(reinterpret_cast<char*>(&obj), sizeof(obj));
	}
	file.close();
	file.clear();
	if (!flag)
	{
		cout << "There was no student with the given roll number." << endl;
		return;
	}
	cout << "Student information:" << endl;
	cout << "Name: " << obj.name << endl;
	cout << "Roll No. " << obj.rollno << endl;
	cout << "Division: " << obj.div << endl;
	cout << "Address: " << obj.address << endl;
}

int main()
{
	int choice, rollno, div;
	info obj("Example.txt");
	char yn='y', name[max], add[max];
	string n, a;
	while(yn=='y')
	{
	cout << "Enter 1 to add data\n2 to delete data\n3 to display data:" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Enter name:" << endl;
		cin.ignore();
		getline(cin, n);
		strcpy(name, n.c_str());
		cout << "Enter address:" << endl;
		getline(cin, a);
		strcpy(add, a.c_str());
		cout << "Enter roll no." << endl;
		cin >> rollno;
		cout << "Enter division:" << endl;
		cin >> div;
		obj.addinfo(rollno, div, name, add);
		break;
	case 2:
		cout << "Enter roll number of student you want to delete:" << endl;
		cin >> rollno;
		obj.deleteinfo(rollno);
		break;
	case 3:
		cout << "Enter roll number of student you want to display:" << endl;
		cin >> rollno;
		obj.display(rollno);
		break;
	}
	cout << "Do you want to continue? (y/n)" << endl;
	cin >> yn;
	}
	//if (yn == 'y' || yn == 'Y')
		//goto a;
	return 0;
}
