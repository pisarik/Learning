#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Reverse {
public:
	Reverse(string str) : str(str) {}
	Reverse(int number) {
		stringstream cast_stream;
		cast_stream << number;
		str = cast_stream.str();
	}

	const string& reverse() {
		std::reverse(str.begin(), str.end());
		return str;
	}

	const string& getString() const {
		return str;
	}

private:
	string str;
};

int main() {
	Reverse r_number(12345);
	Reverse r_string("abcde");

	cout << r_number.getString() << " " << r_number.reverse() << endl;
	cout << r_string.getString() << " " << r_string.reverse() << endl;

	system("pause");
	return 0;
}