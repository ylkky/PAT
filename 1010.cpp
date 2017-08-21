#include <iostream>
#include <string>
using namespace std;

unsigned long long C2D(string n , unsigned long long r);
void compare(unsigned long long low, int step, string n, unsigned long long num);

int main(){
  string num[2];
  int tag, step;
  unsigned long long N[2], i, r;
  char c;
  for(i=0;i<2;i++)
    cin >> num[i];
  cin >> tag;
  cin >> r;

  N[0] = C2D(num[tag-1],r);
  c = num[2 - tag][0];
  for(i = 1; i < num[2 - tag].size(); i++){ //找最小的radix
      if(num[2 - tag][i] > c)
        c = num[2 - tag][i];
  }
  if(c >= '0' && c <= '9')
    i = c - '0';
  else
    i = c - 'a' + 10;
  i++;
  step = 4096;

  if(num[tag - 1].size() > num[2 - tag].size()){  //给出r的数的长度比较大，所以另一个数的r应该要比较大，至少比r大
    i = i > r? i : r;
  }
  //cout << "N[0] = " << N[0] << endl;
  while(1){
    N[1] = C2D(num[2-tag],i);
//    cout << "radix = " << i << ", N[1] = " << N[1] << endl;
    if(N[0] == N[1]){
      cout << i;
      break;
    }
    else if(N[1] > N[0]){  //|| i >= N[0]
      compare(i - step, step/2, num[2-tag], N[0]);
      break;
    }
    else{
      i += step;
      if(i >= N[0]){
        compare(i - step, N[0] - i + step, num[2-tag], N[0]);
        break;
      }
        //i = i > N[0] ? N[0] : i;
    }
  }
  return 0;
}

unsigned long long C2D(string n , unsigned long long r){
  int i;
  unsigned long long res = 0;
  int k;
  char ch;

  for(i=0;i<n.size();i++){
    ch = n.c_str()[i];
    if(ch>='0'&&ch<='9')
      k = ch-'0';
    else
      k = ch -'a' + 10;
    if(k >= r)
      return -1;

    res = k + res*r;
  }
  return res;
}

void compare(unsigned long long low, int step, string n, unsigned long long num){
//  cout << "low = " << low << ", step = " << step << endl;
  unsigned long long i = low + step;
  unsigned long long num2;
  if(step <= 16){
    for(i = low + 1; i < low + 2 * step; i++){
      num2 = C2D(n, i);
      if(num2 == num){
        cout << i;
        return ;
      }
    }
    cout << "Impossible";
  }
  else{
    num2 = C2D(n, i);
    if(num2 == num)
      cout << i;
    else if(num2 < num)
      compare(i, step/2, n, num);
    else
      compare(low, step/2, n, num);
  }
}
