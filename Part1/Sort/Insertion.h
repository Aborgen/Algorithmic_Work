#ifndef INSERTION_H
#define INSERTION_H
#pragma once

#include "Sort.h"

namespace Part1::Sort
{
	template <class T>
	class Insertion : public Sort<T>
	{
	public:
		Insertion() {};
		void sort(std::vector<T> &vector);

	private:
	};
}

#endif // !INSERT_H
