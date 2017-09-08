#include<iostream>
#include<cstdlib>
using namespace std;

int N;
int *a, *b;

void swap(int i, int j) {
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int main() {
	freopen("1", "r", stdin);
	int i, j, k, cnt = 0;
	scanf("%d", &N);
	a = (int *)malloc(sizeof(int) * N);
	b = (int *)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		b[a[i]] = i;
	}
	i = 0;
	for (; ;) {
		while (a[0] != 0) {
			j = b[0];
			b[0] = b[j];
			b[j] = j;
			swap(j, b[0]);
			cnt++;
		}
		for (; i < N; i++) {
			if (a[i] != i) {
				swap(b[0], i);
				cnt++;
				b[0] = i;
				b[a[0]] = 0;
				break;
			}
		}
		if (i == N)
			break;
	}
	printf("%d\n", cnt);
	fclose(stdin);
	return 0;
}