#pragma once
#define MAX_QUEUE_SIZE 10000
#define MIN_INT -2100000000
#define TRUE 1
#define FALSE 0

typedef class QUEUE {

public:
	int Push(int data);	//ť �ȿ� �����͸� ����
	int Pop();			//ť �� �տ� �ִ� �����͸� ����ϰ� ����
	int Front();		//ť �� �տ� �ִ� �����͸� ���
	int Size();			//ť�� ũ�⸦ ���
	bool Empty();		//ť�� ��������� 1 �� ���� �����ϸ� 0

private:
	int size = 0;
	int data[MAX_QUEUE_SIZE];
};
