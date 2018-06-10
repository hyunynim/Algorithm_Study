#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	int n, tmp;
	scanf("%d", &n);
	vector<int> seq;
	vector<int> uSeq, uSeqCnt;
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	int m;
	scanf("%d", &m);

	sort(seq.begin(), seq.end());
	tmp = seq.front();
	int cnt = 1;
	for (int i = 1; i < seq.size(); ++i) {
		if(seq[i] == tmp){
			cnt++;
		}
		else {
			uSeq.push_back(tmp);
			uSeqCnt.push_back(cnt);
			cnt = 1;
			tmp = seq[i];
		}
	}
	if (tmp != uSeq.back()) {
		uSeq.push_back(tmp);
		uSeqCnt.push_back(cnt);
	}

	vector<int>::iterator vPtr;
	for (int i = 0; i < m; ++i) {
		int cnt = 0;
		scanf("%d", &tmp);
		vPtr = find(uSeq.begin(), uSeq.end(), tmp);
		if (vPtr == uSeq.end())
			printf("0 ");
		else {
			cnt = vPtr - uSeq.begin();
			printf("%d ", uSeqCnt[cnt]);
		}
	}
	
}

/*comment*/
//시간초과
//이진탐색 후 앞뒤로 세아리는건 어떨까
//이진탐색 후 갯수 세아리기 시간초과
//처음 입력받은거 정렬 후 개수 세서 압축
//시간초과