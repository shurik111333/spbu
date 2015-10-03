struct ListNode
{
	int value;
	ListNode *next;
};

struct List
{
	ListNode *first;
	ListNode *last;
};

List *getNewList()
{
	List *newList = new List();
	newList->first = nullptr;
	newList->last = nullptr;
	return newList;
}

void addNode(List *list, int value)
{
	ListNode *newNode = new ListNode();
	newNode->value = value;
	if (list->first == nullptr)
	{
		list->first = newNode;
		list->last = newNode;
		newNode->next = newNode;
		return;
	}
	newNode->next = list->first;
	list->first = newNode;
	list->last->next = newNode;
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
		if (currNode == list->first)
		{
			list->first = currNode->next;
		}
		if (currNode == list->last)
		{
			list->last = previousNode;
		}
		previousNode->next = currNode->next;
		delete currNode;
	}
}

void deleteList(List *list)
{
	//while ()
}