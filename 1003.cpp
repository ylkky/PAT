#include <iostream>

using namespace std;

int main(){
	int N,M,C1,C2;
	cin >> N;
	cin >> M;
	cin >> C1;
	cin >> C2;
	
	int i;
	int *teamNum = new int[N];
	
	for(i=0;i<N;i++)
		cin >> teamNum[i];
	
	int map[N][N] , length[N][N] , num[N][N];
	int c1,c2,l;
	
	for(i=0;i<N;i++)
		for(int j=0;j<N;j++){
			map[i][j]=0;
			length[i][j]=0;
			num[i][j]=0;
		}
		
	for(i=0;i<M;i++){
		cin >> c1;
		cin >> c2;
		cin >> l;
		map[c1][c2]=l;
	}
	
	int min;
	
	for(i=0;i<N;i++){
		for(int j=0;j<N;j++){
			
		}
	}
	
	return 0;
}
