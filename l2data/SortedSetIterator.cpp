#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	iter = m.begining;
}


void SortedSetIterator::first() {
	iter = multime.begining;
}


void SortedSetIterator::next() {
	if (iter->next() != nullptr)
		iter->next();
	else
		exception;
}


TElem SortedSetIterator::getCurrent()
{
	return iter->element();
}

bool SortedSetIterator::valid() const {
	if (iter != nullptr)
		return false;
	return true;
}

