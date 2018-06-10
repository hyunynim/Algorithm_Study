#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int bin_search(vector<pair<int, int>> &seq, int left, int right, int n) {
	int mid = (left + right) / 2;
	if (left > right || mid >= seq.size() || (left == right && seq[mid].first != n))
		return -1;
	if (seq[mid].first == n)
		return mid;
	else if (seq[mid].first > n)
		return bin_search(seq, left, mid - 1, n);
	else
		return bin_search(seq, mid + 1, right, n);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	vector<pair<int, int>> seq1;
	vector<int> seq2(b);
	int tmp;
	for (int i = 0; i < a; ++i) {
		scanf("%d", &tmp);
		seq1.push_back(make_pair(tmp, 1));
	}
	for (int i = 0; i < b; ++i)
		scanf("%d", &seq2[i]);
	sort(seq1.begin(), seq1.end());
	int index, size = seq1.size();
	for (int i = 0; i < seq2.size(); ++i) {
		index = bin_search(seq1, 0, seq1.size(), seq2[i]);
		if (index != -1) {
			seq1[index].second = 0;
			--size;
		}
	}
	printf("%d\n", size);
	if (size) {
		for (int i = 0; i < seq1.size(); ++i) {
			if(seq1[i].second)
				printf("%d ", seq1[i]);
		}
	}
}

/*comment*/
//find함수는 순차탐색이라 시간초과뜨는듯
//이진탐색 그냥 구현 ㄱ
//시간초과 왜 시간초과가 뜨는걸까
//erase 때문에 그런건가?
//통과