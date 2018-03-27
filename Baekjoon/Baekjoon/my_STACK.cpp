#include "my_STACK.h"
/*return val argument*/
//item: stack에 넣을 data
//-1 stack 꽉참
//1 정상
int STACK::Push(int item) {
	if (size == MAX_STACK_SIZE) //큐가 꽉참
		return -1;
	else {
		data[size] = item;
		++size;
		return 1;
	}
}

/*return val argument*/
//-1 stack 비어있음
//1 정상
int STACK::Pop() {
	if (size == 0)	//stack 비어있음
		return -1;
	else {
		data[size - 1] = 0;
		--size;
		return 1;
	}
}

int STACK::Top() {
	if (size == 0)	//스택이 비어있을경우 -21억 반환
		return MIN_INT;
	else
		return data[size-1];
}

int STACK::Size() {
	return size;
}

bool STACK::Empty() {
	if (size == 0)
		return TRUE;
	else
		return FALSE;
}