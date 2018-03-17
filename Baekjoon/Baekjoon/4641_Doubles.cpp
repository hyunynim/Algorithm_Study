#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> num;
	int input;
	int ans;
	while (1) {
		ans = 0;
		do {
			scanf("%d", &input);
			if (input == -1)
				return 0;
			num.push_back(input);
		} while (num.back() != 0);
		num.pop_back();
		for (int i = 0; i < num.size(); i++) {
			for (int j = 0; j < num.size(); j++) {
				if (num[i] * 2 == num[j])
					ans++;
			}
		}
		printf("%d\n", ans);
		num.clear();
	}
}