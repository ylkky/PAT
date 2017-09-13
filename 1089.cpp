#include<iostream>
#include<vector>
using namespace std;

int N;
int *init, *res;

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	freopen("1", "r", stdin);
	int i, j, k, tmp, min;
	cin >> N;
	init = new int[N];
	res = new int[N];
	int *s = new int[N];
	for (i = 0; i < N; i++) {
		cin >> init[i];
	}
	for (i = 0; i < N; i++){
		cin >> res[i];
	}
	for (i = 0; i < N - 1; i++)
		if (res[i] > res[i + 1])
			break;
	min = i + 1;
	for (j = i + 1; j < N; j++)
		if (res[j] != init[j])
			break;
	if (j >= N) {
		printf("Insertion Sort\n");
		i++;
		tmp = init[i];
		for (j = 0; j < i; j++) {
			if (res[j] > tmp) {
				for (k = i; k > j; k--)
					res[k] = res[k - 1];
				res[j] = tmp;
				break;
			}
		}
	}
	else {
		// how to find merge degree
		printf("Merge Sort\n");
		i++;
		for (j = i; j < N - 1; j++) {
			if (res[j] > res[j + 1]) {
				if (j - i + 1 < min) {
					min = j - i + 1;
					i = j + 1;
					if (i + min >= N)
						break;
				}
			}
		}
		tmp = min;
		int ii = 0;
		for (k = 0; k < N; k += 2 * tmp) {
			for (i = 0, j = tmp; k + j < N && i < tmp && j < 2 * tmp; ) {
				if (res[i + k] < res[j + k]) {
					s[ii++] = res[i + k];
					i++;
				}
				else {
					s[ii++] = res[j + k];
					j++;
				}
			}
			if (i < tmp) {
				while (i < tmp) {
					s[ii++] = res[k + i++];
				}
			}
			else if(j + k < N)
				while (j < 2 * tmp)
					s[ii++] = res[k + j++];
		}
		res = s;
	}
	cout << res[0];
	for (i = 1; i < N; i++)
		cout << " " << res[i];
	fclose(stdin);
	return 0;
}