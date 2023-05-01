#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

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
	if (this->nextNode == nullptr)
		return nullptr;
	return this->nextNode;
}


//Sorted set

node SortedSet::findPos(TComp elem)
{
	node aux = begining;
	if (aux == nullptr)
		return nullptr;
	if (elem == aux->data)
		return nullptr;
	if (relate(elem, aux->data) == false)
	{
		bool ok = false;
		//std::cout << aux->nextNode << '\n';
		while (ok == false && aux->nextNode != nullptr)
		{
			if (relate(elem, aux->nextNode->data) == true || aux->nextNode->data == elem)
				ok = true;
			else
				aux = aux->nextNode;
		}
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
		if (aux->nextNode == nullptr)
		{
			node p = new SetNode(elem, nullptr);
			aux->nextNode = p;
			//std::cout << '&' << p->data << '\n';
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
	if (begining != nullptr)
	{
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
		if (aux->data == elem)
		{
			node p = aux->nextNode;
			aux->nextNode = aux->nextNode->nextNode;
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
	}
	return false;
}


bool SortedSet::search(TComp elem) const {
	node aux = begining;
	while (aux != nullptr)
	{
		if (aux->data == elem)
			return true;
		aux = aux->nextNode;
	}
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

void SortedSet::Show()
{
	node p = begining;
	while (p != nullptr)
	{
		std::cout << p->data << '\n';
		p = p->nextNode;
	}
}
