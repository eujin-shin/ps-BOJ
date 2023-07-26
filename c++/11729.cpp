#include <iostream>
using namespace std;

int dp[21] = {0, 1, };

void Hanoi(int n, int start, int end, int via) {
  if(n==2) {
    printf("%d %d\n%d %d\n%d %d\n", start, via, start, end, via, end);
  } else {
    Hanoi(n-1, start, via, end);
    printf("%d %d\n", start, end);
    Hanoi(n-1, via, end, start);
  }
}

int GetDp(int n) {
  for(int i=2; i<=n; i++) {
    dp[i] = dp[i-1]*2+1;
  }
  return dp[n];
}

int main() {
  int n;
  cin>>n;
  if(n==1) {
    printf("1\n1 3\n");
  } else {
    cout<<GetDp(n)<<endl;
    Hanoi(n, 1, 3, 2);
  }
  return 0;
}
