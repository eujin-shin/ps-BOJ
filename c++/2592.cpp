#include <iostream>
using namespace std;

int num[100]={0, };

int main() {
  int x, sum, c, f;
  for(int i=0; i<10; i++) {
    cin>>x; sum+=x; num[x/10]+=1;
  }
  c=0;
  for(int i=1; i<100; i++) {
    if(num[i]<=c) continue;
    c=num[i]; f=i*10;
  }
  cout<<sum/10<<'\n';
  cout<<f<<'\n';
  return 0;
}