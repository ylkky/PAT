#include<iostream>
#include<vector>

using namespace std;

#define MAXX 100000001;

int N, M;

int main() {
	//freopen("1.txt", "r", stdin);
	cin >> N >> M;
	int *d = new int[N];
	int i, j, k, sum = 0, max = MAXX;
	vector<int> f, e;
	for (i = 0; i < N; i++) {
		cin >> d[i];
	}
	j = 0;
	for (i = 0; i <= N; ) {
		if (sum < M) {
			sum += d[i];
			i++;
		}
		else {
			if (sum - M < max) {
				max = sum - M;
				f.clear();
				e.clear();
				f.push_back(j + 1);
				e.push_back(i);
				sum -= d[j++];
			}
			else if (sum - M == max) {
				f.push_back(j + 1);
				e.push_back(i);
				sum -= d[j++];
			}
			else {
				sum -= d[j++];
			}
		}
	}
	k = f.size();
	for (i = 0; i < k; i++) {
		cout << f[i] << "-" << e[i] << endl;
	}
	//fclose(stdin);
	return 0;
}