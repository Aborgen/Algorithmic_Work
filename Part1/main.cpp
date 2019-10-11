#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include "Percolation/PercolationStats.h"

using namespace Part1;
int main(int argc, char *argv[])
{
	// Defaults
	int n = 600;
	int trials = 30;
	if (argc >= 3) {
		std::istringstream iss(argv[1]);
		iss >> n;
		iss = std::istringstream(argv[2]);
		iss >> trials;
	}

	// Percolate an nxn grid one site at a time. Does this trials times, and then calculates various stats.
	PercolationStats stats(n, trials);
	std::cout << "Percolating a " << n << "x" << n << " grid " << trials << " times...\n";
	stats.runTrials();
	std::cout << "Mean: " << stats.getMean() << "\nStandard Deviation: " << stats.getStandardDeviation() << "\n";
	std::cout << "95% Confidence interval: [" << stats.confidence(PercolationStats::Level::LOW) << ", " << stats.confidence(PercolationStats::Level::HIGH) << "]";
}