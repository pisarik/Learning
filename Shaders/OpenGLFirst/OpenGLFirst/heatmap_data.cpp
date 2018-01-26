#include "heatmap_data.hpp"

#include <iostream>

std::istream& operator >> (std::istream &in, HeatmapData &sd) {
	in >> sd.rows >> sd.cols >> sd.channels;
	std::copy(std::istream_iterator<MAP_TYPE>(in), std::istream_iterator<MAP_TYPE>(),
			  std::back_inserter(sd.data));
	return in;
}

std::ostream& operator << (std::ostream &out, const HeatmapData &sd) {
	out << sd.rows << sd.cols << sd.channels;
	std::copy(sd.data.begin(), sd.data.end(),
			  std::ostream_iterator<MAP_TYPE>(out));
	return out;
}

void HeatmapData::read(std::istream &in){
	in.read(reinterpret_cast<char*>(&rows), sizeof(rows));
	in.read(reinterpret_cast<char*>(&cols), sizeof(cols));
	in.read(reinterpret_cast<char*>(&channels), sizeof(channels));
	
	data.resize(rows*cols*channels);
	in.read(reinterpret_cast<char*>(data.data()), data.size() * sizeof(MAP_TYPE));
}

void HeatmapData::write(std::ostream &out) const{
	out.write(reinterpret_cast<const char*>(&rows), sizeof(rows));
	out.write(reinterpret_cast<const char*>(&cols), sizeof(cols));
	out.write(reinterpret_cast<const char*>(&channels), sizeof(channels));

	out.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(MAP_TYPE));
}
