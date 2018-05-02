#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<Windows.h>
using namespace std;
typedef long long ll;
int numCnt = 0;

void ReadNum(vector <int> & seq) {
	FILE * fp = fopen("num.txt", "r");
	int tmp;
	while (fscanf(fp, "%d", &tmp) != EOF) {
		seq.push_back(tmp);
		++numCnt;
	}
	printf("num.txt�κ��� %d���� ���� ���� �Ϸ�\n", numCnt);
}

void FindNum(const vector <int> & seq, int num) {
	ll finish, start = GetTickCount();
	int pos;	//seq�� num�� �����Ұ�� num�� ��ġ, �������� ������� numCnt ����
	
				/*	�̰��� binary search�� ������ ��	*/
	
	/*			�������					*/

	if (pos == numCnt)
		printf("%d ����\n", num);
	else
		printf("%d�� ��ġ�� %d\n", num, pos);
	finish = GetTickCount();
	printf("�ҿ�ð� = %lld ms\n", finish - start);
}

int main() {
	vector<int> seq;
	ReadNum(seq);
	FindNum(seq, 15);
	FindNum(seq, 16);
	FindNum(seq, 17);
	FindNum(seq, 4000014);
	FindNum(seq, 4000024);
	FindNum(seq, 4000498);
	FindNum(seq, 5000754);
	FindNum(seq, 5300190);
	FindNum(seq, 5300300);
}