#include <iostream>
#include <string>
using namespace std;

string k, d, a;
int map[2][200][21]={0, };

int Pass(int side, int r, int x) {
  int s;
  string cur;
  if(side>0) {
    s=1; cur=a;
  } else {
    s=0; cur=d;
  }
  if(map[s][x][r]>0) return map[s][x][r];
  if(r==k.size()-1) {
    for(int i=x; i<cur.size(); i++) {
      if(k[r]==cur[i]) map[s][x][r]+=1;
    }
  } else {
    for(int i=x; i<cur.size(); i++) {
      if(k[r]==cur[i]) map[s][x][r]+=Pass(-side, r+1, i+1);
    }
    /*
    for(int i=x; i<=cur.size()-k.size()+r; i++) {
      if(k[r]==cur[i]) map[s][x][r]+=Pass(-side, r+1, i+1);
    }
    */
  }
  return map[s][x][r];
}

int main() {
  cin>>k>>d>>a;
  cout<<Pass(1, 0, 0)+Pass(-1, 0, 0)<<'\n';
  return 0;
}