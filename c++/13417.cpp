#include <iostream>
using namespace std;

int arr[1000]={0, };
char s[1000];

int main() {
  ios_base::sync_with_stdio(false);
  int t, n;
  char f;
  cin>>t;
  while(t--) {
    cin>>n;
    for(int i=0; i<n; i++) {
      cin>>s[i];
      if(i==0 || f>=s[i]) {
        arr[i]=1; f=s[i];
      } else {
        arr[i]=-1;
      }
    }
    for(int i=n-1; i>=0; i--) if(arr[i]>0) cout<<s[i];
    for(int i=1; i<n; i++) if(arr[i]<0) cout<<s[i];
    cout<<'\n';
  }
  return 0;
}