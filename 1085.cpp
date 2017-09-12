#include<iostream>
using namespace std;

long long int N, p, *seq;
long long int n;

int cmp(const void *a, const void *b) {
	return *(long long int *)a - *(long long int *)b;
}
// why use long long int????
int main() {
	freopen("1", "r", stdin);
	long long int i, j, max = 0;
	cin >> N >> p;
	seq = new long long int[N];
	for (i = 0; i < N; i++)
		cin >> seq[i];
	qsort(seq, N, sizeof(long long int), cmp);		//从小到大排
	j = 0;
	for (i = 0; i < N; i++) {
		//n = seq[i] * p;
		if (seq[N - 1] <= seq[i] * p) {
			if (N - i > max)
				max = N - i;
			break;
		}
		for (j = j; j < N; j++) {
			if (seq[j] <= seq[i] * p) {
				if (j - i + 1 > max)
					max = j - i + 1;
			}
			else
				break;
		}
	}
	cout << max;
	fclose(stdin);
	return 0;
}