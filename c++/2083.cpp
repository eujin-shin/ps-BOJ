#include <iostream>
#include <string>
using namespace std;

int main() {
  string name;
  int age, weight;
  while(1) {
    cin>>name>>age>>weight;
    if(age==0) break;
    cout<<name;
    if(age>17 || weight>79) cout<<" Senior\n";
    else cout<<" Junior\n";
  }
  return 0;
}