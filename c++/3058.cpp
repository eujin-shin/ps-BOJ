#include <iostream>
using namespace std;

int main() {
  int t, tmp, min, sum;
  cin>>t;
  while(t--) {
    min=100; sum=0;
    for(int i=0; i<7; i++) {
      cin>>tmp;
      if(tmp%2!=0) continue;
      if(min>tmp) min=tmp;
      sum+=tmp;
    }
    cout<<sum<<' '<<min<<'\n';
  }
  return 0;
}