#include <iostream>
#include <queue>
using namespace std;

int rec[101]={0, };
queue <int> q;

int main() {
  bool flag;
  int n, m, x, k, tmp, min;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>x;
    if(rec[x]==0) {
      if(q.size()>=n) {
        flag=true; k=q.size();
        for(int j=0; j<k; j++) {
          tmp=q.front(); q.pop();
          if(rec[tmp]==min && flag) {
            flag=false; rec[tmp]=0;
          } else {
            q.push(tmp);
          }
        }
      }
      q.push(x);
    }
    rec[x]++;
    min=1001;
    for(int j=0; j<q.size(); j++) {
      tmp=q.front(); q.pop();
      min=(rec[tmp]<min ? rec[tmp] : min);
      q.push(tmp);
    }
  }
  tmp=0;
  for(int i=1; i<101; i++) {
    if(tmp==n) break;
    if(rec[i]<1) continue;
    if(tmp!=0) cout<<' '; 
    tmp++;
    cout<<i;
  }
  cout<<'\n';
  return 0;
}