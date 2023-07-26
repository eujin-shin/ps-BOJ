#include <iostream>
using namespace std;

int main() {
  int a, b, k=1;
  cin>>a>>b;
  while(a!=b) {
    if(b%10==1) {
      k++;
      b/=10;
    } else if(b%2==0) {
      k++;
      b/=2;
    } else {
      k = -1;
      break;
    }
    if(b<a) {
      k = -1;
      break;
    }
  }
  cout<<k<<endl;
  return 0;
}