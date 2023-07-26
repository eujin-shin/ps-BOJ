#include <iostream>
using namespace std;

int main() {
  int max=-1, x, y, tmp;
  for(int i=1; i<10; i++) {
    for(int j=1; j<10; j++) {
      cin>>tmp;
      if(tmp>max) {
        x=j; y=i; max=tmp;
      }
    }
  }
  cout<<max<<'\n'<<y<<' '<<x<<'\n';
  return 0;
}