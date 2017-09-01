#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MAXN 201
#define MAXL 10001

int N, M, L;
int m[MAXL][MAXN];

int main(){
  int i, j, length = 0;
  int *f, *s;
  scanf("%d", &N);
  scanf("%d", &M);
  f = (int *)malloc(sizeof(int) * M);
  for(i = 0; i < M; i++){
    scanf("%d", &f[i]);
    m[0][i] = 0;
  }
  scanf("%d", &L);
  s = (int *)malloc(sizeof(int) * L);
  for(i = 0; i < L; i++){
    scanf("%d", &s[i]);
    m[i][0] = 0;
  }
  // m = (int **)malloc(sizeof(int *) * (L + 1));
  // for(i = 0; i <= L; i++){
  //   m[i] = (int *)malloc(sizeof(int) * (M + 1));
  //   memset( &m[i], 0, sizeof(int) * (M + 1));
  // }

  for(i = 1; i <= L; i++){
    for(j = 1; j <= M; j++){
      if(s[i - 1] == f[j - 1]){
        m[i][j] = m[i - 1][j] + 1;
        if(length < m[i][j])
          length = m[i][j];
      }
      else{
        m[i][j] = m[i][j - 1] > m[i - 1][j] ? m[i][j - 1] : m[i - 1][j];
      }
    }
  }
  printf("%d\n", length);
}
