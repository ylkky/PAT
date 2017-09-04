#include<iostream>
#include<cstring>
using namespace std;

typedef struct _Person Person;
struct _Person {
	char name[9];
	int age, w;
};

int N, K, M, fnum;
int *f;
Person *pp;

int cmp(const void *p1, const void *p2) {
	Person *t1, *t2;
	t1 = (Person *)p1;
	t2 = (Person *)p2;
	if (t1->w != t2->w)
		return t2->w - t1->w;
	else if (t1->age != t2->age)
		return t1->age - t2->age;
	else
		return strcmp(t1->name, t2->name);
}

void find(int minA, int maxA) {
	int i, j;
	j = 0;
	for (i = 0; i < fnum && j < M; i++) {
		if (pp[f[i]].age < minA)
			continue;
		if (pp[f[i]].age > maxA)
			continue;
		printf("%s %d %d\n", pp[f[i]].name, pp[f[i]].age, pp[f[i]].w);
		j++;
	}
	if (j == 0)
		printf("None\n");
}

int main() {
	//freopen("1.txt", "r", stdin);
	int i, minA, maxA, age[201];
	scanf("%d%d", &N, &K);
	pp = (Person *)malloc(sizeof(Person) * N);
	memset(pp, 0, sizeof(Person) * N);
	f = (int *)malloc(sizeof(int) * N);
	memset(f, 0, sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%s%d%d", pp[i].name, &pp[i].age, &pp[i].w);
	}
	qsort(pp, N, sizeof(Person), cmp);
	memset(age, 0, sizeof(int) * 201);
	fnum = 0;
	for (i = 0; i < N; i++) {
		if (age[pp[i].age]++ < 101)
			f[fnum++] = i;
	}
	for (i = 0; i < K; i++) {
		scanf("%d%d%d", &M, &minA, &maxA);
		printf("Case #%d:\n", i + 1);
		find(minA, maxA);
	}
	//fclose(stdin);
	return 0;
}