struct ListNode
{
	int value;
	ListNode *next;
};

struct List
{
	ListNode *first;
	ListNode *last;
	ListNode *currentElement;
};

List *getNewList()
{
	List *newList = new List();
	newList->first = nullptr;
	newList->last = nullptr;
	newList->currentElement = nullptr;
	return newList;
}

void setCurrentElementAtFirst(List *list)
{
	list->currentElement = list->first;
}

int getCurrent(List *list)
{
	return list->currentElement->value;
}

int getNext(List *list)
{
	return list->currentElement->next->value;
}

int goToNext(List *list)
{
	list->currentElement = list->currentElement->next;
	return list->currentElement->value;
}

void addBack(List *list, int value)
{
	ListNode *newNode = new ListNode{value, list->first};
	if (list->first == nullptr)
	{
		list->first = newNode;
		list->last = newNode;
		newNode->next = newNode;
		//list->currentElement = list->first;
		return;
	}
	list->last->next = newNode;
	list->last = newNode;
}

void deleteNode(List *list, int value)
{
	ListNode *currNode = list->first;
	ListNode *previousNode = list->last;
	while (currNode->value != value && currNode->next != list->first)
	{
		previousNode = currNode;
		currNode = currNode->next;
	}
	if (currNode->value == value)
	{
		if (list->first->next == list->first)
		{
			delete list->first;
			list->first = nullptr;
			list->last = nullptr;
			list->currentElement = nullptr;
			return;
		}
		if (currNode == list->first)
		{
			list->first = currNode->next;
		}
		if (currNode == list->last)
		{
			list->last = previousNode;
		}
		previousNode->next = currNode->next;
		if (list->currentElement == currNode)
		{
			list->currentElement = currNode->next;
		}
		delete currNode;
	}
}

void clear(List *list)
{
	while (list->first != nullptr)
	{
		deleteNode(list, list->first->value);
	}
}