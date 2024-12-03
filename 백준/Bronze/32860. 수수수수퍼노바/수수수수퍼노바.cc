#include <iostream>
using namespace std;

int main() {
  int year, order;
  cin>>year>>order;
  cout<<"SN "<<year;
  if(order < 27) {
    cout<<(char)('A' + order - 1)<<'\n';
  } else {
    order -= 27;
    cout<<(char)('a' + order / 26)<<(char)('a' + order % 26)<<'\n';
  }
  return 0;
}