#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  bool b;
  cin>>s;
  while(s[0]!='*') {
    b=true;
    for(int i=1; i<s.length(); i++) {
      int arr[30][30]={0, };
      for(int j=0; j+i<s.length(); j++) {
        if(arr[s[j]-'A'][s[j+i]-'A']==1) {
          b=false; break;
        }
        arr[s[j]-'A'][s[j+i]-'A']=1;
      }
      if(!b) break;
    }
    cout<<s<<" is ";
    if(!b) cout<<"NOT ";
    cout<<"surprising.\n";
    cin>>s;
  }
  return 0;
}