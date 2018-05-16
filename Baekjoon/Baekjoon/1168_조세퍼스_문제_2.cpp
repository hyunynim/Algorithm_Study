#include <iostream>
#include<deque>
#include <queue>

using namespace std;

int main() {
	int n, m;
	deque <int> people;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		people.push_back(i + 1);
	int k = 1;
	printf("<");
	int size = people.size();
	while (people.size() > 1) {
		if (size >= m) {
			if (m < size - m) {
				for (int i = 0; i < m - 1; ++i) {
					people.push_back(people.front());
					people.pop_front();
				}
				printf("%d, ", people.front());
				people.pop_front();
			}
			else {
				for (int i = 0; i < size - m; ++i) {
					people.push_front(people.back());
					people.pop_back();
				}
				printf("%d, ", people.back());
				people.pop_back();
			}
		}
		else {
			int tmp = m % size;
			if (tmp < size - tmp) {
				for (int i = 0; i < tmp - 1; ++i) {
					people.push_back(people.front());
					people.pop_front();
				}
				printf("%d, ", people.front());
				people.pop_front();
			}
			else {
				for (int i = 0; i < size - tmp; ++i) {
					people.push_front(people.back());
					people.pop_back();
				}
				printf("%d, ", people.back());
				people.pop_back();
			}
		}
		size = people.size();
	}
	printf("%d>", people.front());
}