#ifndef SORT_H
#define SORT_H
#pragma once

#include <vector>

namespace Part1::Sort
{
	template <class T>
	class Sort
	{
	public:
		virtual void sort(std::vector<T> &) = 0;
		virtual ~Sort() {};

	protected:
		Sort() {};
	};
}

#endif // !SORT_H
