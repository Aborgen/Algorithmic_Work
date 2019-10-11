#include <algorithm>
#include <numeric>
#include <random>
#include "../PercolationStats.h"
#include "../../DataStructure/WeightedQuickUnionUFComp.h"
#include "../../DataStructure/QuickFindUF.h"

namespace Part1
{
	PercolationStats::PercolationStats(int n, int trials) : n(n), trials(trials), totalSites(n*n)
	{
		openedSitePercentages.reserve(trials);
	}

	double PercolationStats::getMean()
	{
		return mean;
	}

	double PercolationStats::getStandardDeviation()
	{
		return standardDeviation;
	}

	void PercolationStats::runTrials()
	{
		for (int i = 0; i < trials; i++) {
			double openSites = freshTrial();
			openedSitePercentages.push_back(openSites / totalSites);
		}

		calculateStats();
	}

	int PercolationStats::freshTrial()
	{
		// Create a randomized vector of positions
		std::vector<int> positions(totalSites);
		std::iota(positions.begin(), positions.end(), 0);
		std::random_device r;
		std::mt19937 engine{ r() };
		std::shuffle(positions.begin(), positions.end(), engine);

		DataStructure::WeightedQuickUnionUFComp UF(totalSites);
		Percolation p(n, UF);
		while (!p.percolates()) {
			int idx = positions.back();
			positions.pop_back();

			int y = static_cast<int>(idx / n);
			int x = static_cast<int>(idx % n);
			p.open(Coordinates(x, y));
		}

		return p.numberOfOpenSites();
	}

	void PercolationStats::calculateStats()
	{
		calculateMean();
		calculateStandardDeviation();
	}

	void PercolationStats::calculateMean()
	{
		double sum = std::accumulate(openedSitePercentages.begin(), openedSitePercentages.end(), 0.0);
		mean = sum / openedSitePercentages.size();
	}

	// From StackOverflow user Josh griefer: https://stackoverflow.com/a/12405793
	void PercolationStats::calculateStandardDeviation()
	{
		double accumulation = 0.0;
		std::for_each(openedSitePercentages.begin(), openedSitePercentages.end(), [&](const double d) {
			accumulation += (d - mean) * (d - mean);
		});

		standardDeviation = std::sqrt(accumulation / (openedSitePercentages.size() - 1));
	}

	double PercolationStats::confidence(Level level)
	{
		int sign = level == Level::HIGH ? +1 : -1;
		return mean + sign * (1.96 * standardDeviation) / std::sqrt(trials);
	}
}