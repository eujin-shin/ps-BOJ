#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int arr[26]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  string in;
  int t, f, tmp;
  cin>>t;
  while(t--) {
    f=1;
    cin>>in;
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<in.size(); i++) {
      tmp=in[i]-'A';
      arr[tmp]++;
      if(arr[tmp]%3==0) {
        if(i+1>=in.size() || in[i+1]!=in[i]) f=0;
        else i++;
      }
    }
    if(f>0) cout<<"OK\n";
    else cout<<"FAKE\n";
  }
  return 0;
}