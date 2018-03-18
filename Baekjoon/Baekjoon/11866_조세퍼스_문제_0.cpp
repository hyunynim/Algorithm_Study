#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, m;
	queue <int> people;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		people.push(i + 1);
	int k = 1;
	printf("<");
	while (people.size() > 1) {
		if (k%m == 0) {
			printf("%d, ", people.front());
			people.pop();
		}
		else {
			people.push(people.front());
			people.pop();
		}
		++k;
	}
	printf("%d>", people.front());
}