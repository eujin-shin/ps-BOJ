#include <iostream>
using namespace std;

int main() {
  int n, x, y, vector, k, sum=0, left;
  cin>>n;
  for(int i=1; ;i++) {
    if(n-sum<=i) {
      left = n-sum;
      k = i;
      break;
    }
    sum+=i;
  }
  if(k%2) {
    y = left;
    x = k-left+1;
  } else {
    x = left;
    y = k-left+1;
  }
  cout<<x<<"/"<<y<<endl;
  return 0;
}