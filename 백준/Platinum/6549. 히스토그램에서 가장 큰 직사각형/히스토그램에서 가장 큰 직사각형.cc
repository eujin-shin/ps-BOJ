#include <iostream>
#include <stack>
#define ll long long
using namespace std;

struct Pos {
  ll height;
  ll start;
};


int main() {
  int n;
  ll h;
  cin>>n;

  stack <Pos> s;
  Pos prev; 
  ll max, area;
  while(n != 0) {
    max = 0;

    for(int i = 1; i <= n; i++) {
      cin>>h;
      Pos cur = {h, i};
      while(!s.empty() && s.top().height > h) {
        prev = s.top();
        s.pop();
        area = (i - prev.start) * prev.height;
        cur.start = prev.start < cur.start ? prev.start : cur.start;
        max = max < area ? area : max;
      }
      s.push(cur);
    }

    while(!s.empty()) {
      prev = s.top();
      s.pop();
      area = (n + 1 - prev.start) * prev.height;
      max = max < area ? area : max;
    }

    cout<<max<<'\n';
    cin>>n; 
  }
  return 0;
}