#include <iostream>
#include <vector>
#include <string>

using namespace std;
int FindNextBracket(vector<char> v) {
	int brackPos = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == ')') {
			brackPos = i;
			break;
		}
	}
	return brackPos;
}
bool ChackForSymb(char symb) {
	if (symb == '+' || symb == '-' || symb == '*' || symb == '/'||symb == '('||symb == ')')
	{
		return true;
	}
	return false;
}
int Sum(vector<string> numbers, vector<char> symbols);
int main() {
	string input;
	int pos = 0;
	vector<string> numbers;
	vector<char> symbols;
	getline(cin, input);
	for (int i = 0; i <= input.size(); i++)
	{
		//read numbers
		if (ChackForSymb(input[i])||i == input.size())
		{
			string num1;
			num1 = input.substr(pos, i-pos);
			numbers.push_back(num1);
			pos = i+1;
		}
		if (ChackForSymb(input[i])) {
			symbols.push_back(input[i]);
		}
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == "")
		{
			numbers.erase(numbers.begin() + i);
		}
	}
	cout << endl;
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}
	cout << endl;
	int FullSum = Sum(numbers, symbols);
	cout << "++++++++++++++++++++++++" << endl << FullSum << endl << "++++++++++++++++++++++++" << endl;
	system("pause");
	return 0;
}
int SumInBrackets(vector<string> &_numbers, vector<char> &_symbols,int firstBrackPos) {
	int sumInBrackets = 0;
	vector<string> numbers;
	vector<char> symbols;
	for (int i = firstBrackPos+1; i < FindNextBracket(_symbols); i++)
	{
		symbols.push_back(_symbols[i]);
	}
	for (int i = firstBrackPos; i < FindNextBracket(_symbols); i++)
	{
		numbers.push_back(_numbers[i]);
	}//gavaqrot frchxilebs shignit ricxxvebi da simboloebi
	_numbers.erase(_numbers.begin() + firstBrackPos, _numbers.begin() + FindNextBracket(_symbols));
	_symbols.erase(_symbols.begin() + firstBrackPos, _symbols.begin() + FindNextBracket(_symbols)+1);
	sumInBrackets = Sum(numbers,symbols);
	return sumInBrackets;
}
int SumNumbers(vector<string> &numbers, vector<char> &symbols, int firstNumIndex,int secendNumberIndex,int symbolIndex) {
	int flSumm = 0;
	switch (symbols[symbolIndex]) {//es unda gavitanot calke metodad
	case '+':
		flSumm = atoi(numbers[firstNumIndex].c_str()) + atoi(numbers[secendNumberIndex].c_str());
		symbols.erase(symbols.begin() + symbolIndex);
		numbers.erase(numbers.begin() + firstNumIndex, numbers.begin() + 2);
		numbers.insert(numbers.begin()+ symbolIndex, to_string(flSumm));
		break;
	case '-':
		flSumm = atoi(numbers[firstNumIndex].c_str()) - atoi(numbers[secendNumberIndex].c_str());
		symbols.erase(symbols.begin() + symbolIndex);
		numbers.erase(numbers.begin() + firstNumIndex, numbers.begin() + 2);
		numbers.insert(numbers.begin() + symbolIndex, to_string(flSumm));
		break;
	case '*':
		flSumm = atoi(numbers[firstNumIndex].c_str()) * atoi(numbers[secendNumberIndex].c_str());
		symbols.erase(symbols.begin() + symbolIndex);
		numbers.erase(numbers.begin() + firstNumIndex, numbers.begin() + firstNumIndex + 2);
		numbers.insert(numbers.begin() + symbolIndex, to_string(flSumm));
		break;
	case '/':
		flSumm = atoi(numbers[firstNumIndex].c_str()) / atoi(numbers[secendNumberIndex].c_str());
		symbols.erase(symbols.begin() + symbolIndex);
		numbers.erase(numbers.begin() + firstNumIndex, numbers.begin() + firstNumIndex + 2);
		numbers.insert(numbers.begin() + symbolIndex, to_string(flSumm));
		break;
	}
	return flSumm;
}
int Sum(vector<string> numbers, vector<char> symbols)//normal numbers
{
	int flSumm = 0;
	
	while (symbols.size() > 0)
	{
		int firstNumIndex = 0, secendNumberIndex = 1, symbolIndex = 0;
		for (int i = 0; i < symbols.size(); i++)
		{
			for (int i = 0; i < symbols.size(); i++) {
				if (symbols[i] == '(')
				{
					int newnum = SumInBrackets(numbers, symbols, i);
					numbers.insert(numbers.begin() + i, to_string(newnum));
					break;
				}
			}
			if (symbols[i] == '*'|| symbols[i] == '/')
			{
				symbolIndex = i;
				firstNumIndex = i;
				secendNumberIndex = i + 1;
				break;
			}
		}
		flSumm = SumNumbers(numbers,symbols,firstNumIndex,secendNumberIndex,symbolIndex);
	}
	return flSumm;
}
