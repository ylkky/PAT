#include<iostream>
#include<stack>
using namespace std;

char s[11];

int main() {
	int i, l, n;
	bool flag = false;
	stack<char *> s;
	char  num[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	char bits[9][5] = { "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi" };
	scanf("%d", &n);
	if (n < 0) {
		flag = true;
		n = 0 - n;
	}
	if (n == 0)
		cout << num[n];
	else {
		i = 0;
		for (i = 0; n % 10 == 0; i++, n /= 10);
		while (n) {
			l = n % 10;
			if (l > 0) {
				if(i != 0)
					s.push(bits[i]);
				s.push(num[l]);
				n = n / 10;
				i++;
			}
			else {
				s.push(num[l]);
				while (l == 0) {
					n = n / 10;
					l = n % 10;
					if (i % 4 == 0)
						s.push(bits[i]);
					i++;
				}
			}
		}
		if (flag) {
			cout << "Fu ";
		}
		cout << s.top();
		s.pop();
		while (!s.empty()) {
			cout << " " << s.top();
			s.pop();
		}
	}
	return 0;
}