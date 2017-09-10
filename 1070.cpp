#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, D;

class Mcake {
public:
	double price, profit, amount;
	void profits() {
		if (amount == 0)
			profit = -1;
		else
			profit = price / amount;
	}
};

bool cmp(Mcake &m1, Mcake &m2) {
	return m1.profit > m2.profit;
}

int main() {
	//freopen("1", "r", stdin);
	int i;
	double sum = 0, w = 0, a;
	cin >> N >> D;
	vector<Mcake> m;
	for (i = 0; i < N; i++) {
		cin >> a;
		Mcake tmp;
		tmp.amount = a;
		m.push_back(tmp);
	}
	for (i = 0; i < N; i++) {	
		cin >> m[i].price;
		m[i].profits();
	}
	sort(m.begin(), m.end(), cmp);
	for (i = 0; i < N && w < D; i++) {
		if (w + m[i].amount <= D) {
			sum += m[i].price;
			w += m[i].amount;
		}
		else {
			sum += (D - w) * m[i].profit;
			w = D;
		}
	}
	printf("%.2lf\n", sum);
	//fclose(stdin);
	return 0;
}