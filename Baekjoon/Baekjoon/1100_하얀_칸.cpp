#include <iostream>
using namespace std;
int main() {
	char chess[9];
	int res = 0;
	for (int i = 0; i < 8; ++i) {
		cin >> chess;
		for (int j = 0; j < 8; ++j) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (chess[j] == 'F')
						++res;
				}
			}
			else {
				if (j % 2 == 1) {
					if (chess[j] == 'F')
						++res;
				}
			}
		}
	}
	cout << res;
}