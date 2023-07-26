#include <iostream>
using namespace std;

int main() {
  int min, a, b, arr[4];
  for(int i=0; i<4; i++) cin>>arr[i];
  a=arr[0]+arr[3]; b=arr[1]+arr[2];
  min=(a<b) ? a:b;
  cout<<min<<'\n';
  return 0;
}