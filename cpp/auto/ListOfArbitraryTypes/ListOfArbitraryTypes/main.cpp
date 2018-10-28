#include <variant>
#include <vector>
#include <iostream>
#include <string>
#include <any>
#include <type_traits>

using namespace std;

using Object = variant<int, string, double, vector<int>>;

/*template <class... Args>
struct type_list
{
	template <std::size_t N>
	using type = typename std::tuple_element<N, std::tuple<Args...>>::type;
};*/

ostream& operator<<(ostream &out, const vector<int> &v) {
	for (const auto &e : v) {
		out << e << " ";
	}
	return out;
}

int main() {
	vector<Object> vec = { string("kek"), 1, vector<int>{3, 5, 2, 1} };
	
	vec.emplace_back(10);
	vec.emplace_back(35.3);
	vec.emplace_back(string("hello"));

	variant<int, string> x = "kek";
	x = 3;

	for (auto& elem : vec) {
		visit([](auto &e) { cout << e << endl; }, elem);
	}

	system("pause");
	return 0;
}

/*#include <variant>
#include <iostream>
#include <string>

//Resource acqusition is initialization | RAII
#include <memory>
std::make_unique<

using namespace std;

int main() {
	auto func = [](auto x1, auto x2)->auto{
		if constexpr(is_same<decltype(x1), int>::value) {
			return x2 + x1;
		}
		else {
			return string("not int");
		}
	};

	int choice1, choice2;
	cin >> choice1;
	cin >> choice2;

	std::any x = 1;

	if (choice1 == 3) {
		x = 3;
	}
	else {
		x = "string";
	}

	cout << any_cast<string>(x) << endl;

	if (choice1 > choice2) {
		cout << func(choice1, choice2) << endl;
	}
	else {
		cout << func("123", choice1) << endl;
	}
}*/

/*using Object = variant<int, double, string>;

int main() {
	auto func = [](auto x1, auto x2)->auto{
		if constexpr(is_same<decltype(x1), int>::value) {
			return x2;
		}
		return x1;
	};

	auto a = 3;
	auto b = 0.5;

	int choice;
	cin >> choice;
	if (choice > 10) {
		cout << func(a, a) << endl;
	}
	else {
		cout << func(b, b) << endl;
	}


	cout << func(3, 5) << endl;
	cout << func(3.5, 6) << endl;
	cout << func(string("kek"), string("lol")) << endl;

	system("pause");
}*/