#include<iostream>
#include<cstdlib>

using namespace std;

int N;

int main() {
	//freopen("1.txt", "r", stdin);
	int i, n = 0, cnt = 0, r = 1;
	scanf("%d", &N);
	while (N != 0) {
		cnt += (N / 10) * r;
		if (N % 10 == 1)
			cnt += n + 1;
		else if (N % 10 > 1)
			cnt += r;
		n += (N % 10) * r;
		r *= 10;
		N /= 10;
	}
	printf("%d\n", cnt);
	//fclose(stdin);
	return 0;
}