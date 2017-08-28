#include<stdio.h>
#include<stdlib.h>

long int num[2][1000001];
long int res[1000002];

void process(long int* n);

int main() {
	long int n[2], ii;
	int i;
	for (i = 0; i < 2; i++) {
		scanf("%ld", &n[i]);
		for (ii = 0; ii < n[i]; ii++)
			scanf("%ld", &num[i][ii]);
	}
	process(n);
	return 0;
}

void process(long int* n) {
	long int i, j0, j1, mid = n[0] + n[1];
	mid = (mid - 1) / 2;
	j0 = j1 = 0;
	for (i = 0; i < mid + 1 && j0 < n[0] && j1 < n[1]; i++) {
		if (num[0][j0] < num[1][j1]) {
			res[i] = num[0][j0];
			j0++;
		}
		else if (num[0][j0] > num[1][j1]) {
			res[i] = num[1][j1];
			j1++;
		}
		else {
			res[i] = num[0][j0];
			res[++i] = num[0][j0];
			j0++;
			j1++;
		}
	}
	if (i < mid + 1) {
		if (j0 < n[0]) {
			for (; i < mid + 1; i++, j0++) {
				res[i] = num[0][j0];
			}
		}
		else if (j1 < n[1]) {
			for (; i < mid + 1; i++, j1++) {
				res[i] = num[1][j1];
			}
		}
	}
	printf("%ld\n", res[mid]);
}
