#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define  MAXN 26 * 26 * 26 * 10

int N, K;
vector<int> *crs;

int myHash(char *s) {
	int ret = 0;
	for (int i = 0; i < 3; i++)
		ret = ret * 26 + s[i] - 'A';
	ret = ret * 10 + s[3] - '0';
	return ret;
}

void findName(int n, char* ret) {
	int i, a;
	char ch;
	ret[4] = 0;
	ret[3] = n % 10 + '0';
	a = n / 10;
	for (i = 2; i > -1; i--) {
		ch = a % 26 + 'A';
		ret[i] = ch;
		a /= 26;
	}
}

int main() {
	//freopen("1.txt", "r", stdin);
	int i, j, idx, id, c;
	char name[5];
	scanf("%d%d", &N, &K);
	crs = new vector<int>[K];
	for (i = 0; i < N; i++) {
		scanf("%s", name);
		id = myHash(name);
		scanf("%d", &c);
		for (j = 0; j < c; j++) {
			scanf("%d", &idx);
			crs[idx - 1].push_back(id);
		}
	}
	for (i = 0; i < K; i++) {
		char na[5];
		printf("%d %d\n", i + 1, crs[i].size());
		sort(crs[i].begin(), crs[i].end());
		for (j = 0; j < crs[i].size(); j++) {
			findName(crs[i][j], na);
			printf("%s\n", na);
		}
	}
	//fclose(stdin);
	return 0;
}