#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, L, H;

struct peopleNode {
	int id, v, t;
};
typedef peopleNode person;

bool cmp(person &p1, person &p2) {
	if (p1.t + p1.v != p2.t + p2.v)
		return p1.t + p1.v > p2.t + p2.v;
	else{
		if (p1.v != p2.v)
			return p1.v > p2.v;
		else
			return p1.id < p2.id;
	}
}


int main() {
	//freopen("1", "r", stdin);
	int i, m;
	vector<person> sage, n, f, sma;;
	cin >> N >> L >> H;
	for (i = 0; i < N; i++) {
		person p;
		cin >> p.id >> p.v >> p.t;
		if (p.v >= H && p.t >= H)
			sage.push_back(p);
		else if (p.v >= H && p.t >= L)
			n.push_back(p);
		else if (p.v >= p.t && p.t >= L)
			f.push_back(p);
		else if (p.v >= L && p.t >= L)
			sma.push_back(p);
	}
	m = sage.size() + n.size() + f.size() + sma.size();
	cout << m << endl;
	sort(sage.begin(), sage.end(), cmp);
	sort(n.begin(), n.end(), cmp);
	sort(f.begin(), f.end(), cmp);
	sort(sma.begin(), sma.end(), cmp);
	for (i = 0; i < sage.size(); i++)
		printf("%08d %d %d\n", sage[i].id, sage[i].v, sage[i].t);
	for (i = 0; i < n.size(); i++)
		printf("%08d %d %d\n", n[i].id, n[i].v, n[i].t);
	for (i = 0; i < f.size(); i++)
		printf("%08d %d %d\n", f[i].id, f[i].v, f[i].t);
	for (i = 0; i < sma.size(); i++)
		printf("%08d %d %d\n", sma[i].id, sma[i].v, sma[i].t);
	//fclose(stdin);
	return 0;
}