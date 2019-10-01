#ifndef UNIONFIND_H
#define UNIONFIND_H
#pragma once

namespace Part1::DataStructure
{
	class UnionFind
	{
	public:
		virtual int count() = 0;
		virtual void push(int element) = 0;
		virtual void join(int p, int q) = 0;
		virtual bool anyConnection(int p, int q) const = 0;
		virtual int operator[](int idx) const = 0;
		virtual ~UnionFind() {};
	};
}
#endif // !UNIONFIND_H
