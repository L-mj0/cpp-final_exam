#include<bits/stdc++.h>
using namespace std;
class ImgProc
{
public:
	int num;
	void Gray()
	{
		ifstream fin("kiki.bmp", ios::binary);
		ofstream fout("kiki_1.bmp", ios::binary);
		if (!fin || !fout)exit(1);

		unsigned char buf[1024] = { 0 };
		fin.read((char*)buf, 54);
		fout.write((char*)buf, 54);
		unsigned int w = 700, h = 700;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				//Gray = R*0.299 + G*0.587 + B*0.114
				fin.read((char*)buf, 3);
				unsigned char t;
				t = buf[0] * 0.114 + buf[1] * 0.587 + buf[2] * 0.299;
				buf[0] = buf[1] = buf[2] = t;
				fout.write((char*)buf, 3);
			}
		}
		fin.close();
		fout.close();
	}
	void masaike()
	{

		ifstream fin("kiki.bmp", ios::binary);
		ofstream fout("kiki_2.bmp", ios::binary);
		if (!fin || !fout)exit(1);

		unsigned char buf[1024] = { 0 };
		fin.read((char*)buf, 54);
		fout.write((char*)buf, 54);
		unsigned int w = 700, h = 700;
		unsigned char color[4900][3];//148
		int m = 0;
		int a, b;
		for (int i = 0; i < h; i++)
		{
			if (i % 10 == 0)
			{
				for (int j = 0; j < w; j++)
				{
					//	fout.write((char*)color, 3);
					if (j % 10 == 0)
					{
						a = i / 10 * 3;
						b = j / 10;
						m = a * 21 + b;
						fin.read((char*)buf, 3);
						color[m][0] = buf[0];
						color[m][1] = buf[1];
						color[m][2] = buf[2];
					}
					else
					{
						fin.read((char*)buf, 3);
					}
				}
			}
			else
			{
				for (int j = 0; j < w; j++)
				{
					fin.read((char*)buf, 3);
				}
			}
		}

		//fin.seekg(54, ios::cur);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				//i/10*3
				int c, d, m;
				c = i / 10 * 3;
				d = j / 10;
				m = c * 21 + d;
				fin.read((char*)buf, 3);
				buf[0] = color[m][0];
				buf[1] = color[m][1];
				buf[2] = color[m][2];
				fout.write((char*)buf, 3);
			}
		}
		fin.close();
		fout.close();
	}
	void koutu()
	{
		ifstream fin("lotus.bmp", ios::binary);
		ofstream fout("lotus_out.bmp", ios::binary);
		unsigned char buf[1024] = { 0 };

		fin.read((char*)buf, 54);
		fout.write((char*)buf, 54);
		unsigned int w = 1200, h = 800;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				fin.read((char*)buf, 3);
				//p过了
				/*if (buf[0] < 230 && buf[1]>130 && buf[2] > 100 && buf[2] < 220)
				{
					buf[0] = buf[1] = buf[2] = 255;
					fout.write((char*)buf, 3);
				}*/

				//完美
				if (buf[1] > buf[2] && buf[1] > buf[0])
				{
					buf[0] = buf[1] = buf[2] = 255;
					fout.write((char*)buf, 3);
				}
				else if (buf[2] > 100)
				{
					fout.write((char*)buf, 3);
				}
				else if (buf[2] > buf[1] && buf[2] > buf[0] && buf[2] > 60)
				{
					fout.write((char*)buf, 3);
				}
				else if (buf[2] > 100 && buf[0] > 100)
				{
					fout.write((char*)buf, 3);
				}
				else if (buf[1] > 150 && buf[2] > 100)
				{
					fout.write((char*)buf, 3);
				}
				else
				{
					buf[0] = buf[1] = buf[2] = 255;
					fout.write((char*)buf, 3);

				}
			}
		}
		fin.close();
		fout.close();
	}
};
int main()
{
	ImgProc i;
	cout << "请输入想实现功能序号：" << endl;
	cout << "(1)图像灰度处理" << endl;
	cout << "(2)图像马赛克处理" << endl;
	cout << "(3)图像抠图处理" << endl;

	int a;
	cin >> a;
	if (a == 1)i.Gray();
	if (a == 2)i.masaike();
	if (a == 3)i.koutu();

	return 0;
}
