#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

#define OPEN 0
#define CLOSE (21 - 8) * 60 * 60

class P {
public:
	int h, m, s, p, vip, t, wt, st;
	P(int hh, int mm, int ss, int pp, int v) :h(hh), m(mm), s(ss), p(pp), vip(v) {
		t = (h - 8) * 60 * 60 + m * 60 + s;
		wt = -1;
		st = -1;
	};
	void printST() {
		int hh, mm, ss, wait;
		ss = s + wt % 60;
		mm = m + (wt / 60) % 60;
		hh = h + wt / (60 * 60);
		wait = ((wt + 59) / 60) % 60;
		printf("%02d:%02d:%02d %d\n", hh, mm, ss, wait);
		//cout << hh << ":" << mm << ":" << ss << " " << wait << endl;
	}
	void print() {
		if (st < -1)
			return;
		else {
			printf("%02d:%02d:%02d ", h, m, s);
			printST();
		}
	}
	void serve(int time) {
		st = time;
		wt = st - t;
	}
};

class T {
public:
	int open, cnt, vip, id;
};

bool arriveTime(P &p1, P &p2) {
	return p1.t < p2.t;
}

bool serve(P &p1, P &p2) {
	return p1.st < p2.st;
}

int N, K, M;

int main() {
	int i, j, k, kk, hh, mm, ss, p, vip;
	char ch;
	cin >> N;
	vector<P> player;
	for (i = 0; i < N; i++) {
		cin >> hh >> ch >> mm >> ch >> ss >> p >> vip;
		P tmp(hh, mm, ss, p, vip);
		player.push_back(tmp);
	}
	cin >> K >> M;
	T* tbl = new T[K];
	int vipNo;
	for (i = 0; i < K; i++) {		// init tables
		tbl[i].cnt = 0;
		tbl[i].open = 1;
		tbl[i].vip = 0;
		tbl[i].id = -1;
	}
	sort(player.begin(), player.end(), arriveTime);
	for (i = 0; i < M; i++) {
		cin >> vipNo;
		tbl[vipNo - 1].vip = 1;
	}
	k = 0;
	kk = 0;		// vip
	P *tmp;
	for (i = 0; i < CLOSE && k < N; i++) {
		for (j = 0; j < K; j++) {		// re open a table
			if (!tbl[j].open) {
				tmp = &player[tbl[j].id];
				if ((*tmp).st + (*tmp).p * 60 == i) {
					tbl[j].open = 1;
					tbl[j].id = -1;		// one table is avaliable now
					//cout << "time = " << i << ", open : " << j << endl;
				}
			}
			if (tbl[j].open) {
				if (tbl[j].vip) {
					kk = k;
					while (player[kk].t <= i) {
						if (player[kk].vip == 0 || player[kk].st != -1) {	//not vip or has served
							kk++;
							continue;
						}
						if (player[kk].t <= i && player[kk].vip) {		// a vip is in the queue
							tbl[j].id = kk;
							tbl[j].open = 0;
							tbl[j].cnt++;
							player[kk].serve(i);
							//cout << "time = " << i << ", use : " << j << endl;
							if (kk == k)
								k++;
							break;
						}
					}
					if (tbl[j].open) {	//no vip in queue
						while (player[k].st != -1) k++;		// found 1st player in the queue
						if (player[k].t <= i) {
							tbl[j].id = k;
							tbl[j].open = 0;
							tbl[j].cnt++;
							player[k].serve(i);
							//cout << "time = " << i << ", use : " << j << endl;
							k++;
						}
					}
				}
				else		// not a vip table
				{
					while (player[k].st != -1) k++;		// found 1st player in the queue
					if (player[k].t <= i) {
						tbl[j].id = k;
						tbl[j].open = 0;
						tbl[j].cnt++;
						player[k].serve(i);
						//cout << "time = " << i << ", use : " << j << endl;
						k++;
					}
				}
				
			}
		}
	}
	sort(player.begin(), player.end(), serve);
	for (i = 0; i < N; i++) {
		if (player[i].st == -1)
			continue;
		else {
			player[i].print();
		}
	}
	for (i = 0; i < K - 1; i++) {
		cout << tbl[i].cnt << " ";
	}
	cout << tbl[i].cnt;
	return 0;
}
