#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define MAX (17 - 8) * 60

void printFormat(int wt);
int *buildTable(int *time, int n, int m, int k);

int main() {
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
	int *t = new int[K];
	int i, q, j, wt;
	for (i = 0; i < K; i++)
		cin >> t[i];
	int* table;
	table = buildTable(t, N, M, K);
	for (i = 0; i < Q; i++) {
		cin >> q;
		wt = table[q - 1];
		printFormat(wt);
	}
	return 0;
}

void printFormat(int wt) {
	if (wt < 0 )
		cout << "Sorry" << endl;
	else {
		int hh, mm;
		hh = wt / 60 + 8;
		mm = wt % 60;
		printf("%02d:%02d\n", hh, mm);
	}
}
/*  n = 总窗口数
	m = 窗前队伍人数
	k = 总人数
*/
int* buildTable(int *time, int n, int m, int k) {
	int i, j, ii;
	int* res = new int[k];
	vector<int> * lines = new vector<int>[n];
	for (i = 0; i < k; i++)
		res[i] = -1;	//initial
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if(i * n + j < k)
				lines[j].push_back(n * i + j);
		}
	}
	j = k > m * n ? m * n : k; 	// 一开始在窗口前的人的编号 + 1
	for (i = 1; i <= MAX; i++) {	//时间
		for (ii = 0; ii < n; ii++) {	// 遍历这一分钟每个窗口前的情况
			if (!lines[ii].empty()) {
				time[lines[ii].front()]--;
				if (time[lines[ii].front()] == 0) {
					res[lines[ii].front()] = i;
					if (i != MAX) {
						lines[ii].erase(lines[ii].begin());
						if (j < k)
							lines[ii].push_back(j++);
					}
					else
						lines[ii].clear();
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (!lines[i].empty()) {
			ii = lines[i].front();
			res[ii] = time[ii] + MAX;
		}
	}
	return res;
}