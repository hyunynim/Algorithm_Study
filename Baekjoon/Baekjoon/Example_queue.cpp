#include <iostream>
#include "my_QUEUE.h"
#include "my_STACK.h"

#define FALSE 0
#define TRUE 1


int main() {
	queue q;
	for (int i = 0; i < 10; i++)
		q.Push(i);
	for (int i = 0; i < 10; i++) {
		printf("%d\t%d\n", q.Front(), q.Size());
		q.Pop();
	}
	for (int i = 0; i < 10; i++)
		q.Push(i);
	printf("%d\t%d\n", q.Size(), q.Empty());
	while (!q.Empty())
		q.Pop();
	printf("%d\t%d", q.Size(), q.Empty());
}