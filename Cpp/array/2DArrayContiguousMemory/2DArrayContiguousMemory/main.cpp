#include <array>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

template<int N, int M>
using Array2D = array<array<int, M>, N>;

template<int N, int M>
void printArray2D(const Array2D<N, M> &arr);

int main() {
	const int N = 5;
	const int M = 5;
	Array2D<N, M> arr;

	generate(arr.front().begin(), arr.back().end(), [M]()->int {
														return rand() % M;
													});

	printArray2D(arr);

	auto[a, b] = minmax_element(arr.front().begin(), arr.back().end());

	cout << "Swap minimum and maximum: " << *a << " " << *b << endl << endl;

	iter_swap(a, b);
	printArray2D(arr);

	system("pause");
	return 0;
}

template<int N, int M>
void printArray2D(const Array2D<N, M> &arr) {
	for (const auto &row : arr) {
		for (const auto &elem : row) {
			cout << std::setw(3) << elem;
		}
		cout << endl;
		cout << endl;
	}
}