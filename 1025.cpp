#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int N;

class Testee {
public:
	string id;
	int score, local, local_rank;
	Testee(string idd, int s, int l) :id(idd), score(s), local(l) {};
	void localRank(int r) {
		local_rank = r;
	};
};

bool ranking(Testee &t1, Testee &t2) {
	if (t1.score < t2.score)
		return true;
	else if (t1.score == t2.score)
		return t1.id > t2.id;
	return false;
}

int main() {
	int i, ii, j, k, score, cnt = 0, rank, max;
	vector<Testee> *tes;
	vector<Testee> te, tte;
	vector<int> sr;		// same rank
	string id;
	cin >> N;
	tes = new vector<Testee>[N];
	int *ptr = new int[N];
	for (i = 0; i < N; i++) {
		ptr[i] = 0;
		cin >> k;
		cnt += k;
		for (j = 0; j < k; j++) {
			cin >> id;
			cin >> score;
			Testee t(id, score, i);
			tes[i].push_back(t);
		}
		sort(tes[i].begin(), tes[i].end(), ranking);
		rank = 1; 
		max = tes[i].back().score;
		for (j = k - 1, ii = 1; j > -1; j--, ii++) {
			if (max > tes[i][j].score) {
				max = tes[i][j].score;
				rank = ii;
			}
			tes[i][j].localRank(rank);
			tte.push_back(tes[i][j]);
		}
	}
	cout << cnt << endl;
	sort(tte.begin(), tte.end(), ranking);
	j = 1;
	max = tte.back().score;
	rank = 1;
	for (i = cnt - 1; i > -1; i--, j++) {
		if (max > tte[i].score) {
			rank = j;
			max = tte[i].score;
		}
		cout << tte[i].id << " " << rank << " " << tte[i].local + 1 << " " << tte[i].local_rank << endl;
	}
	return 0;
}