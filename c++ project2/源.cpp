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
	//1,文本字符数(ASCII)的统计
	void getASCII()
	{
		ifstream fin("youth.txt");
		if (!fin)exit(1);
		char a;
		while (fin >> a)
		{
			if ((int)(a) >= 0 && (int)(a) <= 127)cnt_ASCII++;
		}
		cout << "文本字符数(ASCII):" << cnt_ASCII << endl;
		fin.close();
	}
	//2,行数统计
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
		cout << "行数:" << cnt_hang << endl;
		fin.close();
	}
	//3,单词个数统计
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
		cout << "单词个数:"<<cnt_words << endl;
		fin.close();
	}
	//4,某个字符的出现次数(区分大小写)
	void searchChar()
	{
		ifstream fin("youth.txt");
		if (!fin)exit(1);
		char s;
		cout << "请输入想要查询的字符：" << endl;
		cin >> s;
		char a;
		while (fin >> a)
		{
			if (a == s)cnt_s++;
			//cout << a;
		}
		cout << s << "字符出现的次数:" << cnt_s << endl;
		fin.close();
	}
	//5,某个单词的出现次数(不区分大小写)
	void searchWord()
	{
		ifstream fin("youth.txt");
		if (!fin)exit(1);
		char w[1025];
		char y[1025];
		int i = 0;
		cout << "请输入想查询单词：" << endl;
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
		cout << y << "单词出现的次数:" << cnt_word << endl;
		fin.close();
	}
	//判断是否相同
	bool judge(string w, char* y)
	{
		for (int i = 0; i < w.length(); i++)
		{
			
			if (w[i] != y[i])return false;
		}
		return true;
	}
	//计算每行有多少个单词出现
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
	//计算字符数组中有效字符数
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
	//计算每行有多少个单词
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
	cout << "功能：" << endl;
	cout << "(1)文本字符数(ASCII)的统计" << endl;
	cout << "(2)行数统计" << endl;
	cout << "(3)单词个数统计" << endl;
	cout << "(4)某个字符的出现次数(区分大小写)" << endl;
	cout << "(5)某个单词的出现次数(不区分大小写)" << endl;
	cin >> num;
	if (num == 1)t.getASCII();
	if (num == 2)t.getHang();
	if (num == 3)t.getword();
	if (num == 4)t.searchChar();
	if (num == 5)t.searchWord();
	
	
		

