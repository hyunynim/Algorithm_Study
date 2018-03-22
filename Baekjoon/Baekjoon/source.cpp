#include <iostream>

using namespace std;

int main() {
	long long int A = 0;
	long long int B = 0;

	cin >> A;
	cin >> B;

	if (A > B)
	{
		cout << (A + B)*(A - B + 1) / 2;
	}
	else if (B > A)
	{
		cout << (A + B)*(B - A + 1) / 2;
	}
	else
	{
		cout << A;
	}
	return 0;
}