#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	vector<string> words;
	string word;
	stringstream sstream(str);

	while (getline(sstream, word, ' ')) {
		if (word == "") 
			continue;
		words.push_back(word);
	}

	int count = words.size();

	cout << count;

	return 0;
}