#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int arr[1000]={0, }, t;
  double n, sum, avg, cnt;
  cin>>t;
  cout<<fixed;
  cout.precision(3);
  while(t--) {
    cin>>n; cnt=0; sum=0;
    for(int i=0; i<n; i++) {
      cin>>arr[i]; sum+=arr[i];
    }
    avg=sum/n;
    for(int i=0; i<n; i++) {
      if(arr[i]>avg) cnt++;
    }
    cout<<round(cnt/n*100000)/1000<<"%\n";
  }
  return 0;
}