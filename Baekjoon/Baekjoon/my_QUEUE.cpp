#include "my_QUEUE.h"
#include <stdio.h>
/*return val argument*/
//item: queue에 넣을 data
//-1 큐 꽉참
//1 정상
int QUEUE::Push(int item) {
	if (size == MAX_QUEUE_SIZE) //큐가 꽉참
		return -1;
	else {						//큐가 꽉차있지 않으므로 집어넣음
		data[size] = item;
		++size;
		return 1;
	}
}

/*return val argument*/
//-1 큐 비어있음
//1 정상
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
	QUEUE queue;
	for (int i = 0; i < 10; i++)
		queue.Push(i);
	
	printf("%d %d\n", queue.Size(), queue.Empty());
	
	while (!queue.Empty()) {
		printf("%d\n", queue.Front());
		queue.Pop();
	}

	printf("%d %d\n", queue.Size(), queue.Empty());
}