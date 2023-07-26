#include <iostream>
#define M 1000000
using namespace std;

int arr[M]={0, 1, };

int main() {
  int p, k, r;
  cin>>p>>k;
  for(int i=2; i<k; i++) {
    if(arr[i]==1) continue;
    for(int j=i*2; j<k; j+=i) arr[j]=1;
  }
  for(int i=2; i<k; i++) {
    if(i>=p) break;
    if(arr[i]==1) continue;
    if(p%i==0 && arr[p/i]==0) {
      r = (i<p/i) ? i : p/i;
      cout<<"BAD "<<r<<'\n';
      return 0;
    }
  }
  cout<<"GOOD\n";
  return 0;
}