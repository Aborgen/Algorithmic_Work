#include "../WeightedQuickUnionUFComp.h"

namespace Part1::DataStructure
{
	WeightedQuickUnionUFComp::WeightedQuickUnionUFComp(int initialElements) {
		for (int i = 0; i < initialElements; i++) {
			push(i);
		}
	}

	int WeightedQuickUnionUFComp::count()
	{
		return static_cast<int>(elements.size());
	}

	void WeightedQuickUnionUFComp::push(int element)
	{
		elements.push_back(element);
		sizes.push_back(1);
	}

	// This is where the 'weighted' keyword comes in. There is a new vector,
	// sizes, which keeps track how many children each node has. When joining
	// two nodes, the 'heavier' (more children) node becomes the parent of the other.
	void WeightedQuickUnionUFComp::join(int p, int q)
	{
		int newRoot = getRootWithPathCompression(p);
		int oldRoot = getRootWithPathCompression(q);
		if (newRoot == oldRoot) {
			return;
		}
		else if (sizes[newRoot] < sizes[oldRoot]) {
			std::swap(newRoot, oldRoot);
		}

		elements[oldRoot] = elements[newRoot];
		sizes[newRoot] += sizes[oldRoot];
	}

	bool WeightedQuickUnionUFComp::anyConnection(int p, int q) const
	{
		// A node is certainly connected to itself
		if (p == q) {
			return true;
		}

		return getRoot(p) == getRoot(q);
	}

	int WeightedQuickUnionUFComp::getRoot(int idx) const
	{
		int value = elements[idx];
		if (value == idx) {
			return value;
		}

		return getRoot(value);
	}
	
	// We perform path compression in this method. The idea is to have each node point toward its root.
	int WeightedQuickUnionUFComp::getRootWithPathCompression(int idx)
	{
		int value = elements[idx];
		if (value == idx) {
			return value;
		}

		// Once we obtain the root, each step back toward the node at idx will then be pointed toward root.
		int root = getRootWithPathCompression(value);
		elements[idx] = root;
		return root;
	}

	int WeightedQuickUnionUFComp::operator[](int idx) const
	{
		return elements.at(idx);
	}
}
