#include<iostream>

using namespace std;

int main() {
	long double a, b, c;
	cin >> a >> b >> c;
	cout.setf(ios::fixed);
	cout << a * b / c;
}