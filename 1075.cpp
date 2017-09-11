#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 10001
int N, K, M;
int *p;
/*
Attention:
ps = partial score
if all ps = -1, this user won't be printed => need flag
only new ps > old ps, then update
*/
class user {
public:
	int id, tscore, *s, cnt, sub;
	user() {
		id = -1;
		tscore = 0;
		cnt = 0;
		sub = 0;
	}
	void calc(int k) {
		tscore = 0;
		for (int i = 0; i < k; i++) {
			if (s[i] > 0)
				tscore += s[i];
		}
	}
};

int cmp(const void *u1, const void *u2) {
	user *p1, *p2;
	p1 = (user *)u1;
	p2 = (user *)u2;
	if (p1->tscore != p2->tscore)
		return p2->tscore - p1->tscore;
	else if (p1->cnt != p2->cnt)
		return p2->cnt - p1->cnt;
	else
		return p1->id - p2->id;
}

int main() {
	//freopen("1", "r", stdin);
	int i, j, uid, pid, ps, rank;
	cin >> N >> K >> M;
	p = new int[K];
	user *u = new user[N];
	for (i = 0; i < K; i++)
		cin >> p[i];
	// init
	for (i = 0; i < N; i++) {
		u[i].s = new int[K];
		for (j = 0; j < K; j++)
			u[i].s[j] = -2;
		u[i].id = i + 1;
	}
	//input
	for (i = 0; i < M; i++) {
		cin >> uid >> pid >> ps;
		if (ps == -1 && ps > u[uid - 1].s[pid - 1]) {
			u[uid - 1].s[pid - 1] = 0;
		}
		else {
			if (ps > u[uid - 1].s[pid - 1]) {
				u[uid - 1].s[pid - 1] = ps;
				u[uid - 1].sub = 1;
				if (ps == p[pid - 1])
					u[uid - 1].cnt++;
			}
			else if (ps == 0) {
				u[uid - 1].sub = 1;
			}
		}
	}
	for (i = 0; i < N; i++) {
		if (u[i].sub > 0) {
			u[i].calc(K);
		}
		else
			u[i].tscore = -1;
	}
	qsort(u, N, sizeof(user), cmp);
	ps = -1;
	rank = 1;
	for (i = 0; i < N; i++) {
		if (u[i].sub < 1)
			break;
		else {
			if (u[i].tscore != ps) {
				rank = i + 1;
				ps = u[i].tscore;
			}
			printf("%d %05d %d", rank, u[i].id, u[i].tscore);
			for (int j = 0; j < K; j++) {
				if (u[i].s[j] == -2)
					printf(" -");
				else
					printf(" %d", u[i].s[j]);
			}
			printf("\n");
		}
	}
	//fclose(stdin);
	return 0;
}