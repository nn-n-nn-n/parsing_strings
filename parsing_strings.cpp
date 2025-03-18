#include <iostream>
#include <vector>
#include <string>
using namespace std;

string DeleteSpaces(string s)
{
	size_t pos = s.find(' ');

	if (!s.empty())
	{
		while (pos != string::npos)
		{
			if (pos != string::npos)
				s.erase(pos, 1);
			pos = s.find(' ');
		}
		//if (s[0] == ' ') s.erase(0);
		//if (s[s.length() - 1] == ' ')s.erase(s.length() - 1);
	}
	return s;
}

vector<double> ParseString(string str)
{
	vector<double> vd;

	str = DeleteSpaces(str);
	size_t pos = 0;
	size_t pos1 = string::npos;
	size_t pos2 = 0;
	string word;
	double number;
	if (!str.empty())
	{
		pos = str.find(',', pos);
		word = str.substr(pos2, pos - pos1);
		number = stod(word);
		vd.push_back(number);
		while (pos != string::npos)
		{
			pos = str.find(',', pos);
			if (pos != string::npos)
			{
				word = str.substr(pos + 1, pos - pos1);
				number = stod(word);
				vd.push_back(number);
				pos1 = pos;
				pos++;
			}
			else
				break;
		}
	}
	return vd;
}

void PrintXY(vector<double> vector)
{
	setlocale(LC_ALL, "");
	cout << "Количество точек: " << vector.size() / 2 << endl;
	cout << "Координаты:" << endl << 'X' << '\t' << 'Y' << endl;
	for (int i = 0; i<vector.size();i+=2)
	{
		double d1 = vector[i], d2 = vector[i+1];
		cout << d1 << '\t' << d2 << endl;
	}
}

int main()
{
	string str = "192.56, -21.2, 17.08, 22.8, -0.01, 0.02, 33.2, 43.8, -12.1, 14.5";

	vector<double> vector = ParseString(str);
	PrintXY(vector);
}