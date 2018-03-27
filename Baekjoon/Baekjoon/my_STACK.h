#pragma once
#define MAX_STACK_SIZE 10000
#define MIN_INT -2100000000
#define TRUE 1
#define FALSE 0

typedef class STACK {

public:
	int Push(int data);
	int Pop();
	int Top();
	int Size();
	bool Empty();

private:
	int size = 0;
	int data[MAX_STACK_SIZE];
} stack;