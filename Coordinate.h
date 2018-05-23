#pragma once
#include <iostream>

struct Coordinate {
	uint y,x;
	Coordinate(uint y, uint x): x(x), y(y) {}
};

inline std::ostream& operator<< (std::ostream& out, const Coordinate& c) {
	return (out << c.x << "," << c.y);
}
