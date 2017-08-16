#include <iostream>

using namespace std;

int main(){
  int k,i,j;
  cin >> k;
  int a[2][k];
  int *post,*in;

  for(i=0;i<2;i++){
    for(j=0;j<7;j++)
      cin >> a[i][j];
  }
  post = a[0];
  in = a[1];

  

  return 0;
}
