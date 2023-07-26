#include <iostream>
#include <string>
using namespace std;

int main() {
  int num[2]={26, 10};
  string form;
  cin>>form;
  int ans=0, cur;
  for(int i=0; i<form.size(); i++) {
    cur=num[form[i]-'c'];
    if(i==0) ans=1;
    else if(form[i]==form[i-1]) cur--;
    ans*=cur;
  }
  cout<<ans<<'\n';
  return 0;
}