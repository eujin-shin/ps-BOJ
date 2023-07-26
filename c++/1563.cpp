#include <iostream>
using namespace std;
#define MAX 1000000

// 일수, 지금껏 지각한 횟수, 직전까지 연속으로 결석한 횟수
int attend[1002][3][4] = {0, };

int GetAttend(int n) {
  int i00, i01, i02, i10, i11, i12, sum;
  if(n==1) return 3;
  for(int i=2; i<=n; i++) {
    i00=attend[i-1][0][0]+attend[i-1][0][1]+attend[i-1][0][2]; i00%=MAX;
    i01=attend[i-1][0][0];
    i02=attend[i-1][0][1];
    i10=attend[i-1][1][1]+attend[i-1][1][2]+attend[i-1][1][0]+attend[i-1][0][0]+attend[i-1][0][1]+attend[i-1][0][2]; i10%=MAX;
    i11=attend[i-1][1][0];
    i12=attend[i-1][1][1];
    attend[i][0][0]=i00; attend[i][0][1]=i01; attend[i][0][2]=i02; attend[i][1][0]=i10;
    attend[i][1][1]=i11; attend[i][1][2]=i12;
    if(i==n) {
      sum=i00+i01+i02+i10+i11+i12;
      sum%=MAX;
    }
  }
  return sum;
}

int main() {
  int n;
  cin>>n;
  attend[1][1][0]=1; attend[1][0][0]=1; attend[1][0][1]=1;
  cout<<GetAttend(n)<<'\n'; 
}