#include <iostream>

using namespace std;

#define infinit 1<<28

int main(){
	int N,M,C1,C2;
	cin >> N;
	cin >> M;
	cin >> C1;
	cin >> C2;

	int i,j;
	int *teamNum = new int[N];

	for(i=0;i<N;i++)
		cin >> teamNum[i];

	int map[N][N] , dist[N] , num[N] , amount[N];
	int c1,c2,l;
	bool known[N];

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			map[i][j]=infinit;
		}
		amount[i] = 0;
		num[i] =0;
		known[i] = false;
		dist[i] = infinit;
	}

	for(i=0;i<M;i++){
		cin >> c1;
		cin >> c2;
		cin >> l;
		map[c1][c2]=l;
		map[c2][c1]=l;
	}

	amount[C1] = teamNum[C1];
	num[C1] = 1;
	dist[C1] = 0;

	int minV,minDist;

	for(j=0;j<N;j++){
		minDist = infinit;
		for(i=0;i<N;i++){
			if(!known[i]&&dist[i]<minDist){
				minDist = dist[i];
				minV = i;
			}
		}
		known[minV] = true;
		for(i=0;i<N;i++){
			if(!known[i] && dist[i]>dist[minV]+map[minV][i]){
				dist[i] = dist[minV]+map[minV][i];
				num[i] = num[minV] ;
				amount[i] = amount[minV] + teamNum[i];
			}
			else if(!known[i] && dist[i] == dist[minV]+map[minV][i]){
				num[i] += num[minV];
				if(amount[i]<amount[minV]+teamNum[i])
					amount[i] = amount[minV]+teamNum[i];
			}
		}
		if(minDist == infinit || C2==minV) break;
	}

	cout << num[C2] << " " << amount[C2];

	delete[] teamNum;
	return 0;
}
