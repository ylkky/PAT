#include<cstdio>
#include<cstdlib>

#define MAXN 100000

int N, M;
int *d, *sum;

int main() {
	freopen("1.txt", "r", stdin);
	scanf("%d", &N);
	d = (int *)malloc(sizeof(int) * N);
	sum = (int *)malloc(sizeof(int) * (N + 1));
	sum[0] = 0;
	int i, ii, j, k, n, res, del;
	for (i = 0; i < N; i++) {
		scanf("%d", &d[i]);
		sum[i + 1] = sum[i] + d[i];
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d%d", &j, &k);
		res = 0;
		if (j < k) {
			ii = j - 1;
			n = k - 1;
		}
		else{
			ii = k - 1;
			n = j - 1;
		}
		res = sum[n] - sum[ii];
		if (res < sum[N] - res)
			printf("%d\n", res);
		else
			printf("%d\n", sum[N] - res);
	}
	fclose(stdin);
	return 0;
}
