#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
  int i,j;
  char ch[4]="WTL";
  int max;
  double odd[3],p=1.0;

  for(i=0;i<3;i++){
    max=0;
    for(j=0;j<3;j++){
      cin >> odd[j];
      if(odd[max]<odd[j])
        max=j;
    }
    cout << ch[max] << " ";
    p *= odd[max];
  }
  p = (p*0.65 - 1) * 2;
  printf("%.2lf",p);
  return 0;
}
