#include <algorithm>
#include <string>
#include "../Selection.h"

namespace Part1::Sort
{
	template <class T>
	void Selection<T>::sort(std::vector<T> &vector)
	{
		for (size_t head = 0; head < vector.size(); head++) {
			int smallest = head;
			for (size_t j = head + 1; j < vector.size(); j++) {
				if (vector.at(j) < vector.at(smallest)) {
					smallest = j;
				}
			}

			std::swap(vector.at(head), vector.at(smallest));
		}
	}

	template void Selection<int>::sort(std::vector<int> &vector);
	template void Selection<std::string>::sort(std::vector<std::string> &vector);
}