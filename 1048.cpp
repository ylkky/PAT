#include<iostream>
#include<cstdlib>

using namespace std;


int N, M;
int *coin;

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	freopen("1.txt", "r", stdin);
	int i, j, num, cnt = 0;
	scanf("%d%d", &N, &M);
	coin = (int *)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num >= M)
			continue;
		else {
			coin[cnt] = num;
			cnt++;
		}
	}
	qsort(coin, cnt, sizeof(int), cmp);
	i = 0; 
	j = cnt - 1;
	while (i < j) {
		if (coin[i] + coin[j] == M)
			break;
		else if (coin[i] + coin[j] > M)
			j--;
		else if (coin[i] + coin[j] < M)
			i++;
	}
	if (i >= j)
		printf("No Solution\n");
	else {
		printf("%d %d\n", coin[i], coin[j]);
	}
	fclose(stdin);
	return 0;
}