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
	printf("num.txt로부터 %d개의 숫자 추출 완료\n", numCnt);
}

void FindNum(const vector <int> & seq, int num) {
	ll finish, start = GetTickCount();
	int pos;	//seq에 num이 존재할경우 num의 위치, 존재하지 않을경우 numCnt 저장
	
				/*	이곳에 binary search를 구현할 것	*/
	
	/*			여기까지					*/

	if (pos == numCnt)
		printf("%d 없음\n", num);
	else
		printf("%d의 위치는 %d\n", num, pos);
	finish = GetTickCount();
	printf("소요시간 = %lld ms\n", finish - start);
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