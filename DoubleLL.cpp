#include "DoubleLL.h"

//Basic constructor that loads the base tab
DoubleLinkedList::DoubleLinkedList()
{
	beg = createNode("about:blank");

	beg->next = NULL;
	beg->prev = NULL;

}

//Destructor to clean up our dynamic memory
DoubleLinkedList::~DoubleLinkedList()
{

	Node* current = beg;
	Node* temp = beg;

	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}

}

//Load function to load a new url and update the timestamp
void DoubleLinkedList::load(Iterator current, char * p)
{

	reloadUrl(p, current);

}

//Insert function
void DoubleLinkedList::insert(Iterator& current, char * p)
{

	Node* temp;
	Node* curr = &(*current);
	
	temp = createNode(p);

	if (!temp)
	{
		return;
	}

	temp->prev = curr;
	temp->next = curr->next;
	curr->next = temp;

	if (temp->next)
	{
		(temp->next)->prev = temp;
	}

	current = temp;

}

//Remove function
void DoubleLinkedList::remove(Iterator& current)
{

	Node* prevNode, *nextNode;
	Node* curr = &(*current);
	prevNode = curr->prev;
	nextNode = curr->next;

	if (!nextNode && !prevNode)
	{
		reloadUrl("about:blank", current);

		return;
	}

	if (prevNode)
	{
		prevNode->next = nextNode;
	}
	else
	{
		beg = nextNode;
	}

	if (nextNode)
	{
		nextNode->prev = prevNode;
	}

	current = (nextNode) ? nextNode : prevNode;

	delete curr;

}

//retrieves the first element (or atleast a pointer to it)
Node * DoubleLinkedList::getFirst() const
{
	return beg;
}

void DoubleLinkedList::reloadUrl(char * p, Iterator it)
{
	Node* curr = &(*it);
	delete[] curr->url;

	size_t size = strlen(p) + 1;
	curr->url = new char[size];
	strcpy_s(curr->url, size, p);

	curr->timeStamp = time(NULL);


}

//Print function
void DoubleLinkedList::print(Iterator current) const
{
	Node* temp = beg;
	while (temp)
	{
		if (&(*current) == temp)
		{
			cout << "> ";
		}
		cout << temp->url << " " << temp->timeStamp << endl;
		temp = temp->next;
	}
}

//helper function for creating a node. when needed
Node * DoubleLinkedList::createNode(char * p)
{

	Node* temp;

	try
	{
		temp = new Node;
	}
	catch (const std::bad_alloc)
	{
		cout << "Couldn't allocate memory for node!" << endl;
		return NULL;
	}

	if (strcmp(p, "") == 0)
	{
		size_t size = strlen("about:blank") + 1;
		temp->url = new char[size];
		strcpy_s(temp->url, size, "about:blank");
	}

	size_t size = strlen(p) + 1;
	temp->url = new char[size];
	strcpy_s(temp->url, size, p);

	temp->timeStamp = time(NULL);

	return temp;

}

//Compare function needed for the sorting algorithm
bool DoubleLinkedList::nodeCmp(Node * first, Node * second, int type)
{
	if (type == 1)
	{
		if (first->timeStamp == second->timeStamp)
		{
			return strcmp(first->url, second->url) <= 0;
		}
		return first->timeStamp < second->timeStamp;
	}
	if (type == 2)
	{
		int temp = strcmp(first->url, second->url);

		if (temp < 0)
		{
			return true;
		}
		else if (temp == 0)
		{
			return first->timeStamp <= second->timeStamp;
		}
		else
		{
			return false;
		}
	}
	return true;
}

//split function for the sorting algorithm
//Splits the list into two halves
Node* DoubleLinkedList::split(Node *head)
{
	struct Node *first = head, *second = head;

	while (first->next && first->next->next)
	{
		first = first->next->next;
		second = second->next;
	}

	Node* temp = second->next;
	second->next = NULL;
	return temp;
}

//merge function used to merge two doubly linked lists
Node* DoubleLinkedList::merge(Node* first, Node* second, int type)
{
	Node* head;
	//checking to see if the first list is empty
	if (!first)
	{
		return second;
	}

	//checking to see if the second list is empty
	if (!second)
	{
		return first;
	}

	if (!nodeCmp(first, second, type))
	{
		Node* temp;
		temp = first;
		first = second;
		second = temp;
	}

	head = first;

	while (second != nullptr)
	{
		if (nodeCmp(first, second, type))
		{
			if (first->next == nullptr)
			{
				first->next = second;
				second->prev = first;
				break;
			}
			first = first->next;
		}
		else
		{
			Node* temp = second;
			second = second->next;
			temp->prev = first->prev;
			first->prev->next = temp;
			temp->next = first;
			first->prev = temp;
		}
	}
	return head;
}

//the main function of the sorting algorithm
Node *DoubleLinkedList::mergeSort(Node *head, int type)
{
	if (!head || !head->next)
	{
		return head;
	}

	Node *second = split(head);

	//Recursive call for both halves
	head = mergeSort(head, type);
	second = mergeSort(second, type);

	//Merge both halves
	return merge(head, second, type);
}

//function that ensures that the first element will be the right one 
// after the sorting algorithm
void DoubleLinkedList::setFirst(Iterator current)
{
	beg = &(*current);
}

DoubleLinkedList::Iterator DoubleLinkedList::getIterator() const
{
	return Iterator(beg);
}
