#include <iostream>
using namespace std;

int main() {
  int n, k, tmp;
  while(cin>>n) {
    k=1; tmp=1;
    while(1) {
      tmp%=n;
      if(tmp==0) break;
      tmp=tmp*10+1; k++;
    }
    cout<<k<<"\n";
  }
}