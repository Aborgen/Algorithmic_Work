#ifndef WEIGHTEDQUICKUNIONUFCOMP_H
#define WEIGHTEDQUICKUNIONUFCOMP_H
#pragma once

#include <vector>
#include "UnionFind.h"

namespace Part1::DataStructure
{
	class WeightedQuickUnionUFComp : UnionFind
	{
	public:
		WeightedQuickUnionUFComp(int initialElements);
		int count();
		void push(int element);
		void join(int p, int q);
		bool anyConnection(int p, int q) const;
		int operator[](int idx) const;

	private:
		std::vector<int> elements;
		std::vector<int> sizes;
		int getRoot(int idx) const;
		int getRootWithPathCompression(int idx);
	};
}

#endif // !WEIGHTEDQUICKUNIONUFCOMP_H
