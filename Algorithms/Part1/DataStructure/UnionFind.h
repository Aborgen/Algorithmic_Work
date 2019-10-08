#ifndef UNIONFIND_H
#define UNIONFIND_H
#pragma once

namespace Part1::DataStructure
{
	class UnionFind
	{
	public:
		virtual int count() = 0;
		virtual void push() = 0;
		virtual void join(int p, int q) = 0;
		virtual bool anyConnection(int p, int q) const = 0;
		virtual int operator[](int idx) const = 0;
		int getLastId() { return lastIndex; };
		virtual ~UnionFind() {};

	protected:
		int lastIndex{ 0 };
	};
	

}
#endif // !UNIONFIND_H
