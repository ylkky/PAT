#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define CLOSE (17 - 8) * 60 * 60
#define START 0
class Client {
public:
	int h, m, s, at, st, wt, p;
	Client(int hh, int mm, int ss, int pp): h(hh), m(mm), s(ss), p(pp){
		at = (h - 8) * 60 * 60 + m * 60 + s;		// arrive time(in mins)
		st = at - 1;	// serve time
		wt = -1;		// wait time
	}
	void serve(int t) {
		st = t;
		wt = st - at;
	}
};

bool lessThan(Client &c1, Client &c2);
void calc(vector<Client> v, int k);
void print(double sum);


int main() {
	int i, N, K, hh, mm, ss, p;
	char ch;
	cin >> N >> K;
	vector<Client> v;
	for (i = 0; i < N; i++) {
		cin >> hh >> ch >> mm >> ch >> ss >> p;
		Client c(hh, mm, ss, p);
		v.push_back(c);
	}
	sort(v.begin(), v.end(), lessThan);
	calc(v, K);
	return 0;
}

bool lessThan(Client &c1, Client &c2) {
	return c1.at < c2.at;
}

void calc(vector<Client> v, int k) {
	int i, j, ii, n = v.size();
	double sum = 0;
	int *win = new int[k];
	for (i = 0; i < k; i++)
		win[i] = -1;
	for (i = 0; i < k && i < n; i++) {		// 刚开门时排队的用户
		if (v[i].at < START ) {
			win[i] = i;
			v[i].serve(START);
		}
		else
			break;
	}
	i = n > i ? i : n;
	for (j = 1; ; j++) {		// 所有在关门前到的客户都会被服务
		for (ii = 0; ii < k; ii++) {
			if (win[ii] != -1 && v[win[ii]].st + v[win[ii]].p * 60 == j) {		//in ii-th window, if costomer is leave
				if (i < n && v[i].at <= j) {
					win[ii] = i;
					v[i].serve(j);
					i++;
				}
				else
					win[ii] = -1;
			}
			else if (win[ii] == -1) {
				if (i < n && v[i].at <= j) {
					win[ii] = i;
					v[i].serve(j);
					i++;
				}
			}
		}
		if (i >= n || v[i].at > CLOSE)
			break;
	}
	for (j = 0; j < i; j++)
		sum += v[j].wt;
	sum = sum / i;
	printf("%.1lf\n",sum / 60);
}
