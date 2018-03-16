#include <iostream>

void TopDownMergeSort(int A[], int B[], int n);
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[]);
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[]);
void CopyArray(int A[], int iBegin, int iEnd, int B[]);

int main() {
	int n;
	scanf("%d", &n);
	int * dat = new int[n];
	int * tmp = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &dat[i]);
	TopDownMergeSort(dat, tmp, n);
	for (int i = 0; i < n; i++)
		printf("%d\n", dat[i]);
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