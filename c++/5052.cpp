#include <iostream>
#include <vector>
using namespace std;

bool Cmp(int a, int b, int s, int l) {
  int c=1;
  for(int i=0; i<l-s; i++) {
    c*=10;
  }
  if(b/c==a) return true;
  else return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, c, x, i;
  bool flag;
  cin>>t;
  while(t--) {
    vector <int> num[11];
    cin>>n; 
    while(n--) {
      cin>>x; flag=false;
      c=1;
      for(i=1; i<=10; i++) {
        c*=10; 
        if(x<c) {
          num[i].push_back(x); break;
        }
      }
      for(int j=1; j<i; j++) {
        for(int h=0; h<num[j].size(); h++) {
          flag=Cmp(num[j][h], x, j, i);
        }
      }
    }
    if(flag) {
      cout<<"NO\n";
    } else {
      cout<<"YES\n";
    }
  }
  return 0;
}