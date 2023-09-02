#include <iostream>
using namespace std;

int n, m=0;
int arr[10][50]={0, }, set[10]={0, }, visit[10]={0, };

void Update() {
  int idx=0, cnt=0, hit, score, out;
  for(int i=0; i<n; i++) {
    out=0; score=0;
    while(out<3) {
      hit=arr[set[idx]][i];
      for(int j=0; j<hit; j++) {
        score*=10;
        if(j==0) score++;
        cnt+=score/1000;
        score%=1000;
      }
      if(hit==0) out++;
      idx++;
      if(idx==9) idx=0;
    }
  }
  if(m<cnt) m=cnt;
  return;
}

void MakeSet(int r) {
  if(r==3) {
    MakeSet(r+1);
    return;
  } else if(r==9) {
    Update();
    return;
  }
  for(int i=1; i<10; i++) {
    if(visit[i]==1) continue;
    visit[i]=1;
    set[r]=i;
    MakeSet(r+1);
    visit[i]=0;
  }
  return;
}

int main() {
  cin>>n;
  visit[1]=1; set[3]=1;
  for(int i=0; i<n; i++) {
    for(int j=1; j<10; j++) cin>>arr[j][i];
  }
  MakeSet(0);
  cout<<m<<'\n';
  return 0;
}