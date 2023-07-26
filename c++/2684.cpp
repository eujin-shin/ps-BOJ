#include <iostream>
#include <string>
using namespace std;

int cnt[8]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string in;
  int t, cur=0;
  cin>>t;
  while(t--) {
    cin>>in;
    for(int i=0; i<40; i++) {
      cur=cur*2%8;
      if(in[i]=='H') cur+=1;
      if(i>1) cnt[cur]++;
    }
    for(int i=0; i<8; i++) {
      cout<<cnt[i];
      cnt[i]=0;
      if(i==7) cout<<'\n';
      else cout<<' ';
    }
  }
  return 0;
}