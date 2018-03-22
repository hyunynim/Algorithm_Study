#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, tmp;
	vector <int> num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	for (int i = 0; num.begin() + i != num.end(); i++)
		printf("%d\n", num[i]);

}

/*comment*/
//배열의 크기가 커지면 에러뜨는듯