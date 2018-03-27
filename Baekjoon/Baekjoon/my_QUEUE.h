#pragma once
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
	bool Empty();

private:
	int size = 0;
	int data[MAX_QUEUE_SIZE];
} queue;
