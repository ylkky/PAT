#include<iostream>
#include<limits>
using namespace std;

#define MAXD cap * cost
#define INFINITY 999999999
struct sta {
	double p;
	double dist;
};
int cap, des, cost, N;
struct sta *s;

int findFirstMin(int v) {
	int i = v, idx = -1;
	double dist = s[v].dist, minp = INFINITY;
	if (v + 1 < N && s[v + 1].dist - dist > MAXD)
		return -2;
	else if (v + 1 == N && des - s[v].dist > MAXD)
		return -2;
	else if (v == 0 && s[v].dist != 0)
		return -2;

	for (i = v + 1; i < N && s[i].dist - dist <= MAXD; i++) {
		if (s[i].p < minp) {
			minp = s[i].p;
			idx = i;
		}
	}
	if (minp > s[v].p) {
		if (s[v].dist + MAXD >= des)
			return -1;
		else {
			return idx;
		}
	}
	else {
		for (i = v + 1; i < N && s[i].dist - dist <= MAXD; i++) {
			if (s[i].p < s[v].p) {
				idx = i;
				break;
			}
		}
		return idx;
	}
}

int cmp(const void *s1, const void *s2) {
	return (int)((struct sta*)s1)->dist - (int)((struct sta*)s2)->dist;
}

int main() {
	//freopen("case.txt", "r", stdin);
	int i, v;
	double dist = 0, sum = 0, rest = 0;
	cin >> cap >> des >> cost >> N;
	s = new struct sta[N];
	for (i = 0; i < N; i++) {
		cin >> s[i].p;
		cin >> s[i].dist;
	}
	qsort(s, N, sizeof(struct sta), cmp);
	for (i = 0; dist <= des;) {
		v = findFirstMin(i);
		if (v < 0)
			break;
		else if (v >= 0) {		//Ӧ���ж���һ���ͼ۵͵�վ��ȵ�ǰ�ͼ���Σ�����ߵĻ����ڵ�ǰ������Ȼ���ߵ���һ��վ���ٴ���
			dist = s[v].dist;
			if (s[v].p > s[i].p) {		//��һ��վ����ͼ۸��� ����Ӧ�ü�����
				sum += (cap - rest) * s[i].p;
				rest = cap - (s[v].dist - s[i].dist) / cost;		//����һ��վ��ʱʣ�µ��� = ���� - ·�����ĵ�
			}
			else {		// ��һ��վ���ͼ۱Ƚϱ��ˣ�ֻҪ�ӵ���һ��վ����;͹���
				sum += ((s[v].dist - s[i].dist) / cost - rest)* s[i].p;		// �۸� = ·����Ҫ�� - ���������е�
				rest = 0;
			}
			i = v;
		}	
	}
	if (v == -1) {
		sum += ((des - s[i].dist) / cost - rest) * s[i].p;
		printf("%.2lf\n", sum);
	}
	else {
		if( i != 0)
			dist += MAXD;
		printf("The maximum travel distance = %.2lf\n", dist);
	}
	//fclose(stdin);
	return 0;
}