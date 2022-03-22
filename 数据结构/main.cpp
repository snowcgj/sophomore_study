#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class basic {
private :
public:
	void meun()
	{
		printf("*************************************************\n");
		printf("*\t欢迎使用battad的单词检索统计程序V1.0\t*\n");
		printf("*\t\t请选择功能\t\t\t*\n");
		printf("*************************************************\n");
		printf("*\t\t1.建立文件\t\t\t*\n");
		printf("*\t\t2.单词计数\t\t\t*\n");
		printf("*\t\t3.单词定位\t\t\t*\n");
		printf("*\t\t4.退出程序\t\t\t*\n");
		printf("*************************************************\n");
	}
	void bulid_file()
	{
		string s, filename;
		cout << "请输入文件名字：";
		cin >> filename;
		ofstream f1(filename + ".txt", ios::out);
		cout << "请输入文本：(结束输入时请在新的一行中按下ctrl+Z)" << endl;
		char c = getchar();
		while ((c = getchar()) != EOF)
		{
			f1 << c;
		}
		f1.close();
//		EOF 的话会多一行，
//  $的话会牺牲一个字符。
//其他的输入没有想到合适的
//这个不是追加的。
	}
	int  word_count(string s, string word)
	{
		int i = s.find(word), count = 0;
		for (; i < s.size();)
		{
			count++;
			i = s.find(word, i + 1);
		}
		return count;
	}
	void word_sum()
	{
		string s,filename,word;
		cout << "请输入要打开的文件名字（不包含.txt）：";
		cin >> filename;
		ifstream f(filename + ".txt", ios::in);
		cout << "请输入要查找的单词：";
		cin >> word;
		int sum = 0;
		if (f)
		{
			while (!f.eof())
			{
				getline(f, s);
				sum += word_count(s, word);
				//cout << s << endl;
			}
			f.close();
		}
		else cout << "open file error!" << endl;
		cout << word<<"的数量是："<<sum << endl;
		f.close();
	}
	void operation_3()
	{
		string s, filename,word;
		cout << "请输入要打开的文件名字（不包含.txt）：";
		cin >> filename;
		ifstream f(filename + ".txt", ios::in);
		cout << "请输入你要操作的单词：";
		cin >> word;
		int column = 0;
		int row = 0;
		if (f)
		{
			while (!f.eof())
			{
				row++;
				getline(f, s);
				if (s.find(word) != string::npos)
				{
					column = s.find(word) + 1;
					break;
				}
			}
			f.close();
		}
		else cout << "open file error!" << endl;
		if (column)
			cout << "as" << "在第" << row << "行" << "第" << column << "个字符第一次出现" << endl;
		else
			cout << "该文本中没有这个单词" << endl;
	}
};

int main()
{
	basic sd;
	while (1)
	{
		sd.meun();
		int c;
		cin >> c;
		{
			switch (c)
			{
			case 1:
				sd.bulid_file();
				break;
			case 2:
				sd.word_sum();
				break;
			case 3:
				sd.operation_3();
				break;
			case 4:
				return 0;
				break;
			default:
				cout << "请输入正确的数字!";
			}
		}
	}
}
