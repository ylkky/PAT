#include<iostream>
#include<map>
using namespace std;

int N, M;

int main() {
	//freopen("1.txt", "r", stdin);
	int i, j, max, c;
	map<int, int> cnt;
	map<int, int>::iterator iter;
	scanf("%d%d", &N, &M);
	max = M * N / 2;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &c);
			cnt[c]++;
			if (cnt[c] > max)
				break;
		}
	}
	printf("%d", c);
	//fclose(stdin);
	return 0;
}