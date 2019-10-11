#ifndef PERCOLATIONSTATS_H
#define PERCOLATIONSTATS_H
#pragma once

#include <vector>
#include "Percolation.h"

namespace Part1
{
	class PercolationStats
	{
	public:
		enum class Level
		{
			HIGH,
			LOW
		};

		PercolationStats(int n, int trials);
		double getMean();
		double getStandardDeviation();
		void runTrials();

		// HIGH/LOW endpoint of 95% confidence interval
		double confidence(Level level);

	private:
		std::vector<double> openedSitePercentages;
		const int trials;
		const int n;
		const int totalSites;
		double mean;
		double standardDeviation;
		void calculateStats();
		void calculateMean();
		void calculateStandardDeviation();
		int freshTrial();
	};
}

#endif // !PERCOLATIONSTATS_H