#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll cnt_all = 0;
ll cnt_s = 0;
ll cnt_ASCII = 0;
ll cnt_hang = 0;
ll cnt_word = 0;
ll cnt_words = 0;
class TXTManager
{
public:
	//1,�ı��ַ���(ASCII)��ͳ��
	void getASCII()
	{
		ifstream fin("youth.txt");
		if (!fin)exit(1);
		char a;
		while (fin >> a)
		{
			if ((int)(a) >= 0 && (int)(a) <= 127)cnt_ASCII++;
		}
		cout << "�ı��ַ���(ASCII):" << cnt_ASCII << endl;
		fin.close();
	}
	//2,����ͳ��
	void getHang()
	{
		ifstream fin("youth.txt");
		if (!fin)exit(1);
		string c;
		while (fin.peek() != EOF)
		{
			getline(fin, c);
			cnt_hang++;
		}
		cout << "����:" << cnt_hang << endl;
		fin.close();
	}
	//3,���ʸ���ͳ��
	void getword()
	{
		ifstream fin("youth.txt");
		if (!fin)exit(1);
		char w[12000];
		while (fin.peek() != EOF)
		{
			fin.getline(w, sizeof(w), '\n');
			
			//fin.getline(w, sizeof(w), ' ');
			cnt_words+=getwords(w);
		}
		cout << "���ʸ���:"<<cnt_words << endl;
		fin.close();
	}
	//4,ĳ���ַ��ĳ��ִ���(���ִ�Сд)
	void searchChar()
	{
		ifstream fin("youth.txt");
		if (!fin)exit(1);
		char s;
		cout << "��������Ҫ��ѯ���ַ���" << endl;
		cin >> s;
		char a;
		while (fin >> a)
		{
			if (a == s)cnt_s++;
			//cout << a;
		}
		cout << s << "�ַ����ֵĴ���:" << cnt_s << endl;
		fin.close();
	}
	//5,ĳ�����ʵĳ��ִ���(�����ִ�Сд)
	void searchWord()
	{
		ifstream fin("youth.txt");
		if (!fin)exit(1);
		char w[1025];
		char y[1025];
		int i = 0;
		cout << "���������ѯ���ʣ�" << endl;
		cin >> y;
		
		for (int i = 0; i < getstrlen(y); i++)
		{
			y[i] = tolower(y[i]);
		}
		while (fin.peek() != EOF)
		{
			fin.getline(w, sizeof(w), '\n');
			cnt_word+=func(w,y);
		}
		cout << y << "���ʳ��ֵĴ���:" << cnt_word << endl;
		fin.close();
	}
	//�ж��Ƿ���ͬ
	bool judge(string w, char* y)
	{
		for (int i = 0; i < w.length(); i++)
		{
			
			if (w[i] != y[i])return false;
		}
		return true;
	}
	//����ÿ���ж��ٸ����ʳ���
	int func(char* x,char*y)
	{	
		int cnt = 0;
		string s;
		for (int i = 0; i < 1024; i++)
		{
			x[i] = tolower(x[i]);
			if (x[i] >= 'a' && x[i] <= 'z')
			{
				s += x[i];
			}
			else if(x[i]==' '||x[i]=='\n')
			{
				if (judge(s, y))cnt++;
				s.erase();
			}
			if (x[i] < 0)return cnt;
		}
		
	}
	//�����ַ���������Ч�ַ���
	int getstrlen(char*x)
	{
		int cnt = 0;
		for (int i = 0; i < 1024; i++)
		{
			cnt++;
			if (x[i] == '\0')return cnt;
			if (x[i] == '\n')return cnt;
		}
		
	}
	//����ÿ���ж��ٸ�����
	int getwords(char*s)
	{
		int cnts = 0;
		for (int i = 0; i < 12000; i++)
		{
			if (s[i] == ' ')cnts++;
			if (s[i] == '\0')
			{
				cnts++;
				return cnts;
			}
		}
	}
};
int main()
{
	TXTManager t;
	int num;
	cout << "���ܣ�" << endl;
	cout << "(1)�ı��ַ���(ASCII)��ͳ��" << endl;
	cout << "(2)����ͳ��" << endl;
	cout << "(3)���ʸ���ͳ��" << endl;
	cout << "(4)ĳ���ַ��ĳ��ִ���(���ִ�Сд)" << endl;
	cout << "(5)ĳ�����ʵĳ��ִ���(�����ִ�Сд)" << endl;
	cin >> num;
	if (num == 1)t.getASCII();
	if (num == 2)t.getHang();
	if (num == 3)t.getword();
	if (num == 4)t.searchChar();
	if (num == 5)t.searchWord();
	
	
		

