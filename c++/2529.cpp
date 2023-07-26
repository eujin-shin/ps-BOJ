#include <iostream>
using namespace std;

int ans[3][11]={0, };
int visit[10] = {0, };
char input[10] = {0, };

void BackTrack(int r, int n, long long *max, long long *min, long long cur) {
  if(r==n) {
    if(*min==0 || *min>cur) *min=cur;
    if(*max==0 || *max<cur) *max=cur;
  } else {
    if(input[r]=='<') {
      for(int i=(cur%10)+1; i<10; i++) {
        if(visit[i]==0) {
          visit[i]=1; 
          BackTrack(r+1, n, max, min, cur*10+i);
          visit[i]=0;
        }
      }
    } else {
      for(int i=(cur%10)-1; i>=0; i--) {
        if(visit[i]==0) {
          visit[i]=1; 
          BackTrack(r+1, n, max, min, cur*10+i);
          visit[i]=0;
        }
      }
    }
  }
  return;
}

int main() {
  int n;
  long long min=0, max=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  for(int i=0; i<10; i++) {
    visit[i]=1;
    BackTrack(0, n, &max, &min, i);
    visit[i]=0;
  }
  cout<<max<<'\n';
  int c=1;
  for(int i=0; i<n; i++) {
    c*=10;
  }
  if(c>min) cout<<'0';
  cout<<min<<'\n';
  return 0;
}