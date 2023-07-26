#include <iostream>
#define M 10000000
using namespace std;

int arr[4][8]={0, };

void Cw(int i) {
  int x=arr[i][7];
  for(int j=7; j>0; j--) {
    arr[i][j]=arr[i][j-1];
  }
  arr[i][0]=x;
  return;
}

void Ccw(int i) {
  int x=arr[i][0];
  for(int j=0; j<7; j++) {
    arr[i][j]=arr[i][j+1];
  }
  arr[i][7]=x;
  return;
}

void Rotate(int i, int dir, int b) {
  bool l=false, r=false;
  if(b!=1 && i+1<4 && arr[i][2]!=arr[i+1][6]) r=true;
  if(b!=-1 && i-1>-1 && arr[i][6]!=arr[i-1][2]) l=true;
  if(dir<0) Ccw(i);
  else Cw(i);
  if(r) Rotate(i+1, -dir, -1);
  if(l) Rotate(i-1, -dir, 1);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, k, m, s, d, sum, temp;
  for(int i=0; i<4; i++) {
    cin>>n; k=M;
    for(int j=0; j<8; j++) {
      arr[i][j]=n/k; n%=k; k/=10;
    }
  }
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>s>>d;
    s--;
    Rotate(s, d, 0);
  }
  sum=0; k=1;
  for(int i=0; i<4; i++) {
    sum+=arr[i][0]*k;
    k*=2;
  }
  cout<<sum<<'\n';
  return 0;
}