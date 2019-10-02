#include "../QuickUnionUF.h"

namespace Part1::DataStructure
{
	QuickUnionUF::QuickUnionUF(int initialElements) {
		for (int i = 0; i < initialElements; i++) {
			push(i);
		}
	}

	int QuickUnionUF::count()
	{
		return static_cast<int>(elements.size());
	}

	void QuickUnionUF::push(int element)
	{
		elements.push_back(element);
	}

	void QuickUnionUF::join(int p, int q)
	{
		int newRoot = getRoot(p);
		int oldRoot = getRoot(q);
		elements[oldRoot] = elements[newRoot];
	}

	bool QuickUnionUF::anyConnection(int p, int q) const
	{
		// A node is certainly connected to itself
		if (p == q) {
			return true;
		}

		return getRoot(p) == getRoot(q);
	}

	int QuickUnionUF::getRoot(int idx) const
	{
		int value = elements[idx];
		if (value == idx) {
			return value;
		}

		return getRoot(value);
	}

	int QuickUnionUF::operator[](int idx) const
	{
		return elements.at(idx);
	}
}
