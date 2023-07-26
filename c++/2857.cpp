#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector <int> v;
  string s;
  for(int i=1; i<6; i++) {
    cin>>s;
    for(int j=0; j<s.size()-2; j++) {
      if(s[j]=='F' && s[j+1]=='B' && s[j+2]=='I') {
        v.push_back(i);
        break;
      }
    }
  }
  for(int i=0; i<v.size(); i++) {
    if(i>0) cout<<' ';
    cout<<v[i];
  }
  if(v.size()==0) cout<<"HE GOT AWAY!";
  cout<<"\n";
  return 0;
}