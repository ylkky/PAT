#include<iostream>

using namespace std;

int t;
long long int A, B, C;

int main() {
	//freopen("1", "r", stdin);
	int i, flag;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%lld%lld%lld", &A, &B, &C);
		cout << "Case #" << i + 1 << ": ";
		if (A > 0 && B > 0) {
			if (C < A || C < B)
				flag = 1;
			else {		// C > A && C > B
				flag = (C - A) < B ? 1 : 0;
			}
		}
		else if (A < 0 && B < 0) {
			if (C >= A || C >= B)
				flag = 0;
			else {
				flag = (C - A) < B ? 1 : 0;
			}
		}
		else
			flag = (A + B) > C ? 1 : 0;
		if (flag == 0)
			cout << "false" << endl;
		else
			cout << "true" << endl;
	}
	//fclose(stdin);
	return 0;
}