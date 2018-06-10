#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int i = 0;
	double res = 0.0;
	int sumK = 0;
	string line;
	stringstream instream;

	while (i != N)
	{
		getline(cin, line);
		instream.clear();
		instream.str(line);

		string name;
		int count;
		string grade_point;
		cin >> name >> count >> grade_point;
		if (grade_point == "A+") {
			res = res + 4.3 * count;
		}
		else if (grade_point == "A0") {
			res = res + 4.0 * count;
		}
		else if (grade_point == "A-") {
			res = res + 3.7 * count;
		}
		else if (grade_point == "B+") {
			res = res + 3.3 * count;
		}
		else if (grade_point == "B0") {
			res = res + 3.0 * count;
		}
		else if (grade_point == "B-") {
			res = res + 2.7 * count;
		}
		else if (grade_point == "C+") {
			res = res + 2.3 * count;
		}
		else if (grade_point == "C0") {
			res = res + 2.0 * count;
		}
		else if (grade_point == "C-") {
			res = res + 1.7 * count;
		}
		else if (grade_point == "D+") {
			res = res + 1.3 * count;
		}
		else if (grade_point == "D0") {
			res = res + 1.0 * count;
		}
		else if (grade_point == "D-") {
			res = res + 0.7 * count;
		}
		else;

		sumK = sumK + count;
		i++;
	}

	double result = res / sumK;
	result = result + 0.0001;
	printf("%.2lf", result);


}