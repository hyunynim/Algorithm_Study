#include "my_STACK.h"
/*return val argument*/
//item: stack�� ���� data
//-1 stack ����
//1 ����
int STACK::Push(int item) {
	if (size == MAX_STACK_SIZE) //ť�� ����
		return -1;
	else {
		data[size] = item;
		++size;
		return 1;
	}
}

/*return val argument*/
//-1 stack �������
//1 ����
int STACK::Pop() {
	if (size == 0)	//stack �������
		return -1;
	else {
		data[size - 1] = 0;
		--size;
		return 1;
	}
}

int STACK::Top() {
	if (size == 0)	//������ ���������� -21�� ��ȯ
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