#include <iostream>
#include <fstream>
 
#include <iostream>
#include <bits/stdc++.h>
 
 
#include <iterator>
 
#include <string>
#include <stdexcept>
 
#ifdef SPCPPL_DEBUG
#define SPCPPL_ASSERT(condition) \
    if(!(condition)) { \
        throw std::runtime_error(std::string() + #condition + " in line " + std::to_string(__LINE__) + " in " + __PRETTY_FUNCTION__); \
    }
#else
	#define SPCPPL_ASSERT(condition)
#endif
 
 
/**
* Support decrementing and multi-passing, but not declared bidirectional(or even forward) because
* it's reference type is not a reference.
*
* It doesn't return reference because
* 1. Anyway it'll not satisfy requirement [forward.iterators]/6
*   If a and b are both dereferenceable, then a == b if and only if *a and
*   b are bound to the same object.
* 2. It'll not work with reverse_iterator that returns operator * of temporary which is temporary for this iterator
*
* Note, reverse_iterator is not guaranteed to work  now too since it works only with bidirectional iterators,
* but it's seems to work at least on my implementation.
*
* It's not really useful anywhere except iterating anyway.
*/
template <typename T>
class IntegerIterator :
		public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
public:
	explicit IntegerIterator(int value) : value(value) {
 
	}
 
	IntegerIterator& operator ++() {
		++value;
		return *this;
	}
 
	IntegerIterator operator ++(int) {
		IntegerIterator copy = *this;
		++value;
		return copy;
	}
 
	IntegerIterator& operator --() {
		--value;
		return *this;
	}
 
	IntegerIterator operator --(int) {
		IntegerIterator copy = *this;
		--value;
		return copy;
	}
 
	T operator *() const {
		return value;
	}
 
	bool operator ==(IntegerIterator rhs) {
		return value == rhs.value;
	}
 
	bool operator !=(IntegerIterator rhs) {
		return !(*this == rhs);
	}
 
private:
	T value;
};
 
template <typename T>
class IntegerRange {
public:
	IntegerRange(T begin, T end) : begin_(begin), end_(end) {
 
	}
 
	IntegerIterator<T> begin() const {
		return IntegerIterator<T>(begin_);
	}
 
	IntegerIterator<T> end() const {
		return IntegerIterator<T>(end_);
	}
 
private:
	T begin_;
	T end_;
};
 
template <typename T>
class ReversedIntegerRange {
	typedef std::reverse_iterator<IntegerIterator<T>> IteratorType;
public:
	ReversedIntegerRange(T begin, T end) : begin_(begin), end_(end) {
 
	}
 
	IteratorType begin() const {
		return IteratorType(IntegerIterator<T>(begin_));
	}
 
	IteratorType end() const {
		return IteratorType(IntegerIterator<T>(end_));
	}
 
private:
	T begin_;
	T end_;
};
 
template <typename T>
IntegerRange<T> range(T to) {
	SPCPPL_ASSERT(to >= 0);
	return IntegerRange<T>(0, to);
}
 
template <typename T>
IntegerRange<T> range(T from, T to) {
	SPCPPL_ASSERT(from <= to);
	return IntegerRange<T>(from, to);
}
 
template <typename T>
ReversedIntegerRange<T> downrange(T from) {
	SPCPPL_ASSERT(from >= 0);
	return ReversedIntegerRange<T>(from, 0);
}
 
template <typename T>
ReversedIntegerRange<T> downrange(T from, T to) {
	SPCPPL_ASSERT(from >= to);
	return ReversedIntegerRange<T>(from, to);
}
 
 
#include <utility>
 
template <typename T>
class Range {
public:
	Range(T begin, T end) : begin_(std::move(begin)), end_(std::move(end)) {
 
	}
 
	T begin() {
		return begin_;
	}
 
	T end() {
		return end_;
	}
 
private:
	T begin_;
	T end_;
};
 
 
template <typename T>
Range<T> make_range(T begin, T end) {
	return Range<T>(begin, end);
}
 
using namespace std;
 
class OrderBook {
public:
	int readInt(std::istream& in) {
		int res;
		in >> res;
		return res;
	}
 
	void outputInt(std::ostream& out, int s) {
		//out << s / 100 << '.' << s / 10 % 10 << s % 10;
		out << s; 
	}
 
	void solve(std::istream& in, std::ostream& out) {
		int n, s;
		in >> n >> s;
 
		map <int, int> buy, sell;
		for (int i: range(n)) {
			char c;
			in >> c;
			int cost = readInt(in);
			int q;
			in >> q;
			if (c == 'B') {
				buy[cost] += q;
			}
			else {
				sell[cost] += q;
			}
		}
 
		while (sell.size() > s) {
			sell.erase(--sell.end());
		}
		for (auto it: make_range(sell.rbegin(), sell.rend())) {
			out << 'S' << ' ';
			outputInt(out, it.first);
			out << ' ' << it.second << "\n";
		}
 
		while (buy.size() > s) {
			buy.erase(buy.begin());
		}
 
		for (auto it: make_range(buy.rbegin(), buy.rend())) {
			out << 'B' << ' ';
			outputInt(out, it.first);
			out << ' ' << it.second << "\n";
		}
	}
};
 
 
int main() {
	std::ios_base::sync_with_stdio(false);
	OrderBook solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}