#ifndef QUICKUNIONUF_H
#define QUICKUNIONUF_H
#pragma once

#include <vector>
#include "UnionFind.h"

namespace Part1::DataStructure
{
	class QuickUnionUF : UnionFind
	{
	public:
		QuickUnionUF(int initialElements);
		int count();
		void push();
		void join(int p, int q);
		bool anyConnection(int p, int q) const;
		int operator[](int idx) const;

	private:
		std::vector<int> elements;
		int getRoot(int idx) const;
	};
}
#endif // !QUICKUNIONUF_H
