#include <iostream>
#define TRUE 1
#define FALSE 0

typedef struct LinkedList {
	LinkedList * prev;
	LinkedList * next;
	int size;
	int item;
} list;


bool AttachFront(list * head, int data);
bool AttachBack(list * tail, int data);
bool DeleteItem(list * head, int data);
bool Clear(list * head, list * tail);
list * SearchItem(list * head, int data);
bool InsertItem(list * head, list * insertPtr, int insertData);
bool PrintAllItem(list * head, list * tail);

int main() {
	list * head = new list;
	list * tail = new list;
	head->next = tail;
	tail->prev = head;
	head->prev = NULL;
	tail->next = NULL;

	AttachFront(head, 1);
	AttachBack(tail, 2);
	for (int i = 0; i < 10; i++) {
		InsertItem(head, SearchItem(head, i % 2 == 0 ? 1 : 2), i + 10);
	}
	PrintAllItem(head, tail);
	Clear(head, tail);
	PrintAllItem(head, tail);
}

bool AttachFront(list * head, int data) {
	list * newNode = new list;
	if (newNode == NULL)
		return FALSE;
	else {
		newNode->prev = head;
		newNode->next = head->next;
		newNode->next->prev = newNode;
		head->next = newNode;
		newNode->item = data;
	}
	return TRUE;
}
bool AttachBack(list * tail, int data) {
	list * newNode = new list;
	if (newNode == NULL)
		return FALSE;
	else {
		newNode->prev = tail->prev;
		newNode->next = tail;
		newNode->prev->next = newNode;
		tail->prev = newNode;
		newNode->item = data;
	}
	return TRUE;
}
bool DeleteItem(list * head, int data) {
	list * target = SearchItem(head, data);
	target->prev->next = target->next;
	target->next->prev = target->prev;
	delete target;
	return TRUE;
}
bool Clear(list * head, list * tail) {
	if (head->next == tail)
		return FALSE;
	list * cur = head->next;
	list * tmp;
	head->next = tail;
	tail->prev = head;
	while (cur != NULL) {
		tmp = cur->next;
		delete cur;
		cur = tmp;
	}
	return TRUE;
}
list * SearchItem(list * head, int data) {
	list * cur = head;
	while (cur->item != data)
		cur = cur->next;
	return cur;
}
bool InsertItem(list * head, list * insertPtr, int insertData) {
	list * newNode = new list;
	if (newNode == NULL)
		return FALSE;
	else {
		list * target = insertPtr;
		if (target == NULL)
			return FALSE;
		newNode->item = insertData;
		newNode->prev = target;
		newNode->next = target->next;
		target->next = newNode;
		(*(target->next)).prev = newNode;
	}
	return TRUE;
}

bool PrintAllItem(list * head, list * tail) {
	if (head->next == tail)
		return FALSE;
	list * cur = head->next;
	while (cur->next != NULL) {
		printf("%d\n", cur->item);
		cur = cur->next;
	}
	return TRUE;
}