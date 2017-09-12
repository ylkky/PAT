#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;

class Stu {
public:
	int grade;
	char name[11], id[11];
};

bool cmp(Stu &s1, Stu &s2) {
	return s1.grade > s2.grade;
}

int main() {
	freopen("1", "r", stdin);
	int i, g1, g2;
	cin >> N;
	vector<Stu> v, res;
	for (i = 0; i < N; i++) {
		Stu s;
		scanf("%s%s%d", s.name, &s.id, &s.grade);
		v.push_back(s);
	}
	cin >> g1 >> g2;
	for (i = 0; i < N; i++) {
		if (v[i].grade >= g1 && v[i].grade <= g2)
			res.push_back(v[i]);
	}
	v.clear();
	if (res.empty())
		cout << "NONE";
	else {
		N = res.size();
		sort(res.begin(), res.end(), cmp);
		for (i = 0; i < N; i++) {
			cout << res[i].name << " " << res[i].id <<endl;
		}
	}
	fclose(stdin);
	return 0;
}