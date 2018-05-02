#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack <char> res;
	int dec, degree;
	scanf("%d %d", &dec, &degree);
	while (dec > 0) {
		char tmp;
		int itmp = dec%degree;
		if (itmp >= 10)
			tmp = itmp - 10 + 'A';
		else
			tmp = itmp + '0';
		res.push(tmp);
		dec /= degree;
	}
	while (res.size()) {
		printf("%c", res.top());
		res.pop();
	}
}