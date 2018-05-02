#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main() {
	int n, len;
	vector <int> wildCard;
	scanf("%d", &n);
	char ** fileName = new char*[n];
	for (int i = 0; i < n; ++i) {
		fileName[i] = new char[60];
		scanf("%s", fileName[i]);
	}
	len = strlen(fileName[0]);

	for (int i = 0; i < len; ++i) {
		for (int j = 1; j < n; ++j) {
			if (fileName[j][i] != fileName[j-1][i]) {
				wildCard.push_back(i);
				break;
			}
		}
	}

	for (int i = 0; i < len; ++i) {
		bool isWild = 0;
		for (int j = 0; wildCard.begin() + j != wildCard.end(); ++j) {
			if (wildCard[j] == i) {
				isWild = 1;
				break;
			}
		}
		if (isWild)
			printf("?");
		else
			printf("%c", fileName[0][i]);
	}
}