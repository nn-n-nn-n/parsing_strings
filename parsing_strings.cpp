#include <iostream>
#include <vector>
#include <string>
using namespace std;

string DeleteSpaces(string s)		// функция удаления пробелов в строке
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
	}
	return s;
}

vector<double> ParseString(string str)	// функция парсинга
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
		if (pos != string::npos)
		{
			word = str.substr(pos2, pos - pos1);	// получаем первое число
			number = stod(word);
			vd.push_back(number);
		}
		while (pos != string::npos)		// цикл для получения остальных чисел в векторе
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
				break;	// выход из цикла, когда вектор достиг конца
		}
	}
	return vd;
}

void PrintXY(vector<double> vector)		// функция вывода в консоль
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
	//string str = "   11.2, 321.1,32,1";
	vector<double> vector = ParseString(str);
	PrintXY(vector);
}