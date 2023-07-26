#include <iostream>
using namespace std;
/*
0: n
1: 3 * n
2: 3 * k  (n이 짝수이면 k=n/2, 아니라면 k = n+1 / 2)
3: 9 * k
4: 1 * k
*/

int main() {
  int i=1, n;
  cin>>n;
  while(n>0) {
    cout<<i<<". ";
    if(n%2==0) cout<<"even "<<n/2<<'\n';
    else cout<<"odd "<<(n-1)/2<<'\n';
    cin>>n; i++;
  }
  return 0;
}