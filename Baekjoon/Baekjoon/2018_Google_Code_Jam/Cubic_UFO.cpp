#include <iostream>
#include <math.h>
#define PI 3.14159265358979323846
#define SQRT2 1.41421356237309504880

enum { X, Y, Z };

void Rotate(long double vPos[3][3], int center, long double rad);

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		long double area;
		long double vPos[3][3] = { {0.5, 0.0, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.0, 0.5}
	};
		scanf("%lf", &area);
		long double xRad = asin(area / SQRT2) - PI / 4.0;
		if (area <= SQRT2) {
			Rotate(vPos, Z, xRad);
		}
		else {
			xRad = PI / 4.0;
			long double zRad = asin(area / sqrt(3.0)) - asin(1.0 / sqrt(3.0));
			Rotate(vPos, X, xRad);
			Rotate(vPos, Z, zRad);
		}
		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				printf("%.6lf ", vPos[j][k]);
			}
			printf("\n");
		}
	}
}

void Rotate(long double vPos[3][3], int center, long double rad) {
	long double rotateMatrix[3][3];
	switch (center) {
	case Z:
		rotateMatrix[0][0] = cos(rad);		rotateMatrix[0][1] = -sin(rad);		rotateMatrix[0][2] = 0.0;
		rotateMatrix[1][0] = sin(rad);		rotateMatrix[1][1] = cos(rad);		rotateMatrix[1][2] = 0.0;
		rotateMatrix[2][0] = 0.0;		rotateMatrix[2][1] = 0.0;		rotateMatrix[2][2] = 1.0;
		break;
	case X:
		rotateMatrix[0][0] = 1.0;		rotateMatrix[0][1] = 0.0;		rotateMatrix[0][2] = 0.0;
		rotateMatrix[1][0] = 0.0;		rotateMatrix[1][1] = cos(rad);		rotateMatrix[1][2] = -sin(rad);
		rotateMatrix[2][0] = 0;		rotateMatrix[2][1] = sin(rad);		rotateMatrix[2][2] = cos(rad);
		break;
	}
	for (int i = 0; i < 3; ++i) {
		long double res[3] = { 0.0 };
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				res[j] += rotateMatrix[j][k] * vPos[i][k];
			}
		}
		for (int j = 0; j < 3; j++) {
			vPos[i][j] = res[j];
			if (abs(res[j]) < 0.000001)
				vPos[i][j] = 0.0;
		}
	}
}