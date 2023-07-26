#include <iostream>
using namespace std;

int main() {
  int n, sum, min, max, temp;
  int num[100000] = {0, };
  cin>>n;
  sum = 0; min = 0;
  for(int i=0; i<n; i++) {
    scanf("%d", &temp);
    if(i==0) {
      max = temp;
    }
    sum+=temp;
    if(sum-min>max) {
      max = sum-min;
    }
    if(min>sum) {
      min = sum;
    }
  }
  cout<<max<<endl;
  return 0;
}