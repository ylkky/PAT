#include<iostream>
#include<stack>
using namespace std;

int N, M, K;
int *seq;

void check() {
	int i = 0, j = 0;
	stack<int> s;
	while (i < N) {
		if (s.empty()) {
			for (j; j < seq[i] && s.size() < M; j++)
				s.push(j + 1);
		}
		if (s.top() == seq[i]) {
			s.pop();
			i++;
		}
		else {
			if (s.top() > seq[i])
				break;
			else {
				if (s.size() == M)
					break;
				for (j; j < seq[i] && s.size() < M; j++) {
					s.push(j + 1);
				}
			}
		}
	}
	if (i == N)
		printf("YES\n");
	else
		printf("NO\n");
}

int main() {
	//freopen("1.txt", "r", stdin);
	int i, j;
	scanf("%d%d%d", &M, &N, &K);
	seq = (int *)malloc(sizeof(int) * N);
	for (i = 0; i < K; i++) {
		for (j = 0; j < N; j++)
			scanf("%d", &seq[j]);
		check();
	}
	//fclose(stdin);
	return 0;
}