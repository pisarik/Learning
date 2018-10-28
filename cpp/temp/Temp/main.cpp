#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

using namespace std;
#define _SCL_SECURE_NO_WARNINGS

template<typename T>
inline T fastMax(const T a, const T b)
{
	return (a > b ? a : b);
}

template<typename T>
inline T fastMaxRef(const T &a, const T &b)
{
	return (a > b ? a : b);
}

template<typename T>
inline int intRound(const T a)
{
	return int(a + 0.5f);
}

inline float floatAnd(float &x, const int mask) noexcept {
	*reinterpret_cast<int*>(&x) &= -mask;
	return x;
}

inline float floatAnd(float &&x, const int mask) noexcept{
	*reinterpret_cast<int*>(&x) &= -mask;
	return x;
}

using uint = unsigned int;

using MAP_TYPE = float;
void nonMaximumSuppression(MAP_TYPE *map, const uint rows, const uint cols, const MAP_TYPE threshold) {
	const uint sz = rows*cols;
	char *local_max = (char*)malloc(sz);

	//top corner elems
	local_max[0] = map[0] > threshold &&
		map[0] >= map[1] &&
		map[0] >= map[cols] &&
		map[0] >= map[cols + 1];

	local_max[cols - 1] = map[cols - 1] > threshold &&
		map[cols - 1] >= map[cols - 2] &&
		map[cols - 1] >= map[2 * cols - 2] &&
		map[cols - 1] >= map[2 * cols - 1];

	//top row
	for (uint j = 1; j < cols - 1; j++) {
		local_max[j] = map[j] > threshold &&
			map[j] >= map[j - 1] &&
			map[j] >= map[cols + j - 1] &&
			map[j] >= map[cols + j] &&
			map[j] >= map[cols + j + 1] &&
			map[j] >= map[j + 1];
	}

	//middle
	for (uint i = 1; i < rows - 1; i++) {
		uint offset = i * cols;
		for (uint j = 1; j < cols - 1; j++) {
			local_max[offset + j] = map[offset + j] > threshold &&
				map[offset + j] >= map[offset + j - 1] &&
				map[offset + j] >= map[offset - cols + j - 1] &&
				map[offset + j] >= map[offset - cols + j] &&
				map[offset + j] >= map[offset - cols + j + 1] &&
				map[offset + j] >= map[offset + j + 1] &&
				map[offset + j] >= map[offset + cols + j + 1] &&
				map[offset + j] >= map[offset + cols + j] &&
				map[offset + j] >= map[offset + cols + j - 1];

		}
	}

	//last row
	uint lstrow = (rows - 1)*cols;
	for (uint j = 1; j < cols - 1; j++) {
		local_max[lstrow + j] = map[lstrow + j] > threshold &&
			map[lstrow + j] >= map[lstrow + j - 1] &&
			map[lstrow + j] >= map[lstrow - cols + j - 1] &&
			map[lstrow + j] >= map[lstrow - cols + j] &&
			map[lstrow + j] >= map[lstrow - cols + j + 1] &&
			map[lstrow + j] >= map[lstrow + j + 1];
	}

	//bottom corners
	local_max[lstrow] = map[lstrow] > threshold &&
		map[lstrow] >= map[lstrow + 1] &&
		map[lstrow] >= map[lstrow - cols] &&
		map[lstrow] >= map[lstrow - cols + 1];

	local_max[lstrow + cols - 1] = map[lstrow + cols - 1] > threshold &&
		map[lstrow + cols - 1] >= map[lstrow + cols - 2] &&
		map[lstrow + cols - 1] >= map[lstrow - 1] &&
		map[lstrow + cols - 1] >= map[lstrow - 2];


	//left column
	for (uint i = 1; i < rows - 1; i++) {
		uint cur = i * cols;
		local_max[cur] = map[cur] > threshold &&
			map[cur] >= map[cur - cols] &&
			map[cur] >= map[cur - cols + 1] &&
			map[cur] >= map[cur + 1] &&
			map[cur] >= map[cur + cols + 1] &&
			map[cur] >= map[cur + cols];
	}

	//right column
	for (uint i = 1; i < rows - 1; i++) {
		uint cur = (i + 1) * cols - 1;
		local_max[cur] = map[cur] > threshold &&
			map[cur] >= map[cur - cols] &&
			map[cur] >= map[cur - cols - 1] &&
			map[cur] >= map[cur - 1] &&
			map[cur] >= map[cur + cols - 1] &&
			map[cur] >= map[cur + cols];
	}

	std::transform(local_max, local_max + sz, map, map,
				   [](const char& mask, const MAP_TYPE &val)->MAP_TYPE {
		return mask * val;
	});

	free(local_max);
}

void nonMaximumSuppressionBitwise(MAP_TYPE *map, const uint rows, const uint cols, const MAP_TYPE threshold) {
	const uint sz = rows*cols;
	char* local_max = (char*) malloc(sz);

	//top corner elems
	local_max[0] = -(map[0] > threshold &&
		map[0] >= map[1] &&
		map[0] >= map[cols] &&
		map[0] >= map[cols + 1]);

	local_max[cols - 1] = -(map[cols - 1] > threshold &&
		map[cols - 1] >= map[cols - 2] &&
		map[cols - 1] >= map[2 * cols - 2] &&
		map[cols - 1] >= map[2 * cols - 1]);

	//top row
	for (uint j = 1; j < cols - 1; j++) {
		local_max[j] = -(map[j] > threshold &&
			map[j] >= map[j - 1] &&
			map[j] >= map[cols + j - 1] &&
			map[j] >= map[cols + j] &&
			map[j] >= map[cols + j + 1] &&
			map[j] >= map[j + 1]);
	}

	//middle
	for (uint i = 1; i < rows - 1; i++) {
		uint offset = i * cols;
		for (uint j = 1; j < cols - 1; j++) {
			local_max[offset + j] = -(map[offset + j] > threshold &&
				map[offset + j] >= map[offset + j - 1] &&
				map[offset + j] >= map[offset - cols + j - 1] &&
				map[offset + j] >= map[offset - cols + j] &&
				map[offset + j] >= map[offset - cols + j + 1] &&
				map[offset + j] >= map[offset + j + 1] &&
				map[offset + j] >= map[offset + cols + j + 1] &&
				map[offset + j] >= map[offset + cols + j] &&
				map[offset + j] >= map[offset + cols + j - 1]);

		}
	}

	//last row
	uint lstrow = (rows - 1)*cols;
	for (uint j = 1; j < cols - 1; j++) {
		local_max[lstrow + j] = -(map[lstrow + j] > threshold &&
			map[lstrow + j] >= map[lstrow + j - 1] &&
			map[lstrow + j] >= map[lstrow - cols + j - 1] &&
			map[lstrow + j] >= map[lstrow - cols + j] &&
			map[lstrow + j] >= map[lstrow - cols + j + 1] &&
			map[lstrow + j] >= map[lstrow + j + 1]);
	}

	//bottom corners
	local_max[lstrow] = -(map[lstrow] > threshold &&
		map[lstrow] >= map[lstrow + 1] &&
		map[lstrow] >= map[lstrow - cols] &&
		map[lstrow] >= map[lstrow - cols + 1]);

	local_max[lstrow + cols - 1] = -(map[lstrow + cols - 1] > threshold &&
		map[lstrow + cols - 1] >= map[lstrow + cols - 2] &&
		map[lstrow + cols - 1] >= map[lstrow - 1] &&
		map[lstrow + cols - 1] >= map[lstrow - 2]);


	//left column
	for (uint i = 1; i < rows - 1; i++) {
		uint cur = i * cols;
		local_max[cur] = -(map[cur] > threshold &&
			map[cur] >= map[cur - cols] &&
			map[cur] >= map[cur - cols + 1] &&
			map[cur] >= map[cur + 1] &&
			map[cur] >= map[cur + cols + 1] &&
			map[cur] >= map[cur + cols]);
	}

	//right column
	for (uint i = 1; i < rows - 1; i++) {
		uint cur = (i + 1) * cols - 1;
		local_max[cur] = -(map[cur] > threshold &&
			map[cur] >= map[cur - cols] &&
			map[cur] >= map[cur - cols - 1] &&
			map[cur] >= map[cur - 1] &&
			map[cur] >= map[cur + cols - 1] &&
			map[cur] >= map[cur + cols]);
	}

	int *it = reinterpret_cast<int*>(map);
	int *end = it + sz - 1;
	char *mask_it = local_max + sz - 1;
	while (it != end) {
		*(end--) &= (int)(*mask_it);
		mask_it--;
	}
	*it &= (int)(*mask_it);
	free(local_max);
}

void nonMaximumSuppressionInplace(MAP_TYPE *map, const uint rows, const uint cols, const MAP_TYPE threshold) {
	//top corner elems
	floatAnd(map[0], map[0] > threshold &&
					 map[0] >= map[1] &&
					 map[0] >= map[cols] &&
					 map[0] >= map[cols + 1]);

	floatAnd(map[cols - 1], map[cols - 1] > threshold &&
							map[cols - 1] >= map[cols - 2] &&
							map[cols - 1] >= map[2 * cols - 2] &&
							map[cols - 1] >= map[2 * cols - 1]);

	//top row
	for (uint j = 1; j < cols - 1; j++) {
		floatAnd(map[j], map[j] > threshold &&
						 map[j] >= map[j - 1] &&
						 map[j] >= map[cols + j - 1] &&
						 map[j] >= map[cols + j] &&
						 map[j] >= map[cols + j + 1] &&
						 map[j] >= map[j + 1]);
	}

	//middle
	for (uint i = 1; i < rows - 1; i++) {
		uint offset = i * cols;
		for (uint j = 1; j < cols - 1; j++) {
			floatAnd(map[offset + j], map[offset + j] > threshold &&
									  map[offset + j] >= map[offset + j - 1] &&
									  map[offset + j] >= map[offset - cols + j - 1] &&
									  map[offset + j] >= map[offset - cols + j] &&
									  map[offset + j] >= map[offset - cols + j + 1] &&
									  map[offset + j] >= map[offset + j + 1] &&
									  map[offset + j] >= map[offset + cols + j + 1] &&
									  map[offset + j] >= map[offset + cols + j] &&
									  map[offset + j] >= map[offset + cols + j - 1]);

		}
	}

	//last row
	uint lstrow = (rows - 1)*cols;
	for (uint j = 1; j < cols - 1; j++) {
		floatAnd(map[lstrow + j], map[lstrow + j] > threshold &&
								  map[lstrow + j] >= map[lstrow + j - 1] &&
								  map[lstrow + j] >= map[lstrow - cols + j - 1] &&
								  map[lstrow + j] >= map[lstrow - cols + j] &&
								  map[lstrow + j] >= map[lstrow - cols + j + 1] &&
								  map[lstrow + j] >= map[lstrow + j + 1]);
	}

	//bottom corners
	floatAnd(map[lstrow], map[lstrow] > threshold &&
						  map[lstrow] >= map[lstrow + 1] &&
						  map[lstrow] >= map[lstrow - cols] &&
						  map[lstrow] >= map[lstrow - cols + 1]);

	floatAnd(map[lstrow + cols - 1], map[lstrow + cols - 1] > threshold &&
									 map[lstrow + cols - 1] >= map[lstrow + cols - 2] &&
									 map[lstrow + cols - 1] >= map[lstrow - 1] &&
									 map[lstrow + cols - 1] >= map[lstrow - 2]);


	//left column
	for (uint i = 1; i < rows - 1; i++) {
		uint cur = i * cols;
		floatAnd(map[cur], map[cur] > threshold &&
						   map[cur] >= map[cur - cols] &&
						   map[cur] >= map[cur - cols + 1] &&
						   map[cur] >= map[cur + 1] &&
						   map[cur] >= map[cur + cols + 1] &&
						   map[cur] >= map[cur + cols]);
	}

	//right column
	for (uint i = 1; i < rows - 1; i++) {
		uint cur = (i + 1) * cols - 1;
		floatAnd(map[cur], map[cur] > threshold &&
						   map[cur] >= map[cur - cols] &&
						   map[cur] >= map[cur - cols - 1] &&
						   map[cur] >= map[cur - 1] &&
						   map[cur] >= map[cur + cols - 1] &&
						   map[cur] >= map[cur + cols]);
	}
}

void nonMaximumSuppressionBlock(MAP_TYPE *map, uint rows, uint cols, MAP_TYPE threshold, uint block_size = 16) {
	std::vector<char> local_max(rows*cols, 0);

	//top corner elems
	local_max[0] = map[0] > threshold &&
		map[0] >= map[1] &&
		map[0] >= map[cols] &&
		map[0] >= map[cols + 1];

	local_max[cols - 1] = map[cols - 1] > threshold &&
		map[cols - 1] >= map[cols - 2] &&
		map[cols - 1] >= map[2 * cols - 2] &&
		map[cols - 1] >= map[2 * cols - 1];

	//top row
	for (uint j = 1; j < cols - 1; j++) {
		local_max[j] = map[j] > threshold &&
			map[j] >= map[j - 1] &&
			map[j] >= map[cols + j - 1] &&
			map[j] >= map[cols + j] &&
			map[j] >= map[cols + j + 1] &&
			map[j] >= map[j + 1];
	}

	//middle
	uint blocks_rows = (rows - 2) / block_size + 1;
	uint blocks_cols = (cols - 2) / block_size + 1;

	for (uint bl_i = 0; bl_i < blocks_rows; bl_i++)
	{
		uint block_beg_row = bl_i * block_size + 1;
		uint block_end_row = min((bl_i + 1) * block_size + 1, rows - 1);
		for (uint bl_j = 0; bl_j < blocks_cols; bl_j++) {
			uint block_beg_col = bl_j * block_size + 1;
			uint block_end_col = min((bl_j + 1) * block_size + 1, cols - 1);
			for (uint i = block_beg_row; i < block_end_row; i++) {
				uint offset = i * cols;
				for (uint j = block_beg_col; j < block_end_col; j++) {
					local_max[offset + j] = map[offset + j] > threshold &&
						map[offset + j] >= map[offset + j - 1] &&
						map[offset + j] >= map[offset - cols + j - 1] &&
						map[offset + j] >= map[offset - cols + j] &&
						map[offset + j] >= map[offset - cols + j + 1] &&
						map[offset + j] >= map[offset + j + 1] &&
						map[offset + j] >= map[offset + cols + j + 1] &&
						map[offset + j] >= map[offset + cols + j] &&
						map[offset + j] >= map[offset + cols + j - 1];

				}
			}
		}
	}

	//last row
	uint lstrow = (rows - 1)*cols;
	for (uint j = 1; j < cols - 1; j++) {
		local_max[lstrow + j] = map[lstrow + j] > threshold &&
			map[lstrow + j] >= map[lstrow + j - 1] &&
			map[lstrow + j] >= map[lstrow - cols + j - 1] &&
			map[lstrow + j] >= map[lstrow - cols + j] &&
			map[lstrow + j] >= map[lstrow - cols + j + 1] &&
			map[lstrow + j] >= map[lstrow + j + 1];
	}

	//bottom corners
	local_max[lstrow] = map[lstrow] > threshold &&
		map[lstrow] >= map[lstrow + 1] &&
		map[lstrow] >= map[lstrow - cols] &&
		map[lstrow] >= map[lstrow - cols + 1];

	local_max[lstrow + cols - 1] = map[lstrow + cols - 1] > threshold &&
		map[lstrow + cols - 1] >= map[lstrow + cols - 2] &&
		map[lstrow + cols - 1] >= map[lstrow - 1] &&
		map[lstrow + cols - 1] >= map[lstrow - 2];


	//left column
	for (uint i = 1; i < rows - 1; i++) {
		uint cur = i * cols;
		local_max[cur] = map[cur] > threshold &&
			map[cur] >= map[cur - cols] &&
			map[cur] >= map[cur - cols + 1] &&
			map[cur] >= map[cur + 1] &&
			map[cur] >= map[cur + cols + 1] &&
			map[cur] >= map[cur + cols];
	}

	//right column
	for (uint i = 1; i < rows - 1; i++) {
		uint cur = (i + 1) * cols - 1;
		local_max[cur] = map[cur] > threshold &&
			map[cur] >= map[cur - cols] &&
			map[cur] >= map[cur - cols - 1] &&
			map[cur] >= map[cur - 1] &&
			map[cur] >= map[cur + cols - 1] &&
			map[cur] >= map[cur + cols];
	}

	std::transform(local_max.begin(), local_max.end(), map, map,
				   [](const char& mask, const MAP_TYPE &val)->MAP_TYPE {
		return mask * val;
	});

}


void nonMaximumSuppressionSlow(MAP_TYPE *map, uint rows, uint cols, MAP_TYPE threshold) {
	std::vector<char> local_max(rows*cols, 0);

	vector<pair<int, int>> shifts = { { -1, 0 },{ -1, -1 },{ 0, -1 },{ 1, -1 },{ 1, 0 },{ 1, 1 },{ 0, 1 },{ -1, 1 } };
	for (int i = 0; i < rows; i++) {
		uint offset = i * cols;
		for (int j = 0; j < cols; j++) {
			if (map[offset + j] > threshold) {
				local_max[offset + j] = 1;
				for (auto &[si, sj] : shifts) {
					uint cur_i = i + si;
					uint cur_j = j + sj;

					if (cur_i < rows && cur_j < cols) {
						local_max[offset + j] &= map[offset + j] >= map[cur_i*cols + cur_j];
					}
				}
			}
		}
	}

	std::transform(local_max.begin(), local_max.end(), map, map,
				   [](const char& mask, const MAP_TYPE &val)->MAP_TYPE {
		return mask * val;
	});
}

class kek {
public:
	int x[3];
};

int main() {
	int x = -10;
	cout << x << endl;
	char m = -1;
	cout << (x&m) << endl;

	uint rows = 10000;
	uint cols = 10000;
	vector<MAP_TYPE> arr(rows*cols, 0);
	srand(42);
	//std::generate(arr.begin(), arr.end(), []()->int { return rand() / (MAP_TYPE)rand(); });

	/*vector<char> mask(rows*cols, 0);
	std::generate(mask.begin(), mask.end(), []()->int { return rand() % 2; });*/
	
	/*for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i*cols + j] << " ";
		}
		cout << endl;
	}*/

	double sum = 0;
	auto start = chrono::high_resolution_clock::now();
	//nonMaximumSuppressionSlow(arr.data(), rows, cols, 5);
	//nonMaximumSuppressionBitwise(arr.data(), rows, cols, 5);
	//nonMaximumSuppression(arr.data(), rows, cols, 5);
	//nonMaximumSuppressionInplace(arr.data(), rows, cols, 5);
	size_t offset = 1;
	size_t range = 30;
	for (size_t n = offset; n < 30; ++n) {
		for (size_t m = 2 * n + 1; m < 30; ++m) {
			if (size_t(pow(2, m) + 3) % (size_t(pow(4, n) - 9)) == 0) {
				auto x = size_t(pow(2, m) + 3) / (size_t(pow(4, n) - 9));
				cout << x << " " << n << " " << m << " " << size_t(pow(2, m) + 3) << " " << 9*x + 3 << "\n";
			}
		}
	}

	//cout << floatAnd(0.3f, 1) << endl;

	auto finish = chrono::high_resolution_clock::now();

	//cout << endl;
	//for (int i = 0; i < rows; i++) {
	//	for (int j = 0; j < cols; j++) {
	//		cout << arr[i*cols + j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << count(arr.begin(), arr.end(), 0) << endl;
	cout << sum << endl;
	cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << endl;
	system("pause");
	return 0;
}