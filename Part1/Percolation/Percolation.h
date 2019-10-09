#ifndef PERCOLATION_H
#define PERCOLATION_H
#pragma once

#include <optional>
#include <vector>
#include "Coordinates.h"
#include "Site.h"
#include "../DataStructure/UnionFind.h"

namespace Part1
{
	class Percolation {
	public:
		typedef std::vector<std::vector<Site>> Grid;
		// creates n-by-n grid, with all sites initially blocked.
		// UF is an abstract class passed by reference for purposes of dependency injection.
		Percolation(int n, DataStructure::UnionFind &UF) : Percolation(n, n, UF) {};
		Percolation(int n, int m, DataStructure::UnionFind &UF);

		// Sets a specific Site's status to OPEN, if not already so.
		void open(const Coordinates &coordinates);

		// A Site can be in either an OPEN or FULL state.
		bool isOpen(const Coordinates &coordinates);
		bool isFull(const Coordinates &coordinates);

		// Returns the number of open Sites.
		int numberOfOpenSites();

		// Is there a connection between topAnchor and bottomAnchor?
		bool percolates();

	private:
		enum class Direction
		{
			ABOVE,
			BELOW,
			LEFT,
			RIGHT
		};

		Site topAnchor;
		Grid grid;
		Site bottomAnchor;
		DataStructure::UnionFind &UF;
		const int maxRowIdx;
		const int maxColumnIdx;
		int openSites{ 0 };
		void constructGrid(int rows, int columns);
		void initAnchors();

		// Returns a reference to the Site at the specified coordinate pair.
		Site& getSite(const Coordinates &coordinates);

		// Obtain adjacent Sites of Site.
		std::optional<Site> adjacent(const Coordinates &coordinates, Direction direction);

		// Attempts to join sites adjacent to provided site. Two sites are joinable if both are open.
		void joinAdjacentSites(const Site &site);
	};
}
#endif // !PERCOLATION_H
