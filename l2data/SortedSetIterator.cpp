#include "SortedSetIterator.h"
#include <exception>
#include <iostream>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	iter = m.begining;
}


void SortedSetIterator::first() {
	iter = multime.begining;
}


void SortedSetIterator::next() {
	if (valid())
	{
		//cout << iter->element() << '\n';
		iter = iter->next();
	}
	else
		throw exception();
}


TElem SortedSetIterator::getCurrent()
{
	if(valid())
		return iter->element();
	else
		throw exception();
}

bool SortedSetIterator::valid() const {
	if (iter != nullptr)
	{
		return true;
	}
	return false;
}

