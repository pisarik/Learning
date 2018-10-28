#ifndef HEATMAP_DATA_HPP
#define HEATMAP_DATA_HPP
#include <vector>
#include <fstream>
#include <iterator>

using MAP_TYPE = float;

struct HeatmapData{
	size_t rows;
	size_t cols;
	size_t channels;
	std::vector<MAP_TYPE> data;

	void read(std::istream &in);
	void write(std::ostream &out) const;
};

std::istream& operator >> (std::istream &in, HeatmapData &inp_data);
std::ostream& operator << (std::ostream &out, const HeatmapData &inp_data);

#endif // HEATMAP_DATA_HPP