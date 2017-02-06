#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class signTime{
public:
  int h,m,s;
  signTime();
  signTime(int hh, int mm, int ss):h(hh),m(mm),s(ss){}
  ~signTime(){};

};

// if t1>t2,ture
bool compare(signTime* t1, signTime* t2){
  if(t1->h==t2->h)
    if(t1->m==t2->m)
      if(t1->s>t2->s)
        return true;
      else return false;
    else return t1->m>t2->m;
  else  return t1->h>t2->h;

//  return true;
}

int main(){
  int m;
  cin >> m;
  char* id[m];
  vector<signTime> stIn,stOut;
  char ch;
  int hh,mm, ss;
  for(int i=0; i<m;i++){
    id[i]= new char[16];
    scanf("%s", id[i]);
    scanf("%d:%d:%d",&hh,&mm,&ss );
    signTime tempIn(hh,mm,ss);
    stIn.push_back(tempIn);
    scanf("%d:%d:%d",&hh,&mm,&ss );
    signTime tempOut(hh,mm,ss);
    stOut.push_back(tempOut);
  }

  int max=0,min=0;

  for(int i=1;i<m;i++){
    if(compare(&stIn[min],&stIn[i]))
      min=i;

    if(compare(&stOut[i],&stOut[max]))
      max=i;
  }

  cout << id[min] << " " << id[max];

  return 0;
}
