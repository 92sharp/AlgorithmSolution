#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int second = 0;
	for (auto c : str) {
		if (c >= 'A' && c <= 'C')
			second += 3;
		else if (c >= 'D' && c <= 'F')
			second += 4;
		else if (c >= 'G' && c <= 'I')
			second += 5;
		else if (c >= 'J' && c <= 'L')
			second += 6;
		else if (c >= 'M' && c <= 'O')
			second += 7;
		else if (c >= 'P' && c <= 'S')
			second += 8;
		else if (c >= 'T' && c <= 'V')
			second += 9;
		else if (c >= 'W' && c <= 'Z')
			second += 10;
	}

	cout << second;

	return 0;
}