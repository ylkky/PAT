#include<iostream>
using namespace std;

struct rationalNum {
	long int n, d;
};
typedef struct rationalNum RN;

int N;
RN *rn;

long long int gcd(long long int n, long long int d) {
	long long int temp;
	if (n == 0)
		return 1;
	n = n < 0 ? -n : n;
	while (d % n) {
		temp = d % n;
		d = n;
		n = temp;
	}
	return n;
}

RN add(RN r1, RN r2) {
	RN ret;
	long long int n, d, k;
	d = r1.d * r2.d;
	n = r1.n * r2.d + r2.n * r1.d;
	k = gcd(n, d);
	ret.n = n / k;
	ret.d = d / k;
	return ret;
}

int main() {
	//freopen("1", "r", stdin);
	int i;
	long int j;
	RN res;
	cin >> N;
	rn = new RN[N];
	for (i = 0; i < N; i++) {
		scanf("%ld/%ld", &rn[i].n, &rn[i].d);
	}
	res = add(rn[0], rn[1]);
	for (i = 2; i < N; i++) {
		res = add(res, rn[i]);
	}
	j = res.n / res.d;
	if (res.n == 0 || res.n % res.d == 0)
		cout << j << endl;
	else if (j == 0)
		cout << res.n % res.d << "/" << res.d << endl;
	else
		cout << j << " " << res.n % res.d << "/" << res.d << endl;
	//fclose(stdin);
	return 0;
}