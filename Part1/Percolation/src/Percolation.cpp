#include "../Percolation.h"

namespace Part1
{
	// Subtract one, as Coordinates within Site are 0-based.
	Percolation::Percolation(int n, int m, DataStructure::UnionFind &UF) : maxRowIdx(n - 1), maxColumnIdx(m - 1), UF(UF)
	{
		constructGrid(n, m);
		initAnchors();
	}

	void Percolation::open(const Coordinates &coordinates)
	{
		if (isOpen(coordinates)) {
			return;
		}

		Site& site = getSite(coordinates);
		site.open();
		openSites++;
		
		// Once a new site is opened, attempt to join it with those around it.
		joinAdjacentSites(site);
	}

	void Percolation::joinAdjacentSites(const Site &site)
	{
		// Run the code block within the for loop for each cardinal direction:
		// ABOVE, BELOW, LEFT, and RIGHT.
		const std::vector<Direction> directions = { Direction::ABOVE, Direction::BELOW, Direction::LEFT, Direction::RIGHT };
		const Coordinates coordinates = site.getCoordinates();
		for (Direction direction : directions) {
			// std::optional<Site&> . . . optional reference is not in standard, as of c++17
			std::optional<Site> maybeSite = adjacent(coordinates, direction);
			if (maybeSite.has_value()) {
				Site adjacentSite = maybeSite.value();
				if (adjacentSite.getStatus() == Site::Status::OPEN) {
					UF.join(site.getId(), adjacentSite.getId());
				}
			}
		}
	}

	std::optional<Site> Percolation::adjacent(const Coordinates &coordinates, Direction direction)
	{
		switch (direction) {
			case Direction::ABOVE:
			{
				if (coordinates.Y() == 0) {
					return topAnchor;
				}

				Coordinates above = coordinates - Coordinates(0, 1);
				return getSite(above);
			}
			case Direction::BELOW:
			{
				if (coordinates.Y() == maxColumnIdx) {
					return bottomAnchor;
				}

				Coordinates below = coordinates + Coordinates(0, 1);
				return getSite(below);
			}
			case Direction::LEFT:
			{
				// There is no Site to the left.
				if (coordinates.X() == 0) {
					return std::nullopt;
				}

				Coordinates left = coordinates - Coordinates(1, 0);
				return getSite(left);
			}
			case Direction::RIGHT:
			{
				// There is no Site to the right.
				if (coordinates.X() == maxRowIdx) {
					return std::nullopt;
				}

				Coordinates right = coordinates + Coordinates(1, 0);
				return getSite(right);
			}
			default:
				throw std::invalid_argument("Unrecognized direction given");
			}
	}

	bool Percolation::isOpen(const Coordinates &coordinates)
	{
		return getSite(coordinates).getStatus() == Site::Status::OPEN;
	}

	bool Percolation::isFull(const Coordinates &coordinates)
	{
		return !isOpen(coordinates);
	}

	int Percolation::numberOfOpenSites()
	{
		return openSites;
	}

	// N x M grid
	void Percolation::constructGrid(int rows, int columns)
	{
		Grid grid;
		grid.reserve(rows);
		int id = 0;
		for (int i = 0; i < rows; i++) {
			std::vector<Site> sites;
			sites.reserve(columns);
			for (int j = 0; j < columns; j++) {
				sites.push_back(Site(i, j, id));
				id++;
			}

			grid.push_back(sites);
		}

		this->grid = grid;
	}

	void Percolation::initAnchors()
	{
		//Coordinates lastPosition = grid.back().back().getCoordinates();
		//Coordinates foo;
		//if (lastPosition.X() == n) {
		//	foo = Coordinates(lastPosition.Y() + 1, 0)
		//}
		//else {
		//	foo = lastPosition + Coordinates(0, 1);
		//}

		// Default Coordinates is set to meaningless numbers.
		// The only thing that matters is their ids, which correspond to nodes in the union-find data structure.
		UF.push();
		topAnchor = Site(Coordinates(-1, -1), UF.getLastId() - 1, Site::Status::OPEN);

		UF.push();
		bottomAnchor = Site(Coordinates(-1, -1), UF.getLastId() - 1, Site::Status::OPEN);
	}

	Site& Percolation::getSite(const Coordinates &coordinates)
	{
		return grid[coordinates.X()][coordinates.Y()];
	}

	bool Percolation::percolates()
	{
		return UF.anyConnection(topAnchor.getId(), bottomAnchor.getId());
	}
}