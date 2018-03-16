#include <iostream>
#include <vector>

void TopDownMergeSort(int A[], int B[], int n);
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[]);
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[]);
void CopyArray(int A[], int iBegin, int iEnd, int B[]);

using namespace std;

int main() {
	int n, sum = 0;
	int chk_num[8001] = { 0 };
	vector <int> v;
	scanf("%d", &n);

	int * data = new int[n];
	int * tmp = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
		chk_num[data[i] + 4000]++;
		sum += data[i];
	}
	TopDownMergeSort(data, tmp, n);

	double avg = (double)sum / n;
	int avgi;
	if (avg - (int)avg >= 0.5)
		avgi = (int)avg + 1;
	else
		avgi = (int)avg;

	int max = -10000;
	for (int i = 0; i < 8001; i++) {
		if (max < chk_num[i] && chk_num[i] != 0) {
			v.clear();
			max = chk_num[i];
			v.push_back(i - 4000);
		}
		else if (max == chk_num[i] && chk_num[i] != 0) 
			v.push_back(i - 4000);
	}

	printf("%d\n", avgi);
	printf("%d\n", data[n / 2]);
	if (v.size() == 1)
		printf("%d\n", v[0]);

	else {
		int * mer = new int[v.size()];
		for (int i = 0; i < v.size(); i++) 
			mer[i] = v[i];
		
		int * mer2 = new int[v.size()];
		TopDownMergeSort(mer, mer2, v.size());
		printf("%d\n", mer[1]);
	}

	printf("%d", data[n - 1] - data[0]);
}

void TopDownMergeSort(int A[], int B[], int n)
{
	CopyArray(A, 0, n, B);
	TopDownSplitMerge(B, 0, n, A);
}
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
	if (iEnd - iBegin < 2)
		return;

	int iMiddle = (iEnd + iBegin) / 2;

	TopDownSplitMerge(A, iBegin, iMiddle, B);
	TopDownSplitMerge(A, iMiddle, iEnd, B);
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
	int i = iBegin;
	int j = iMiddle;

	for (int k = iBegin; k < iEnd; k++) {
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
			B[k] = A[i];
			i = i + 1;
		}
		else {
			B[k] = A[j];
			j = j + 1;
		}
	}
}

void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
	for (int k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}