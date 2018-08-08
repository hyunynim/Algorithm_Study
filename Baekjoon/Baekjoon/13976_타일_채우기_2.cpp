#include<cstdio>
typedef long long ll;
#define MOD (ll)(1e9+7)
ll ABS(ll a) { return a > 0 ? a : -a; }

class Matrix {
private:
	ll data[2][2];
public:
	Matrix() {
		data[0][0] = 1;
		data[1][1] = 1;
		data[1][0] = 0;
		data[0][1] = 0;
	}
	Matrix(int E) {
		data[0][0] = E;
		data[1][1] = E;
		data[1][0] = 0;
		data[0][1] = 0;
	}
	Matrix(int a, int b, int c, int d) {
		data[0][0] = a;
		data[1][1] = d;
		data[1][0] = c;
		data[0][1] = b;
	}
	void SetMatrix(int data, int i, int j) {
		this->data[i][j] = data;
	}
	Matrix operator*(Matrix mat2) {
		Matrix res;
		res.data[0][0] = (this->data[0][0] * mat2.data[0][0])%MOD + (this->data[0][1] * mat2.data[1][0]) % MOD;
		res.data[0][1] = (this->data[0][0] * mat2.data[0][1]) % MOD + (this->data[0][1] * mat2.data[1][1]) % MOD;
		res.data[1][0] = (this->data[1][0] * mat2.data[0][0]) % MOD + (this->data[1][1] * mat2.data[1][0]) % MOD;
		res.data[1][1] = (this->data[1][0] * mat2.data[0][1]) % MOD + (this->data[1][1] * mat2.data[1][1]) % MOD;
		return res;
	}

	Matrix operator%(ll mod) {
		Matrix res;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (this->data[i][j] < 0)
					res.data[i][j] = -(ABS(this->data[i][j]) % mod);
				else
					res.data[i][j] = this->data[i][j] % mod;
			}
		}
		if (res.data[0][0] < 0)
			res.data[0][0] += MOD;
		if (res.data[0][1] < 0)
			res.data[0][1] += MOD;
		if (res.data[1][0] > 0)
			res.data[1][0] -= MOD;
		if (res.data[1][0] > 0)
			res.data[1][0] -= MOD;
		return res;
	}

	void operator=(Matrix mat2) {
		this->data[0][0] = mat2.data[0][0];
		this->data[1][0] = mat2.data[1][0];
		this->data[0][1] = mat2.data[0][1];
		this->data[1][1] = mat2.data[1][1];
	}

	ll GetData(int i, int j) {
		return data[i][j];
	}
};

Matrix mat1(4, 1, -1, 0);

ll pow(ll n, ll m) {
	Matrix res(11, 3, 3, 1);
	while (n > 0) {
		if (n % 2) {
			res = res * mat1;
			res = res % m;
		}
		mat1 = mat1 * mat1;
		mat1 = mat1 % m;
		n /= 2;
	}
	return res.GetData(0, 0) % m;
}

int main() {
	ll n;
	scanf("%lld", &n);
	if (n % 2)
		printf("0");
	else {
		if (n == 2)
			printf("3");
		else if (n == 4)
			printf("11");
		else {
			n /= 2;
			ll tmp = pow(n - 2, MOD);
			tmp < 0 ? tmp + MOD : tmp;
			printf("%lld\n", tmp);
		}
	}
	
}

/*comment*/
//2133은 AC인데 왜 WA인지 모르겠음
//뺄셈 연산에서의 모듈러 때문에 그런듯 (n = 62 일경우)
//AC