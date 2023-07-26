#include <iostream>
using namespace std;

int main() {
  int n, t;
  cin>>n;
  while(n!=0) {
    while(n>9) {
      t=0;
      while(n>0) {
        t+=n%10; n/=10;
      }
      n=t;
    }
    cout<<n<<'\n';
    cin>>n;
  }
}