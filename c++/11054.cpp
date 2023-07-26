#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int num[1001] = {0, };
  int inc[1002][1002] = {0, }, dec[1002][1002] = {0, };
  int n, max, temp;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>num[i];
  }
  for(int i=1; i<=n; i++) {
    max = 0;
    for(int j=1; j<=i; j++) {
      if(inc[j][i]>max) max = inc[j][i];
    }
    inc[0][i] = max;
    for(int j=i+1; j<=n; j++) {
      if(num[i]<num[j]) inc[i][j] = max+1;
      else inc[i][j] = 0;
    }
  }
  for(int i=n; i>0; i--) {
    max = 0;
    for(int j=1; j<=n-i+1; j++) {
      if(dec[j][i]>max) max = dec[j][i];
    }
    dec[0][i] = max;
    for(int j=i-1; j>0; j--) {
      if(num[i]<num[j]) dec[n-i+1][j] = max+1;
      else dec[i][j] = 0;
    }
  }
  max = 0;
  for(int i=1; i<=n; i++) {
    temp = dec[0][i]+inc[0][i];
    if(temp>max) max = temp;
  }
  max += 1;
  cout<<max<<'\n';
  return 0;
}