#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;

#define ON 1
#define OFF 0
#define INFINITE 65535

typedef int type;
class Record;

void printBill(vector<Record> v, int *rate);
double printRecord(vector<Record>::iterator iter1, vector<Record>::iterator iter2, int *rate);


class Record{
public:
  int dd,hh,mm;
  int time;
  type t;
  Record(int d, int h, int m, string w):dd(d), hh(h), mm(m){
    if(w == "off-line")
      t = OFF;
    else
      t = ON;
    time = m + h * 60 + d * 24 * 60;
  };
  // bool operator < (const Record &a){
  //   return time < a.time;
  // }
  // bool operator == (const Record &a){
  //   return time == a.time;
  // }
  // bool operator > (const Record &a){
  //   return time > a.time;
  // }
};

bool func(Record &r1, Record &r2){
  return r1.time < r2.time;
}

int main(){
  int rate[24];
  int i, j, N, mm, d, h, m;
  char ch;
  string name, w;
  map<string, vector<Record> > idList;
  map<string, vector<Record> >::iterator iter;
  for(i = 0; i < 24; i++){
    cin >> rate[i];
  }
  cin >> N;
  for(i = 0; i < N; i++){
    cin >> name;
    cin >> mm >> ch >> d >> ch >> h >> ch >> m;
    cin >> w;
    iter = idList.find(name);
    if(iter == idList.end()){
      vector<Record> v;
      idList.insert(map<string, vector<Record> >::value_type(name, v));
    }
    Record r(d, h, m, w);
    idList[name].push_back(r);
  }
  for(iter = idList.begin(); iter != idList.end(); iter ++){
    printf("%s %02d\n", (iter->first).c_str(), mm);
    printBill(iter->second, rate);
  }
  return 0;
}

void printBill(vector<Record> v, int* rate){
  vector<Record>::iterator iter1, iter2;
  double sum = 0;
  sort(v.begin(), v.end(), func);
  for(iter1 = v.begin(); iter1 != v.end(); iter1++){  //从第i条记录找起
    iter2 = iter1 + 1;
    if(iter2 == v.end())
      break;
    if(iter1->t == OFF || iter1->t == iter2->t)
      continue;
    else if(iter1->t == ON && iter2->t == OFF){
      sum += printRecord(iter1, iter2, rate);
      iter1++;
    }
  }
  printf("Total amount: $%.2lf\n", sum);
}

double printRecord(vector<Record>::iterator iter1, vector<Record>::iterator iter2, int *rate){
  int d, h, m, t = 0;
  double sum;
    if(iter1->dd < iter2->dd){    //不同天
      t = 60 - iter1->mm;
      sum = t * rate[iter1->hh];
      for(h = iter1->hh + 1; h < 24; h++){
        sum += 60 * rate[h];
      }
      for(d = iter1->dd + 1; d < iter2->dd; d++){
        for(h = 0; h < 24; h++)
          sum += rate[h] * 60;
      }
      for(h = 0; h < iter2->hh; h++)
        sum += rate[h] * 60;
      sum += rate[h] * iter2->mm;
    }
    else if(iter1->dd == iter2->dd){  //同天跨小时
      if(iter1->hh < iter2->hh){
        t = 60 - iter1->mm;
        sum = t * rate[iter1->hh];
        for(h = iter1->hh + 1; h < iter2->hh; h++){
          sum += 60 * rate[h];
        }
        sum += iter2->mm * rate[h];
      }
      else if(iter1->hh == iter2->hh){
        sum = (iter2->mm - iter1->mm) * rate[iter1->hh];
      }
    }
    sum /= 100;
    printf("%02d:%02d:%02d %02d:%02d:%02d ", iter1->dd, iter1->hh, iter1->mm, iter2->dd, iter2->hh, iter2->mm);
    //cout << iter1->dd << ":" << iter1->hh << ":" << iter1->mm << " ";
    //cout << iter2->dd << ":" << iter2->hh << ":" << iter2->mm << " ";
    cout << iter2->time - iter1->time << " ";
    printf("$%.2lf\n",sum);
  return sum;
}
