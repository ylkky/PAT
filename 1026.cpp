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
	P(int hh, int mm, int ss, int pp, int v) :h(hh), m(mm), s(ss), vip(v) {
		t = (h - 8) * 60 * 60 + m * 60 + s;
		wt = -1;
		st = -1;
		if (pp > 120)
			p = 120;
		else
			p = pp;
	};
	void printST() {
		int hh, mm, ss, wait;
		ss = s + wt % 60;
		mm = m + (wt / 60) % 60;
		hh = h + wt / (60 * 60);
		wait = ((wt + 30) / 60) % 60;
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
		if (hh > 21 || hh < 8)
			continue;
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
	vector<int> vips;
	P *tmp;
	for (i = 0; i < CLOSE && k < N; i++) {
		for (j = 0; j < K; j++) {		// re open a table
			if (!tbl[j].open) {
				tmp = &player[tbl[j].id];
				if ((*tmp).st + (*tmp).p * 60 == i) {
					tbl[j].open = 1;		//reopen
					tbl[j].id = -1;		// one table is avaliable now
					//cout << "time = " << i << ", open : " << j << endl;
				}
			}
		}
		kk = k;
		vips.clear();
		while (kk < N && player[kk].t <= i) {		// all palyers in the queue
			if(player[kk].vip && player[kk].st == -1)		//find vip players in  the queue
				vips.push_back(kk);
			kk++;
		}
		for (j = 0; j < K && !vips.empty(); j++) {	//allocate vip tables first
			if (tbl[j].open && tbl[j].vip) {
				kk = vips.front();
				vips.erase(vips.begin());
				tbl[j].id = kk;
				tbl[j].open = 0;
				tbl[j].cnt++;
				player[kk].serve(i);
				player[kk].print();
			}
		}
		for (j = 0; j < K; j++) {
			if (tbl[j].open) {
				while (k < N && player[k].st != -1) k++;		// find 1st player in the queue
				if (k < N && player[k].t <= i) {
					tbl[j].id = k;
					tbl[j].open = 0;
					tbl[j].cnt++;
					player[k].serve(i);
					//cout << "time = " << i << ", use : " << j << endl;
					player[k].print();
					k++;
				}
			}
		}
	}
	for (i = 0; i < K - 1; i++) {
		cout << tbl[i].cnt << " ";
	}
	cout << tbl[i].cnt;
	return 0;
}
