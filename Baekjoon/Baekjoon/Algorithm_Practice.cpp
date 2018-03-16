#include <stdio.h>

int main() {
	int dat[100000];
	int search = 80000, no[3] = { -1, -1, -1 };

	int low = 0, high = 99999;
	int mid;
	FILE * fp = fopen("data.dat", "r");
	for (int i = 0; i < 100000; i++)
		fscanf(fp, "%d", &dat[i]);
	fclose(fp);
	double tmp;

	//¼øÂ÷Å½»ö
	for (int i = 0; i < 100000; i++) {
		if (dat[i] == search)
			no[0] = i;
	}
	//ÀÌÁøÅ½»ö
	while (1) {
		mid = (high + low) / 2;
		if (dat[mid] == search) {
			no[1] = mid;
			break;
		}
		else if (dat[mid] <= search) {
			low = mid;
		}
		else
			high = mid;
	}

	low = 0;
	high = 99999;
	//º¸°£Å½»ö
	while (1) {
		tmp = ((double)(search - dat[low]) / (double)(dat[high] - dat[low])) * (high - low) + low +1;
		mid = tmp;
		if (dat[mid] == search) {
			no[2] = mid;
			break;
		}
		else if (dat[mid] < search) {
			low = mid;
		}
		else
			high = mid;
		getchar();
	}
	printf("%d %d %d", no[0], no[1], no[2]);


}