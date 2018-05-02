#include <iostream>
#include <deque>

using namespace std;

void LShift(deque <int> & num);
void RShift(deque <int> & num);
void PopNSync(int popNum, deque <int> & num1, deque <int> & num2);

int main() {
	deque <int> num1, num2;
	int n, m, res = 0, popNum;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		num1.push_back(i + 1);
		num2.push_back(i + 1);
	}

	for (int i = 0; i < m; ++i) {
		scanf("%d", &popNum);
		int cnt = 0;
		while (num1.front() != popNum && num2.front() != popNum) {
			LShift(num1);
			RShift(num2);
			cnt++;
		}
		if (cnt == 0) {
			num1.pop_front(); num2.pop_front();
		}
		else
			PopNSync(popNum, num1, num2);
		res += cnt;
		}

	printf("%d", res);
	}

void LShift(deque <int> & num) {
	num.push_back(num.front());
	num.pop_front();
}
void RShift(deque <int> & num) {
	num.push_front(num.back());
	num.pop_back();
}

void PopNSync(int popNum, deque <int> & num1, deque <int> & num2) {
	if (popNum == num2.front()) {
		num2.pop_front();
		num1.clear();
		for (int i = 0; i < num2.size(); i++) {
			num1.push_back(num2.front());
			num2.push_back(num2.front());
			num2.pop_front();
		}
	}
	else {
		num1.pop_front();
		num2.clear();
		for (int i = 0; i < num1.size(); i++) {
			num2.push_back(num1.front());
			num1.push_back(num1.front());
			num1.pop_front();
		}
	}
}

/*commnet*/
//middle을 잘못잡았나? 잘못잡음
//갈아엎음
//데크 2개 이용
//while문 2개 -> 1개 연산 최소화
//lCnt, rCnt삭제, popNum parameter로 비교
//맞았습니다