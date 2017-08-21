#include<iostream>

using namespace std;

void convert(int a) {
	char ch;
	if (a < 10)
		cout << "0" << a + '0';
	else if (a < 13) {
		ch = a - 10 + 'A';
		cout << "0" << ch;
	}
	else {
		int i;
		i = a / 13;
		a = a % 13;
		if (i > 10)
			ch = i - 10 + 'A';
		else
			ch = i + '0';
		cout << ch;
		ch = a > 10 ? a - 10 + 'A' : a + '0';
		cout << ch;
	}
}
int main() {
	int a;
	cout << "#";
	for (int i = 0; i < 3; i++) {
		cin >> a;
		convert(a);
	}
	return 0;
}