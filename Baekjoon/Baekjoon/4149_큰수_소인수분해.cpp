#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	long long n;
	vector <long long> v;
	v.push_back(2LL);

	int i_min = 0;
	int i = 0;
	int isPrime = 0;
	scanf("%lld", &n);
	while (n > 1) {
		while (v.begin() + i != v.end()) {

			if (n % (*(v.begin() + i)) == 0) {
				printf("%d\n", *(v.begin() + i));
				n /= *(v.begin() + i);
			}
			else
				i++;
		}

			for (long long int j = *(v.end() - 1)+1; ; j++) {
				isPrime = 0;
				for (int k = 0; k < v.size(); k++) {
					if (j%v[k] == 0) {
						isPrime = -1;
					}
				}
				if (isPrime != -1) {
					isPrime = 0;
					v.push_back(j);
					break;
				}
			}
		
	}
}