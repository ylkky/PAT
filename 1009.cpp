#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
  int k[2];
  double a[2][1001],p[2002];
  int i,j;

  for(i=0;i<1001;i++){
    a[1][i]=0;
    a[0][i]=0;
    p[2*i]=0;
    p[2*i+1]=0;
  }

  int n;
  double an;

  for(i=0;i<2;i++){
    cin >> k[i];
    for(j=0;j<k[i];j++){
      cin >> n;
      cin >> an;
      a[i][n] = an;
    }
  }


  for(i=0;i<1001;i++){
    for(j=0;j<1001;j++){
      p[i+j]+=a[0][i]*a[1][j];
    }
  }

  int count=0;

  for(i=0;i<2001;i++)
    if(p[i]!=0) count++;

  cout << count;

  for(i=2001;i>0;){
    if(p[--i]!=0){
      cout << " " << i;
      printf(" %.1lf",p[i]);
    }
  }

  return 0;
}
