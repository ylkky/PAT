#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXX 26*26*26*10
int N, K;

int myHash(const char* s){
  int i, ret = 0;
  for( i = 0; i < 3; i++)
    ret = ret * 26 + s[i] - 'A';
  ret = ret * 10 + s[3] - '0';
  return ret;
}

vector<int> v[MAXX];

int main(){
  int i, j, k, ii, ni;
  char name[5];
  scanf("%d%d", &N, &K);
  for(i = 0; i < K; i++){
    scanf("%d%d", &k, &ni);
    for(j = 0; j < ni; j++){
      scanf("%s", name);
      ii = myHash(name);
      v[ii].push_back(k);
    }
  }
  for(i = 0; i < N; i++){
    scanf("%s", name);
    ii = myHash(name);
    k = v[ii].size();
    printf("%s %d", name, k);
    sort(v[ii].begin(), v[ii].end());
    for(j = 0; j < k; j++){
        printf(" %d", v[ii][j]);
    }
    printf("\n");
  }
  return 0;
}
