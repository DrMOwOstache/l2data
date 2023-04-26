#include "SortedSet.h"
#include "SortedSetIterator.h"

//node manage
SetNode::SetNode(TComp da, node nextN)
{
	this->data = da;
	this->nextNode = nextN;
}

TComp SetNode::element()
{
	return data;
}

node SetNode::next()
{
	return this->nextNode;
}


//Sorted set

node SortedSet::findPos(TComp elem)
{
	node aux = begining;
	if (relate(elem, aux->data) == false)
	{
		while (relate(elem, aux->nextNode->data) && aux->nextNode != nullptr)
			aux = aux->nextNode;
		return aux;
	}
	return nullptr;
}

SortedSet::SortedSet(Relation r) {
	relate = r;
	begining = nullptr;
	number = 0;
}


bool SortedSet::add(TComp elem) {
	if (begining == nullptr)
	{
		node p = new SetNode(elem,nullptr);
		begining = p;
		number++;
		return true;
	}
	else
	{
		node aux = findPos(elem);
		if (aux == nullptr)
		{
			if (begining->data == elem)
				return false;
			node p = new SetNode(elem, nullptr);
			p->nextNode = begining;
			begining = p;
			number++;
			return true;
		}
		if (aux->nextNode->data == elem)
			return false;
		else
		{
			node p = new SetNode(elem, nullptr);
			p->nextNode = aux->nextNode;
			aux->nextNode = p;
			number++;
			return true;
		}
	}

	return false;
}


bool SortedSet::remove(TComp elem) {
	node aux = findPos(elem);
	if (aux == nullptr)
	{
		if (begining->data != elem)
			return false;
		node p = begining;
		begining = begining->nextNode;
		delete p;
		number--;
		return true;
	}
	if (aux->nextNode->data == elem)
	{
		node p = aux->nextNode;
		aux->nextNode = aux->nextNode->nextNode;
		delete p;
		number--;
		return true;
	}
	
	return false;
}


bool SortedSet::search(TComp elem) const {
	node aux = begining;
	if (aux->data == elem)
		return true;
	while (relate(elem, aux->nextNode->data) && aux->nextNode != nullptr)
		aux = aux->nextNode;
	if (aux->nextNode->data == elem)
		return true;
	return false;
}


int SortedSet::size() const {
	return number;
}



bool SortedSet::isEmpty() const {
	return begining == nullptr;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	while (begining != nullptr)
	{
		node p = begining;
		begining = begining->nextNode;
		delete p;
	}
	number = 0;
}


