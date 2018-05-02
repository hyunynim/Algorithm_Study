#pragma once
#define MAX_QUEUE_SIZE 10000
#define MIN_INT -2100000000
#define TRUE 1
#define FALSE 0

typedef class QUEUE {

public:
	int Push(int data);	//큐 안에 데이터를 넣음
	int Pop();			//큐 맨 앞에 있는 데이터를 출력하고 제거
	int Front();		//큐 맨 앞에 있는 데이터를 출력
	int Size();			//큐의 크기를 출력
	bool Empty();		//큐가 비어있으면 1 한 개라도 존재하면 0

private:
	int size = 0;
	int data[MAX_QUEUE_SIZE];
};
