#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
  int n,m,i,id,k,j,cid;
  string leaf="";
  cin >> n;
  cin >> m;
  map<int,vector<int> > t;
  vector<int> node;

  for(i=0;i<m;i++){
    node.clear();
    leaf = "";
    cin >> id;
    cin >> k;
    for(j=0;j<k;j++){
      cin >> cid;
      node.push_back(cid);
    }
    t.insert(map<int, vector<int> >::value_type(id,node));
  }
  queue<int> Q;
  map<int,vector<int> >::iterator iter;
  id = 01;
  int count=0,thisN=1,nextN=0;
  vector<int> v;
  for(i=0;i<n;i++){
    iter = t.find(id);
    if(iter!=t.end()){
      v = iter->second;
      if(v.size()==0)
        count++;
      else{
        for(j=0;j<v.size();j++){
          Q.push(v[j]);
        }
        nextN += v.size();
      }
    }
    else
      count++;
      
    thisN--;
    if(thisN==0){
      thisN=nextN;
      nextN = 0;
      if(i) cout << " ";
      cout << count;
      count = 0;
    }

    if(!Q.empty()){
      id = Q.front();
      Q.pop();
    }
    else
      break;
  }

  return 0;
}
