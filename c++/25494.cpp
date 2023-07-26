#include <iostream>
using namespace std;

int main() {
  int count, a, b, c, t;
  cin>>t;
  while(t--) {
    cin>>a>>b>>c; count=0;
    for(int x=1; x<=a; x++) {
      for(int y=1; y<=b; y++) {
        for(int z=1; z<=c; z++) {
          if(x%y == y%z && y%z == z%x) count++;
        }
      }
    }
    cout<<count<<'\n';
  }
  return 0;
}