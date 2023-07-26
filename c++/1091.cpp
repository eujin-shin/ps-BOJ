#include <iostream>
#define MAX 10000000 // 애매하게 풂
using namespace std;

int s[49]={0, }, p[49]={0, }, pos[49]={0, }, visit[49][50]={0, };

int main() {
  int n, cnt=0;
  bool flag=true, un=true;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>p[i]; p[i]=(p[i]+1)%3;
  }
  for(int i=1; i<=n; i++) {
    cin>>s[i]; s[i]++;
  }
  for(int i=1; i<=n; i++) {
    pos[i]=i;
    visit[i][i]=1;
    if(i%3==p[i]) visit[i][0]=1;
    else flag=false;
  }
  while(!flag) {
    cnt++; flag=true;
    if(cnt > MAX) {
      flag=false; break;
    }
    for(int i=1; i<=n; i++) {
      pos[i]=s[pos[i]];
      if(visit[i][pos[i]]==1 && visit[i][0]==0) {
        un=false; flag=false; break;
      }
      visit[i][pos[i]]=1;
      if(pos[i]%3==p[i]) visit[i][0]=1;
      else flag=false;
    }
    if(!un) break;
  }
  if(flag) cout<<cnt<<'\n';
  else cout<<"-1\n";
  return 0;
}
