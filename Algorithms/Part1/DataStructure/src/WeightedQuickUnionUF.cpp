#include "../WeightedQuickUnionUF.h"

namespace Part1::DataStructure
{
	WeightedQuickUnionUF::WeightedQuickUnionUF(int initialElements) {
		for (int i = 0; i < initialElements; i++) {
			push(i);
		}
	}

	int WeightedQuickUnionUF::count()
	{
		return static_cast<int>(elements.size());
	}

	void WeightedQuickUnionUF::push(int element)
	{
		elements.push_back(element);
		sizes.push_back(1);
	}

	// This is where the 'weighted' keyword comes in. There is a new vector,
	// sizes, which keeps track how many children each node has. When joining
	// two nodes, the 'heavier' (more children) node becomes the parent of the other.
	void WeightedQuickUnionUF::join(int p, int q)
	{
		int newRoot = getRoot(p);
		int oldRoot = getRoot(q);
		if (newRoot == oldRoot) {
			return;
		}
		else if (sizes[newRoot] < sizes[oldRoot]) {
			std::swap(newRoot, oldRoot);
		}

		elements[oldRoot] = elements[newRoot];
		sizes[newRoot] += sizes[oldRoot];
	}

	bool WeightedQuickUnionUF::anyConnection(int p, int q) const
	{
		// A node is certainly connected to itself
		if (p == q) {
			return true;
		}

		return getRoot(p) == getRoot(q);
	}

	int WeightedQuickUnionUF::getRoot(int idx) const
	{
		int value = elements[idx];
		if (value == idx) {
			return value;
		}

		return getRoot(value);
	}

	int WeightedQuickUnionUF::operator[](int idx) const
	{
		return elements.at(idx);
	}
}
