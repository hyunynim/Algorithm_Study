#include<cstdio>
#include<list>

using namespace std;

int main() {
	int n, tmp;
	scanf("%d", &n);
	list<int> seq;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		if (i == 0)
			seq.push_front(1);
		else {
			list<int>::iterator lPtrTmp = seq.end();
			for (int i = 0; i < tmp; ++i)
				lPtrTmp--;
			seq.insert(lPtrTmp, i + 1);
				
		}
	}
	list<int>::iterator lPtr = seq.begin();
	while (lPtr != seq.end()) {
		printf("%d ", *lPtr);
		++lPtr;
	}
}