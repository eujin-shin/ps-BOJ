#include <iostream>
#include <string>
using namespace std;

int arr[10]={0, };

int main() {
  string in;
  int tmp, sum=0;
  cin>>in;
  for(int i=0; i<in.size(); i++) {
    tmp=in[i]-'0';
    arr[tmp]++; sum+=tmp;
  }
  if(arr[0]==0 || sum%3!=0) {
    cout<<"-1\n";
  } else {
    for(int i=9; i>=0; i--) {
      for(int j=0; j<arr[i]; j++) cout<<i;
    }
    cout<<"\n";
  }
  return 0;
}