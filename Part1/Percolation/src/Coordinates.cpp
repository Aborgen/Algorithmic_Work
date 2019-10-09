#include "../Coordinates.h"

namespace Part1
{
	int Coordinates::X() const
	{
		return x;
	}
	
	int Coordinates::Y() const
	{
		return y;
	}

	bool Coordinates::operator==(const Coordinates &rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	bool Coordinates::operator!=(const Coordinates &rhs) const
	{
		return !(*this == rhs);
	}

	Coordinates& Coordinates::operator+=(const Coordinates &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Coordinates Coordinates::operator+(const Coordinates &rhs) const
	{
		Coordinates temp(*this);
		return temp += rhs;
	}

	Coordinates& Coordinates::operator-=(const Coordinates &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Coordinates Coordinates::operator-(const Coordinates &rhs) const
	{
		Coordinates temp(*this);
		return temp -= rhs;
	}
}