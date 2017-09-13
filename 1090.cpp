#include<iostream>
#include<vector>
using namespace std;

int N, Root, cnt;
double P, r, maxP;
vector<int> *S;

void dfs(int root, double rate) {
	if (S[root].empty()) {
		if (rate * P > maxP) {
			cnt = 1;
			maxP = rate * P;
		}
		else if (maxP == rate * P)
			cnt++;
	}
	else {
		vector<int>::iterator it;
		for (it = S[root].begin(); it != S[root].end(); it++) {
			dfs(*it, rate * r);
		}
	}
}

int main() {
	freopen("1", "r", stdin);
	int i, j;
	cnt = 0;
	maxP = 0;
	cin >> N;
	cin >> P >> r;
	r = 1 + r / 100;
	S = new vector<int>[N];
	for (i = 0; i < N; i++) {
		cin >> j;
		if (j == -1)
			Root = i;
		else
			S[j].push_back(i);
	}
	dfs(Root, 1);
	printf("%.2lf %d", maxP, cnt);
	fclose(stdin);
	return 0;
}