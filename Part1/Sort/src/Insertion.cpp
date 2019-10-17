#include <string>
#include <algorithm>
#include "../Insertion.h"

namespace Part1::Sort
{
	template <class T>
	void Insertion<T>::sort(std::vector<T> &vector)
	{
		for (size_t i = 1; i < vector.size(); i++) {
			size_t currentIdx = i;
			for (int j = i - 1; j >= 0; j--) {
				if (vector.at(currentIdx) >= vector.at(j)) {
					break;
				}

				std::swap(vector.at(currentIdx), vector.at(j));
				currentIdx--;
			}
		}
	}

	template void Insertion<int>::sort(std::vector<int> &vector);
	template void Insertion<std::string>::sort(std::vector<std::string> &vector);
}