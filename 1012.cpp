#include<iostream>
#include<map>
using namespace std;

int main(){
  int N,m;
  char ch[5]="ACME";
  string id;
  map<string,int> sid;
  cin >> N >> m;
  int i,j;
  int g[N][4],best[N],rank[N][4];

  for(i=0;i<N;i++){
    g[i][0]=0;
    cin >> id;
    sid.insert(map<string,int>::value_type(id,i));
    for(j=1;j<4;j++){
      cin >> g[i][j];
      g[i][0] += g[i][j];
    }
    g[i][0] /= 3;
  }

  map<string,int>::iterator iter;
  int stuid , count=1;
  int k=0;

  for(i=0;i<N;i++){
    best[i]=0;
    for(k=0;k<4;k++){
      count=1;
      for(j=0;j<N;j++){
        if(g[i][k]<g[j][k])
          count++;
      }
      rank[i][k] = count;
      if(rank[i][best[i]]>count)
        best[i]=k;
    }
  }


  for(i=0;i<m;i++){
    count = 1;
    cin >> id;
    iter = sid.find(id);
    if(iter!=sid.end()){
      stuid = iter->second;
      cout << rank[stuid][best[stuid]] << " " << ch[best[stuid]] << endl;
    }
    else
      cout << "N/A" << endl;
  }

  return 0;
}
