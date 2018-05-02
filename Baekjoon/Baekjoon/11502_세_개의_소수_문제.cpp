#include <cstdio>
#include <vector>

using namespace std;
int k;
vector <int> prime;
bool isOk = 0;
int p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

void CheckNum(vector<int> picked) {
	int res = 0;
	for (int i = 0; i < picked.size(); ++i) {
		res += picked[i];
	}
	if (res == k) {
		for (int i = 0; i < picked.size(); ++i) {
			printf("%d ", picked[i]);
		}
		printf("\n");
		isOk = 1;
	}
}

void pick(vector <int> picked, int toPick, int prev) {
	if (toPick == 0 && isOk == 0)
		CheckNum(picked);
	else {
		int next = picked.empty() ? 0 : prev;
		for (int i = next; i < prime.size(); ++i) {
			picked.push_back(prime[i]);
			if (isOk == 0)
				pick(picked, toPick - 1, i);
			picked.pop_back();
		}
	}
}

int main() {
	for (int i = 0; i < 168; ++i)
		prime.push_back(p[i]);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		vector <int> tmp;
		scanf("%d", &k);
		pick(tmp, 3, 0);
		if (isOk == 0)
			printf("0\n");
		tmp.clear();
		isOk = 0;
	}
}