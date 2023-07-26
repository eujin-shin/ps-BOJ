#include <iostream>
using namespace std;

int main() {
  int x=1, n, k;
  cin>>n>>k;
  while(x*2<n) x*=2;
  while(k>1 && n>0) {
    while(x>n && x>1) x/=2;
    n-=x;
    k--;
  }
  if(n==0) {
    cout<<"0\n";
  } else {
    while(x<n) x*=2;
    while(x/2>=n && x>1) x/=2;
    cout<<x-n<<'\n';
  }
  return 0;
}