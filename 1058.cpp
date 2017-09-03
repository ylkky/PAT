#include<iostream>

using namespace std;

struct money {
	int a, b, c;
}m[2], res;

int main() {
	int i, temp;
	for (i = 0; i < 2; i++) {
		scanf("%d.%d.%d", &m[i].a, &m[i].b, &m[i].c);
	}
	res.c = m[0].c + m[1].c;
	temp = res.c / 29;
	res.c %= 29;
	res.b = m[0].b + m[1].b + temp;
	temp = res.b / 17;
	res.b %= 17;
	res.a = m[0].a + m[1].a + temp;
	printf("%d.%d.%d\n", res.a, res.b, res.c);
	return 0;
}