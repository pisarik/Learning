#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

using namespace std;

void printMatches(const string &text, const string &pattern) {
	regex base_regex(pattern);
	sregex_iterator it(text.begin(), text.end(), base_regex);
	while (it != sregex_iterator())
		cout << (it++)->str() << endl;
}

int main() {
	string text;
	{
		stringstream tmp;
		tmp << ifstream("text.txt").rdbuf();
		text = tmp.str();
	}

	printMatches(text, R"(\w[^.!]+?\?)"); // que sentences
	printMatches(text, R"(\w[^.?]+?!)");  // excl sentences

	system("pause");
	return 0;
}