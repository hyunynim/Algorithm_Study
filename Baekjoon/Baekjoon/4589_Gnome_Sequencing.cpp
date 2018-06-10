#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int t;
	printf("Gnomes:\n");
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int tmp;
		vector<int> beard;
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &tmp);
			beard.push_back(tmp);
		}
		bool isOrdered = 1;
		for (int j = 1; j < 3; ++j) {
			if (beard[j - 1] > beard[j]) {
				isOrdered = 0;
				break;
			}
		}
		if (isOrdered) {
			printf("Ordered\n");
			continue;
		}
		isOrdered = 1;
		for (int j = 1; j < 3; ++j) {
			if (beard[j - 1] < beard[j]) {
				isOrdered = 0;
				break;
			}
		}
		if (isOrdered) {
			printf("Ordered\n");
			continue;
		}
		printf("Unordered\n");
	}
}

/*comment*/
//¸ÇÀ§¿¡ Ãâ·Â ÇÑÁÙ »©¸ÔÀ½