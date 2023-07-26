#include <iostream>
#define ll long long
using namespace std;

ll arr[81]={0, 1, 1, };

ll Solve(int n) {
  if(arr[n]!=0) return arr[n];
  return arr[n]=Solve(n-1)+Solve(n-2);
}

int main() {
  int n;
  cin>>n;
  if(n==1) {
    cout<<"4\n"; return 0;
  }
  cout<<Solve(n)*4+Solve(n-1)*2<<'\n';
  return 0;
}