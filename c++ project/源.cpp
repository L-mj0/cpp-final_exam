#include<bits/stdc++.h>
using namespace std;
class Student 
{
public:
	char name[200];
	char ID[200];
	char phone[200];
	char color[200];
	char f[200];
	Student* next;
	Student() :next(nullptr) {}
	Student(char* Name, char* Id, char* Phone, char* Color, char* F) 
	{
		strcpy(ID, Id);
		strcpy(name, Name);
		strcpy(phone, Phone);
		strcpy(color, Color);
		strcpy(f, F);
		next = nullptr;
	}
	void creat(char* Name, char* Id, char* Phone, char* Color, char* F) 
	{
		strcpy(ID, Id);
		strcpy(name, Name);
		strcpy(phone, Phone);
		strcpy(color, Color);
		strcpy(f, F);
		next = nullptr;
	}
	Student(Student& n) 
	{
		strcpy(ID, n.ID);
		strcpy(name, n.name);
		strcpy(phone, n.phone);
		strcpy(color, n.color);
		strcpy(f, n.f);
		next = nullptr;
	}
};
class Link {
public:
	Student* head;
	Link() {head = new Student();}
	void addStudentTail(Student* s) 
	{
		Student* p = head;
		while (p->next != nullptr) 
		{
			p = p->next;
		}
		Student* newStudent = new Student(*s);
		p->next = newStudent;
	}
	void traverse() 
	{
		Student* p = head->next;
		while (p != nullptr) 
		{
			cout << p->name << " " << p->ID << " " << p->phone << " " << p->color << " " << p->f << endl;
			p = p->next;
		}
		cout << endl;
	}
	bool func(char* x, char* y)
	{
		for (int i = 0; i < 2; i++)
		{
			if (x[i] != y[i])return false;
		}
		return true;
	}
	void getColor(char* na)
	{
		Student* p = head->next;
		while (p != nullptr)
		{
			if (func(p->name,na))
			{
				cout << p->color << " " << p->f << endl;
				break;
			}
			p = p->next;
		}
	}
	void displayUndoing()
	{
		Student* p = head->next;
		while (p != nullptr)
		{
			if (p->f[0] == -73)cout << p->name << " " << p->ID << " " <<" "<<p->phone<<" "<< p->color << " " << p->f << endl;
			p = p->next;
		}
	}
	//绿码：-62,-52,-62,-21,\0
	bool green(char* x)
	{
		if (x[0] != -62)return false;
		if (x[1] != -52)return false;
		if (x[2] != -62)return false;
		if (x[3] != -21)return false;
		return true;
	}
	//红码： -70,-20,-62,-21,'\0'
	bool red(char* x)
	{
		if (x[0] != -70)return false;
		if (x[1] != -20)return false;
		if (x[2] != -62)return false;
		if (x[3] != -21)return false;
		return true;
	}
	//绿码：-62,-52,-62,-21,\0
	bool yellow(char* x)
	{
		if (x[0] != -69)return false;
		if (x[1] != -58)return false;
		if (x[2] != -62)return false;
		if (x[3] != -21)return false;
	}
	void setfile()
	{
		Student* p = head->next;
		ofstream foutgreen("绿码.txt");
		ofstream foutyellow("黄码.txt");
		ofstream foutred("红码.txt");
		while (p->next != nullptr)
		{
			if (green(p->color))
			{
				foutgreen << p->name << " " << p->ID << " " << p->phone << " " << p->color << " " << p->f << endl;
			}
			if (red(p->color))
			{
				foutred << p->name << " " << p->ID << " " << p->phone << " " << p->color << " " << p->f << endl;
			}
			if (yellow(p->color))
			{
				foutyellow << p->name << " " << p->ID << " " << p->phone << " " << p->color << " " << p->f << endl;
			}
			p = p->next;
		}
	}
};

int main() 
{
	ifstream fin("疫情管理人员2.txt");
	if (!fin) 
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	//2 8 11 2 2
	Link link;
	char c[1153];
	fin.getline(c, sizeof(c));

	int i = 0;
	Student s[8];
	while (i < 8)
	{
		char name[1024];
		char ID[1024];
		char phone[1024];
		char color[1024];
		char f[1024];

		fin.getline(name, sizeof(name), ' ');
		fin.getline(ID, sizeof(ID), ' ');
		fin.getline(phone, sizeof(phone), ' ');
		fin.getline(color, sizeof(color), ' ');
		fin.getline(f, sizeof(f), '\n');

		s[i].creat(name, ID, phone, color, f);
		link.addStudentTail(&s[i]);
		//link.traverse();
		i++;
	}
	int p;
	cout << "功能：" << endl;
	cout << "(1)根据姓名查询学生的健康码和核酸检测状态" << endl;
	cout << "(2)显示所有未做核酸检测的学生信息" << endl;
	cout << "请输入想实现功能的序号：" << endl;
	cin >> p;
	//根据学生姓名查询学生健康码和核酸检测状态
	if (p == 1)
	{
		char ch[200];
		cout << "请输入查询学生名字：" << endl;
		cin >> ch;
		link.getColor(ch);
		cout << endl;
	}
	
	//显示所有未做核酸检测的学生信息
	if(p==2)link.displayUndoing();
	
	//根据健康码状态将人员数据储存到文件
	link.setfile();
	

	fin.close();
}