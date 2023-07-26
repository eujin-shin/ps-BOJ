#include <iostream>
#include <stack>
using namespace std;

typedef struct {
  int i, x;
} element;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int NGE[1000000] = {0, };
  int n, cur; stack <element> s;
  cin>>n;
  for(int i=0; i<n; i++) {
    element temp; temp.i=i;
    cin>>temp.x;
    while(!s.empty() && s.top().x<temp.x) {
      NGE[s.top().i]=temp.x;
      s.pop();
    }
    s.push(temp);
  }
  while(!s.empty()) {
    NGE[s.top().i]=-1;
    s.pop();
  }
  for(int i=0; i<n; i++) {
    cout<<NGE[i];
    if(i==n-1) cout<<'\n';
    else cout<<' ';
  }
  return 0;
}