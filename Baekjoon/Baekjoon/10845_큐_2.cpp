#include <iostream>
#include <queue>
#include <string.h>
#define MAX_QUEUE_SIZE 10000
#define MIN_INT -2100000000
#define TRUE 1
#define FALSE 0

typedef class QUEUE {

public:
	int Push(int data);
	int Pop();
	int Front();
	int Size();
	int Back();
	bool Empty();

private:
	int size = 0;
	int data[MAX_QUEUE_SIZE];
} queue;


using namespace std;

int QUEUE::Push(int item) {
	if (size == MAX_QUEUE_SIZE) //큐가 꽉참
		return -1;
	else {
		data[size] = item;
		++size;
		return 1;
	}
}

int QUEUE::Pop() {
	if (size == 0)	//큐가 비어있음
		return -1;
	else {
		for (int i = 0; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		--size;
		return 1;
	}
}

int QUEUE::Front() {
	if (size == 0)	//큐가 비어있을경우 -21억 반환
		return MIN_INT;
	else
		return data[0];
}

int QUEUE::Back() {
	if (size == 0)	//큐가 비어있을경우 -21억 반환
		return MIN_INT;
	else
		return data[size-1];
}

int QUEUE::Size() {
	return size;
}

bool QUEUE::Empty() {
	if (size == 0)
		return TRUE;
	else
		return FALSE;
}

int main() {
	int t, oper;
	char command[10];
	scanf("%d", &t);
	QUEUE q;

	for (int i = 0; i < t; i++) {
		scanf("%s", command);
		if (strcmp(command, "push") == 0) {
			scanf("%d", &oper);
			q.Push(oper);
		}

		else if (strcmp(command, "pop") == 0) {
			if (q.Size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.Front());
				q.Pop();
			}
		}

		else if (strcmp(command, "size") == 0)
			printf("%d\n", q.Size());

		else if (strcmp(command, "empty") == 0)
			printf("%d\n", q.Empty());

		else if (strcmp(command, "front") == 0) {
			if (q.Size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.Front());
			}
		}

		else if (strcmp(command, "back") == 0) {
			if (q.Size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.Back());
			}
		}

	}
}