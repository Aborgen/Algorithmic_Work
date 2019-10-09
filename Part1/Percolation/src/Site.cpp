#include "..\Site.h"

namespace Part1
{
	void Site::close()
	{
		status = Status::FULL;
	}

	void Site::open()
	{
		status = Status::OPEN;
	}

	Site::Status Site::getStatus() const
	{
		return status;
	}

	int Site::getId() const
	{
		return id;
	}

	const Coordinates& Site::getCoordinates() const
	{
		return coordinates;
	}

}