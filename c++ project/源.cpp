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
	//���룺-62,-52,-62,-21,\0
	bool green(char* x)
	{
		if (x[0] != -62)return false;
		if (x[1] != -52)return false;
		if (x[2] != -62)return false;
		if (x[3] != -21)return false;
		return true;
	}
	//���룺 -70,-20,-62,-21,'\0'
	bool red(char* x)
	{
		if (x[0] != -70)return false;
		if (x[1] != -20)return false;
		if (x[2] != -62)return false;
		if (x[3] != -21)return false;
		return true;
	}
	//���룺-62,-52,-62,-21,\0
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
		ofstream foutgreen("����.txt");
		ofstream foutyellow("����.txt");
		ofstream foutred("����.txt");
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
	ifstream fin("���������Ա2.txt");
	if (!fin) 
	{
		cout << "�ļ���ʧ��" << endl;
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
	cout << "���ܣ�" << endl;
	cout << "(1)����������ѯѧ���Ľ�����ͺ�����״̬" << endl;
	cout << "(2)��ʾ����δ���������ѧ����Ϣ" << endl;
	cout << "��������ʵ�ֹ��ܵ���ţ�" << endl;
	cin >> p;
	//����ѧ��������ѯѧ��������ͺ�����״̬
	if (p == 1)
	{
		char ch[200];
		cout << "�������ѯѧ�����֣�" << endl;
		cin >> ch;
		link.getColor(ch);
		cout << endl;
	}
	
	//��ʾ����δ���������ѧ����Ϣ
	if(p==2)link.displayUndoing();
	
	//���ݽ�����״̬����Ա���ݴ��浽�ļ�
	link.setfile();
	

	fin.close();
}