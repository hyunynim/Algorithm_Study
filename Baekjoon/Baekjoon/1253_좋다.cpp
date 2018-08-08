#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int binary_search_for_pair(vector<pair<int, int>> & seq, int first, int last, int dat) {
	while (first <= last) {
		int mid = (first + last) / 2;
		if (seq[mid].first == dat)
			return mid;
		else if (seq[mid].first > dat)
			last = mid - 1;
		else if (seq[mid].first < dat)
			first = mid + 1;
	}
	return -1;
}

int binary_search_index(vector<int> & seq, int first, int last, int dat) {
	while (first <= last) {
		int mid = (first + last) / 2;
		if (seq[mid] == dat)
			return mid;
		else if (seq[mid] > dat)
			last = mid - 1;
		else if (seq[mid] < dat)
			first = mid + 1;
	}
	return -1;
}

int main() {
	int n, tmp;
	scanf("%d", &n);
	vector<pair<int, int>> seq;
	vector<int> seq2;
	for(int i = 0; i<n; ++i){
		scanf("%d", &tmp);
		seq2.push_back(tmp);
		int index = -1;
		for (int j = 0; j < seq.size(); ++j) {
			if (seq[j].first == tmp) {
				index = j;
				break;
			}
		}
		if (index == -1)
			seq.push_back(make_pair(tmp, 1));
		else
			++seq[index].second;
	}
	

	sort(seq.begin(), seq.end());
	sort(seq2.begin(), seq2.end());
	vector<int> res;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j) {
			int index = binary_search_index(seq2, 0, seq2.size() - 1, seq2[i] + seq2[j]);
			if (index != -1 && index != j && index != i) 
					res.push_back(binary_search_for_pair(seq, 0, seq.size() - 1, seq2[i] + seq2[j]));
		}
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (int i = 0; i < res.size(); ++i) {
		ans += seq[res[i]].second;
			
	}
	printf("%d", ans);
	
}

/*comment*/
//for문 범위 잘못잡음
//숫자가 중복되서 들어오면 걔들도 다 세어줘야함
//pair용 이진탐색 하나 만들어볼까
