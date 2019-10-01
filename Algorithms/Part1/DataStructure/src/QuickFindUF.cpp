#include "../QuickFindUF.h"

namespace Part1::DataStructure
{
	QuickFindUF::QuickFindUF(int initialElements) {
		for (int i = 0; i < initialElements; i++) {
			push(i);
		}
	}

	int QuickFindUF::count()
	{
		return static_cast<int>(elements.size());
	}

	void QuickFindUF::push(int element)
	{
		elements.push_back(element);
	}

	void QuickFindUF::join(int p, int q)
	{
		if (anyConnection(p, q)) {
			return;
		}

		int unionId = elements[p];
		int oldId = elements[q];
		for (int &id : elements) {
			if (id == oldId) {
				id = unionId;
			}
		}
	}

	bool QuickFindUF::anyConnection(int p, int q) const
	{
		// A node is certainly connected to itself
		if (p == q) {
			return true;
		}

		return elements[p] == elements[q];
	}

	int QuickFindUF::operator[](int idx) const
	{
		return elements.at(idx);
	}
}
