#include<iostream>
#include<algorithm>
using namespace std;

int NC, NP;
int *c, *p;

int cmp(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}
int main() {
	//freopen("1.txt", "r", stdin);
	int i, j;
	long int sum = 0;
	cin >> NC;
	c = new int[NC];
	for (i = 0; i < NC; i++)
		cin >> c[i];
	cin >> NP;
	p = new int[NP];
	for (i = 0; i < NP; i++)
		cin >> p[i];
	qsort(c, NC, sizeof(int), cmp);
	qsort(p, NP, sizeof(int), cmp);
	for (i = 0; c[i] > 0 && p[i] > 0; i++) {
		sum += c[i] * p[i];
	}
	for (i = NC - 1, j = NP - 1; c[i] < 0 && p[j] < 0; i--, j--) {
		sum += c[i] * p[j];
	}
	cout << sum << endl;
	//fclose(stdin);
	return 0;
}