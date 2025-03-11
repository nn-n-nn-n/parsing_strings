#include <iostream>
#include <vector>
#include <string>
using namespace std;

string DeleteSpaces(string s)
{
	int pos;
	if (!s.empty())
	{
		do
		{
			pos = s.find(' ');
			if (pos != -1)
				s.erase(pos);
		} while (pos != -1);
		if (s[0] == ' ') s.erase(0);
		if (s[s.length() - 1] == ' ')s.erase(s.length() - 1);
	}
	return s;
}

vector<double> ParseString(string str)
{
	vector<double> vd;

	str = DeleteSpaces(str);
	int pos = 0;
	int pos1 = -1;
	string word;
	double number;
	if (!str.empty())
	{
		do
		{
			pos = str.find(" ", pos);
			if (pos != -1)
			{
				word = str.substr(pos1 + 1, pos - pos1);
				vd.push_back(word);
				pos1 = pos;
				pos++;
			}
			else
			{
				if (pos1 == -1) vd.push_back(str);
				else
				{
					word = str.substr(pos1 + 1, str.length() - pos1);
					vd.push_back(word);
				}
				break;
			}
		} while (pos != -1);
	}
	return vd;
}

int main()
{

}