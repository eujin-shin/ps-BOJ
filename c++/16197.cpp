#include <iostream>
#include <string>
#include <queue>
#define pnt pair<int, int>
#define nax na.second
#define nay na.first
#define nbx nb.second
#define nby
using namespace std;

queue <pnt> aq, bq;
string map[20];
int n, m, mx[4]={0, -1, 0, 1}, my[4]={1, 0, -1, 0};

int main() {
  bool flag=false, a=false, b=false;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>map[i];
    for(int j=0; j<m; j++) {
      if(map[i][j]=='o' && !a) {
        aq.push(make_pair(i, j)); a=true;
      } else if(map[i][j]=='o') {
        bq.push(make_pair(i, j)); b=true;
      }
    }
  }
  int cnt=1, next=0, cur=1;
  pnt ca, cb, na, nb;
  while(!aq.empty() && cnt<=10) {
    ca.second=aq.front().second;
    ca.first=aq.front().first;
    cb.second=bq.front().second;
    cb.first=bq.front().first;
    for(int i=0; i<4; i++) {
      a=false; b=false;
      na.first=ca.first+my[i];
      na.second=ca.second+mx[i];
      nb.first=cb.first+my[i];
      nb.second=cb.second+mx[i];
      if(na.second<0 || na.second>=m || na.first<0 || na.first>=n) a=true;
      else if(map[na.first][na.second]=='#') {
        na.second-=mx[i]; na.first-=my[i];
      }
      if(nb.second<0 || nb.second>=m || nb.first<0 || nb.first>=n) b=true;
      else if(map[nb.first][nb.second]=='#') {
        nb.second-=mx[i]; nb.first-=my[i];
      }
      if(a!=b) {
        cout<<cnt<<'\n';
        return 0;
      }
      if(a && b) continue;
      if(na.first==nb.first && na.second==nb.second) continue;
      aq.push(na); bq.push(nb);
      next++;
    }
    aq.pop(); bq.pop();
    cur--;
    if(cur==0) {
      cnt++; cur=next; next=0;
    }
  }
  cout<<"-1\n";
  return 0;
}