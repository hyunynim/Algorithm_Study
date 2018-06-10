#include<cstdio>
#include<cmath>

double point_distance(double x, double y, double a, double b) {
	double distance = 0;
	distance = sqrt(pow(x - a, 2.0) + pow(y - b, 2.0));

	return distance;
}
int main() {
	double x1, x2, y1, y2;
	double cx, cy, r;
	int t, n, res;
	double d1, d2;
	scanf("%d", &t);


	for (int i = 0; i < t; ++i){
		scanf("%lf %lf %lf %lf %d", &x1, &y1, &x2, &y2, &n);
		res = 0;
		for(int j = 0; j<n; ++j){
			scanf("%lf %lf %lf", &cx, &cy, &r);
			d1 = point_distance(x1, y1, cx, cy);
			d2 = point_distance(x2, y2, cx, cy);
			if (d1<r&&d2>r) {
				res++;
			}
			else if (d1>r&&d2<r) {
				res++;
			}
		}
		printf("%d\n", res);
	}


	return 0;
}