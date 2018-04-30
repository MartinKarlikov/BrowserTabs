#include "DoubleLL.h"

typedef DoubleLinkedList::Iterator Iterator;

//decrement prefix operator
Iterator& Iterator::operator--()
{
	if (curr->prev)
	{
		curr = curr->prev;
	}
	return *this;
}

//decrement postfix operator
Iterator Iterator::operator--(int)
{
	Iterator temp(*this);
	operator--();
	return temp;
}

//basic constructor
Iterator::Iterator()
{
	curr = NULL;
}

//constructor with a given node
Iterator::Iterator(Node * other)
{
	curr = other;
}

//assignment operator to a given node
Iterator& Iterator::operator=(Node * other)
{
	curr = other;
	return *this;
}

//assignment operator with a given iterator
Iterator& Iterator::operator=(const Iterator & other)
{
	curr = other.curr;
	return *this;
}

//increment operator, prefix
Iterator& Iterator::operator++()
{
	if (curr->next)
	{
		curr = curr->next;
	}
	return *this;
}

//increment operator, postfix
Iterator Iterator::operator++(int)
{
	Iterator temp(*this);
	operator++();
	return temp;
}

//equals operator
bool Iterator::operator==(const Iterator & other) const
{
	return curr == other.curr;
}

//difference operator
bool Iterator::operator!=(const Iterator & other) const
{
	return operator==(other);
}


Iterator::operator bool() const
{
	return curr->next != NULL;
}

//dereference operator
Node & DoubleLinkedList::Iterator::operator*() const
{
	return *curr;
}


bool Iterator::atEnd() const
{
	return curr->next == NULL;
}


