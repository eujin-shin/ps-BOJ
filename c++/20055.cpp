#include <iostream>
#include <queue>
using namespace std;

int main() {
  int belt[201]={0, };
  int robot[101]={0, };
  queue <int> robotq;
  int n, k;
  cin>>n>>k;
  for(int i=1; i<=2*n; i++) {
    cin>>belt[i];
  }
  int count=0, start=1, zero=0, cur, index;
  while(zero<k) {
    count++; start--;
    if(start<1) start=2*n;
    if(robot[n-1]) robot[n-1]=0;
    for(int cur=n-2; cur>0; cur--) {
      if(robot[cur]==0) continue;
      robot[cur]=0;
      index=cur+start+1; if(index>2*n) index-=2*n;
      if(belt[index]>0 && robot[cur+2]==0) {
        belt[index]=belt[index]-1;
        if(belt[index]==0) {
          zero++;
        }
        if(cur+2==n) continue;
        robot[cur+2]=1;
      } else {
        robot[cur+1]=1;
      }
    }
    if(belt[start]>0) {
      robot[1]=1;
      belt[start]=belt[start]-1;
      if(belt[start]==0) {
        zero++;
      }
    }
  }
  cout<<count<<'\n';
}