#ifndef SITE_H
#pragma once

#include "Coordinates.h"
namespace Part1
{
	class Site
	{
	public:
		enum class Status
		{
			OPEN,
			FULL
		};

		Site() {};
		// These two constructors call the one below.
		Site(int row, int column, int id) : Site(Coordinates(row, column), id, Status::FULL) {};
		Site(const Coordinates &coordinates, int id) : Site(coordinates, id, Status::FULL) {};
		
		Site(const Coordinates &coordinates, int id, Status status) : coordinates(coordinates), id(id), status(status) {};
		Status getStatus() const;
		int getId() const;
		const Coordinates& getCoordinates() const;
		void open();
		void close();

	private:
		int id;
		Status status;
		Coordinates coordinates;
	};
}

#endif // !SITE_H
