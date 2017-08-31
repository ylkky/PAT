#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Stu {
public:
	string name, id;
	int grade;
};

int N;

bool cmp(Stu &s1, Stu &s2) {
	return s1.grade < s2.grade;
}

int main() {
	//freopen("case.txt", "r", stdin);
	int i;
	vector<Stu> f, m;
	char ch;
	cin >> N;
	for (i = 0; i < N; i++) {
		Stu s;
		cin >> s.name;
		cin >> ch;
		cin >> s.id;
		cin >> s.grade;
		if (ch == 'M')
			m.push_back(s);
		else if (ch == 'F')
			f.push_back(s);
	}
	if (!f.empty()) {
		sort(f.begin(), f.end(), cmp);
		cout << f.back().name << " " << f.back().id << endl;
	}
	else {
		cout << "Absent" << endl;
	}

	if (!m.empty()) {
		sort(m.begin(), m.end(), cmp);
		cout << m.front().name << " " << m.front().id << endl;
	}
	else {
		cout << "Absent" << endl;
	}

	if (m.empty() || f.empty())
		cout << "NA" << endl;
	else {
		cout << f.back().grade - m.front().grade << endl;
	}
	//fclose(stdin);
	return 0;
}