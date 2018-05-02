#include "my_QUEUE.h"
#include <stdio.h>
/*return val argument*/
//item: queue�� ���� data
//-1 ť ����
//1 ����
int QUEUE::Push(int item) {
	if (size == MAX_QUEUE_SIZE) //ť�� ����
		return -1;
	else {						//ť�� �������� �����Ƿ� �������
		data[size] = item;
		++size;
		return 1;
	}
}

/*return val argument*/
//-1 ť �������
//1 ����
int QUEUE::Pop() {
	if (size == 0)	//ť�� �������
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
	if (size == 0)	//ť�� ���������� -21�� ��ȯ
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