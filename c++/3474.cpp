#include <iostream>
using namespace std;

int arr[15]={0, 5, };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  int t, n, i, c;
  cin>>t;
  while(t--) {
    cin>>n; c=0;
    for(int i=1; arr[i]<=n; i++) {
      c+=n/arr[i];
      arr[i+1]=arr[i]*5;
    }
    cout<<c<<'\n';
  }
  return 0;
}