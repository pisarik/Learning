#ifdef _DEBUG
#define _ITERATOR_DEBUG_LEVEL 1
#endif

#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <array>
#include <random>
#include <thread>

using namespace std;

template <size_t N, size_t M>
using Array2D = array<array<double, M>, N>;

template <typename T, size_t CUR_DIM, size_t... DIMS>
struct MultiArray_Impl
{
	using Nested = typename MultiArray_Impl<T, DIMS...>::type;
	using type = std::array<Nested, CUR_DIM>;
};

template <typename T, size_t DIM>
struct MultiArray_Impl<T, DIM>
{
	using type = std::array<T, DIM>;
};

template <typename T, size_t... DIMS>
using MultiArray = typename MultiArray_Impl<T, DIMS...>::type;

template <size_t N, size_t M, size_t K>
void fastConventionalConvolution(const Array2D<N, M> &img, const Array2D<K, K> &filter,
							 Array2D<N - K + 1, M - K + 1> &result) {
	for (size_t i = 0; i < N - K + 1; ++i) {
		for (size_t j = 0; j < M - K + 1; ++j) {
			double acc = 0;
			for (size_t y = i; y < i + K; ++y)
				for (size_t x = j; x < j + K; ++x) {
					acc += img[y][x] * filter[y - i][x - j];
				}
			result[i][j] = acc;
		}
	}
}

//#define WITH_IMG_ACCESS_COST
#ifdef WITH_IMG_ACCESS_COST
	const auto IMG_ACCESS_TIME_MS = 1ms;
#endif

template <size_t N, size_t M, size_t K>
void conventionalConvolution(const Array2D<N, M> &img, const Array2D<K, K> &filter, 
							 Array2D<N - K + 1, M - K + 1> &result) {
	for (size_t i = 0; i < N - K + 1; ++i) {
		for (size_t j = 0; j < M - K + 1; ++j) {
			double acc = 0;
			for (size_t y = i; y < i + K; ++y)
			for (size_t x = j; x < j + K; ++x) {
				#ifdef WITH_IMG_ACCESS_COST
					this_thread::sleep_for(IMG_ACCESS_TIME_MS);
				#endif
				acc += img[y][x] * filter[y - i][x - j];
			}
			result[i][j] = acc;
		}
	}
}

template <size_t N, size_t M, size_t K>
void multFirstConvolution(const Array2D<N, M> &img, const Array2D<K, K> &filter,
						  Array2D<N - K + 1, M - K + 1> &result) {
	MultiArray<double, N, M, K, K> mult_matrix;
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j) {
			#ifdef WITH_IMG_ACCESS_COST
				this_thread::sleep_for(IMG_ACCESS_TIME_MS);
			#endif
			double tmp = img[i][j];
			for (size_t y = 0; y < K; ++y)
			for (size_t x = 0; x < K; ++x) {
				mult_matrix[i][j][y][x] =  tmp * filter[y][x];
			}
		}
	}

	for (size_t i = 0; i < N - K + 1; ++i) {
		for (size_t j = 0; j < M - K + 1; ++j) {
			double acc = 0;
			for (size_t y = i; y < i + K; ++y)
				for (size_t x = j; x < j + K; ++x) {
					acc += mult_matrix[y][x][y - i][x - j];
				}
			result[i][j] = acc;
		}
	}
}

template <size_t N, size_t M, size_t K>
void multFirstCorrectLayoutConvolution(const Array2D<N, M> &img, const Array2D<K, K> &filter,
									   Array2D<N - K + 1, M - K + 1> &result) {
	//array<array<array<double, K*K>, M>, N> mult_matrix;
	MultiArray<double, N, M, K, K> mult_matrix;
	for (size_t i = 0; i < N; ++i)
	for (size_t j = 0; j < M; ++j) {
		#ifdef WITH_IMG_ACCESS_COST
			this_thread::sleep_for(IMG_ACCESS_TIME_MS);
		#endif
		double tmp = img[i][j];
		for (size_t y = 0; y < K; ++y)
		for (size_t x = 0; x < K; ++x) {
			mult_matrix[i > y? i - y: 0][j > x ? j - x : 0][y][x] = tmp * filter[y][x];
		}
	}

	for (size_t i = 0; i < N - K + 1; ++i) {
		for (size_t j = 0; j < M - K + 1; ++j) {
			const auto &vals = mult_matrix[i][j];
			result[i][j] = accumulate(vals.front().begin(), vals.back().end(), 0.);
		}
	}
}

template <size_t N, size_t M, size_t K>
void multFirstCorrectLayoutIflessConvolution(const Array2D<N, M> &img, const Array2D<K, K> &filter,
									   Array2D<N - K + 1, M - K + 1> &result) {
	//array<array<array<double, K*K>, M>, N> mult_matrix;
	MultiArray<double, N, M, K, K> mult_matrix;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			#ifdef WITH_IMG_ACCESS_COST
				this_thread::sleep_for(IMG_ACCESS_TIME_MS);
			#endif
			double tmp = img[i][j];
			for (int y = 0; y < K; ++y)
				for (int x = 0; x < K; ++x) {
					mult_matrix[abs(i - y)][abs(j - x)][y][x] = tmp * filter[y][x];
				}
		}

	for (size_t i = 0; i < N - K + 1; ++i) {
		for (size_t j = 0; j < M - K + 1; ++j) {
			const auto &vals = mult_matrix[i][j];
			result[i][j] = accumulate(vals.front().begin(), vals.back().end(), 0.);
		}
	}
}

template<size_t N, size_t M>
void printArray2D(const Array2D<N, M> &arr);

int main() {
	const size_t N = 1000;
	const size_t M = 1000;
	const size_t K = 10;
	Array2D<N, M> img;
	Array2D<K, K> filter;
	Array2D<N - K + 1, M - K + 1> result;
	Array2D<N - K + 1, M - K + 1> correct;


	mt19937 gen(42); //Standard mersenne_twister_engine seeded with random_device()
	uniform_real_distribution<> dis(1.0, 2.0);

	generate(img.front().begin(), img.back().end(), [&gen]()->double {
		return uniform_real_distribution<>(0, 1)(gen);
	});
	generate(filter.front().begin(), filter.back().end(), [&gen]()->double {
		return uniform_real_distribution<>(0, 1)(gen);
	});

	fastConventionalConvolution(img, filter, correct);

	auto start = chrono::high_resolution_clock::now();
	//conventionalConvolution(img, filter, result);
	//multFirstConvolution(img, filter, result);
	multFirstCorrectLayoutConvolution(img, filter, result);
	//multFirstCorrectLayoutIflessConvolution(img, filter, result);
	auto finish = chrono::high_resolution_clock::now();

	//printArray2D(img);
	//printArray2D(filter);
	//printArray2D(result);

	if (result == correct) {
		cout << "Correct!" << endl;
	}
	else {
		cout << "WRONG!!!!!!!!!!!!!!" << endl;
	}
	cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << endl;

	system("pause");
	return 0;
}

template<size_t N, size_t M>
void printArray2D(const Array2D<N, M> &arr) {
	cout << fixed; 
	for (const auto &row : arr) {
		for (const auto &elem : row) {
			cout << setw(3) << elem << " ";
		}
		cout << endl;
		cout << endl;
	}
	cout << scientific;
}