#include <stdio.h>
#define ARR_SIZE 8
void QuickSort(int arr[], int left, int right, int pivot);
int main() {
	int num[ARR_SIZE] = { 10, 1, 5, 16, 61, 9, 11, 1 };
	QuickSort(num, 1, ARR_SIZE - 1, num[ARR_SIZE - 1]);
	
	for (int i = 0; i < ARR_SIZE; i++)
		printf("%d ", num[i]);
}

void QuickSort(int arr[], int left, int right, int pivot) {
	int iLeft = 0;
	int iRight = 0;
	int tmp = 0;
	int returnPivot;

	if (left == right);
	else {
		while ((left + iLeft) < (right - iRight)) {
			while (pivot > arr[left + iLeft])
				iLeft++;
			while (pivot < arr[right - iRight])
				iRight++;

			tmp = arr[left + iLeft];
			arr[left + iLeft] = arr[right - iRight];
			arr[right - iRight] = tmp;
			iLeft++;
			iRight++;
		}
		tmp = arr[ARR_SIZE - 1];
		arr[ARR_SIZE - 1] = arr[right - iRight];
		arr[right - iRight] = tmp;
		returnPivot = right - iRight;


		QuickSort(arr, returnPivot + 1, ARR_SIZE - 1, arr[ARR_SIZE - 1]);
	}
}