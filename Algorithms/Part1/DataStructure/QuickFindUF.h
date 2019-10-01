#ifndef QUICKFINDUF_H
#define QUICKFINDUF_H
#pragma once

#include <vector>
#include "UnionFind.h"

namespace Part1::DataStructure
{
	class QuickFindUF : UnionFind
	{
	public:
		QuickFindUF(int initialElements);
		int count();
		void push(int element);
		void join(int p, int q);
		bool anyConnection(int p, int q) const;
		int operator[](int idx) const;

	private:
		std::vector<int> elements;
	};
}

#endif // !QUICKFINDUF_H
