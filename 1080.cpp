#include<iostream>
#include<set>
using namespace std;

int N, M, K;
int *quota;

class Stu {
public:
	int id, Ge, Gi, t;
	int *c;
};

Stu *stu;
set<int> *res;

int cmp(const void *s1, const void *s2) {
	Stu *p1, *p2;
	p1 = (Stu *)s1;
	p2 = (Stu *)s2;
	if (p1->t != p2->t) {
		return p2->t - p1->t;
	}
	else
		return p2->Ge - p1->Ge;
}

int main() {
	freopen("1", "r", stdin);
	int i, j, rank, prege,  pret;
	int *cnt;
	scanf("%d%d%d", &N, &M, &K);
	quota = new int[M];
	cnt = new int[M];
	res = new set<int>[M];
	for (i = 0; i < M; i++) {
		cnt[i] = 0;
		scanf("%d", &quota[i]);
	}
	stu = new Stu[N];
	for (i = 0; i < N; i++) {
		stu[i].id = i;
		scanf("%d%d", &stu[i].Ge, &stu[i].Gi);
		stu[i].t = (stu[i].Ge + stu[i].Gi);
		stu[i].c = new int[K];
		for (j = 0; j < K; j++)
			scanf("%d", &stu[i].c[j]);
	}
	qsort(stu, N, sizeof(Stu), cmp);
	pret = -1;
	prege = -1;
	// 学生已经按照名次排好， 接下来要分配学校
	for (i = 0; i < N; i++) {
		if (stu[i].t != pret || stu[i].Ge != prege) {
			rank = i + 1;
			pret = stu[i].t;
			prege = stu[i].Ge;
		}
		for (j = 0; j < K; j++) {
			if (quota[stu[i].c[j]] > 0) {
				res[stu[i].c[j]].insert(stu[i].id);
				cnt[stu[i].c[j]] = rank;
				quota[stu[i].c[j]]--;
				break;
			}
			else if (cnt[stu[i].c[j]] == rank) {
				res[stu[i].c[j]].insert(stu[i].id);
				break;
			}
		}
	}
	set<int>::iterator it;
	for (i = 0; i < M; i++) {
		for (it = res[i].begin(); it != res[i].end(); it++) {
			if (it == res[i].begin())
				cout << *it;
			else
				cout << " " << *it;
		}
		cout << endl;
	}
	fclose(stdin);
	return 0;
}