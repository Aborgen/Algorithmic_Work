#ifndef COORDINATES_H
#define COORDINATES_H
#pragma once

namespace Part1
{
	class Coordinates
	{
	public:
		Coordinates() {}
		Coordinates(int x, int y) : x(x), y(y) {};
		int X() const;
		int Y() const;
		bool operator==(const Coordinates &rhs) const;
		bool operator!=(const Coordinates &rhs) const;
		Coordinates& operator+=(const Coordinates &rhs);
		Coordinates operator+(const Coordinates &rhs) const;
		Coordinates& operator-=(const Coordinates &rhs);
		Coordinates operator-(const Coordinates &rhs) const;

	private:
		int x;
		int y;
	};
}
#endif // !COORDINATES_H
