#include<iostream>
using namespace std;

long int a1, a2, b1, b2;

struct Num {
	long int n, d;
}res;

long int gcd(long int n, long int d) {
	long int tmp;
	if (n == 0)
		return 1;
	else {
		while (n % d) {
			tmp = n % d;
			n = d;
			d = tmp;
		}
		return d;
	}
}

Num add(long int n1, long int d1, long int n2, long int d2) {
	struct Num ret;
	long int n, d;
	d = d1 * d2;
	n = n1 * d2 + n2 * d1;
	//k = gcd(n, d);
	ret.n = n;
	ret.d = d;
	return ret;
}

Num mul(long int n1, long int d1, long int n2, long int d2) {
	struct Num ret;
	if (d2 == 0) {
		ret.d = 0;
		return ret;
	}
	else {
		long int n, d;
		n = n1 * n2;
		d = d1 * d2;
		//k = gcd(n, d);
		ret.n = n;
		ret.d = d;
		return ret;
	}
}

void printNum(long int n, long int d) {
	if (d == 0)
		printf("Inf");
	else if (n < 0) {
		printf("(-");
		printNum(-n, d);
		printf(")");
	}
	else{
		long int i, k;
		k = gcd(n, d);
		i = n / d;
		if (n == 0) {
			printf("0");
		}
		else if (i == 0) {
			printf("%ld/%ld", n / k, d / k);
		}
		else {
			printf("%ld", i);
			if (n % d) {
				printf(" %ld/%ld", (n % d) / k, d / k);
			}
		}
	}
	
}

void print(char ch) {
	printNum(a1, b1);
	printf(" %c ", ch);
	printNum(a2, b2);
	printf(" = ");
	printNum(res.n, res.d);
	printf("\n");
}

int main() {
	freopen("1", "r", stdin);
	scanf("%ld/%ld", &a1, &b1);
	scanf("%ld/%ld", &a2, &b2);
	res = add(a1, b1, a2, b2);
	print('+');
	res = add(a1, b1, -a2, b2);
	print('-');
	res = mul(a1, b1, a2, b2);
	print('*');
	if (a2 < 0) {
		res = mul(a1, b1, -b2, -a2);
	}
	else
		res = mul(a1, b1, b2, a2);
	print('/');
	fclose(stdin);
	return 0;
}