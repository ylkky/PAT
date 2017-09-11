#include<iostream>
#include<memory.h>
using namespace std;

int MSize, N;
int *T;

// Pay attention to the situation MSize = 1

bool isPrime(int n) {
	int i;
	if (n == 1)
		return false;
	for (i = 3; i * i <= n; i++) {
		if (n % i == 0)
			return false;;
	}
	return true;
}
void findPrime() {
	int i;
	i = MSize;
	if (i == 1)
		MSize = 2;
	if (MSize == 2)
		return;
	if (i % 2 == 0) i++;
	while (!isPrime(i)) {
		i += 2;
	}
	MSize = i;
}

void insert(int key) {
	int i, pos = key, j;
	for (i = 0; i < MSize; i++) {
		j = (i * i + pos) % MSize;
		if (T[j] == -1) {
			T[j] = key;
			printf("%d", j);
			return;
		}
	}
	printf("-");
}

int main() {
	//freopen("1", "r", stdin);
	int i, key;
	cin >> MSize >> N;
	findPrime();
	T = new int[MSize];
	for (i = 0; i < MSize; i++)
		T[i] = -1;
	for (i = 0; i < N; i++) {
		cin >> key;
		if (i != 0)
			printf(" ");
		insert(key);
	}
	printf("\n");
	//fclose(stdin);
	return 0;
}