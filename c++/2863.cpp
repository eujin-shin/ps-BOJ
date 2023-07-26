#include <iostream>
using namespace std;

int main() {
  double arr[4]={0, }, x, max=0; 
  int k;
  for(int i=0; i<4; i++) cin>>arr[i];
  for(int i=1; i<3; i++) {
    x=arr[0]/arr[i]+arr[3-i]/arr[3];
    if((max<x) || (max==x && k>2-i)) {
      max=x; k=2-i;
    }
    x=arr[i]/arr[0]+arr[3]/arr[3-i];
    if((max<x) || (max==x && k>4-i)) {
      max=x; k=4-i;
    }
  }
  cout<<k<<'\n';
  return 0;
}