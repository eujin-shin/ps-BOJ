#include <iostream>
using namespace std;

int main() {
  int sum=0, min, x;
  min=101;
  for(int i=0; i<4; i++) {
    cin>>x; sum+=x;
    if(min>x) min=x;
  }
  sum-=min; min=101;
  for(int i=0; i<2; i++) {
    cin>>x; sum+=x;
    if(min>x) min=x;
  }
  sum-=min;
  cout<<sum<<'\n';
  return 0;
}