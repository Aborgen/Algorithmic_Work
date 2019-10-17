#ifndef SELECTION_H
#define SELECTION_H
#pragma once

#include "../Sort.h"

namespace Part1::Sort
{
	template <class T>
	class Selection : public Sort<T>
	{
	public:
		Selection() {};
		void sort(std::vector<T> &vector);

	private:
	};
}

#endif // !SELECTION_H
