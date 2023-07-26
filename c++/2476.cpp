#include <iostream>
using namespace std;

int arr[7]={0, };

int main() {
  int n, max=0, t, x;
  cin>>n;
  for(int i=0; i<n; i++) {
    t=0;
    for(int j=0; j<3; j++) {
      cin>>x; arr[x]+=1;
    }
    for(int i=1; i<7; i++) {
      if(arr[i]==1 && t<i*100) t=i*100;
      else if(arr[i]==2) t=1000+i*100;
      else if(arr[i]==3) t=10000+i*1000;
      arr[i]=0;
    }
    if(t>max) max=t;
  }
  cout<<max<<'\n';
  return 0;
}