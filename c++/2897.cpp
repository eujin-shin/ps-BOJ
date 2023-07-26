#include <iostream>
#include <string>
using namespace std;

string map[50];

int Check(int x, int y) {
  int a[4]={0, 1, 0, 1}, b[4]={0, 0, 1, 1};
  int cnt=0;
  char tmp;
  for(int i=0; i<4; i++) {
    tmp=map[y+b[i]][x+a[i]];
    if(tmp=='#') return -1;
    if(tmp=='X') cnt++;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  int arr[5]={0, }, r, c, tmp;
  cin>>r>>c;
  for(int i=0; i<r; i++) cin>>map[i];
  for(int y=0; y<r-1; y++) {
    for(int x=0; x<c-1; x++) {
      tmp=Check(x, y);
      if(tmp<0) continue;
      arr[tmp]++;
    }
  }
  for(int i=0; i<5; i++) cout<<arr[i]<<'\n';
  return 0;
}