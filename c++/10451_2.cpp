#include <iostream>
using namespace std;

int main() {
  int num[1002] = {0, };
  int t, n, temp, next, count;
  cin>>t;
  for(int i=0; i<t; i++) {
    count = 0;
    cin>>n;
    for(int j=1; j<=n; j++) {
      cin>>temp;
      num[j] = temp;
    }
    for(int j=1; j<=n; j++) {
      if(num[j]!=0) {
        count++;
        temp = j;
        do {
          next = num[temp];
          num[temp] = 0;
          temp = next;
        } while(num[next]!=0);
      }
    }
    cout<<count<<endl;
  }
  return 0;
}