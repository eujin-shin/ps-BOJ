#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int move_x[] = {1, 2, 2, 1, -1, -2, -2, -1};
  int move_y[] = {-2, -1, 1, 2, 2, 1, -1, -2};
  int t, l, cur_x, cur_y, next_x, next_y, fin_x, fin_y, next, cur, ans;
  cin>>t;
  for(int i=0; i<t; i++) {
    int map[302][302] = {0, };
    queue <int> xq; queue <int> yq;
    next = ans = 0; cur = 1;
    cin>>l>>cur_x>>cur_y>>fin_x>>fin_y;
    xq.push(cur_x); yq.push(cur_y);
    while(cur_x!=fin_x || cur_y!=fin_y) {
      if(cur==0) {
        cur = next;
        next = 0;
        ans++;
      }
      cur_x = xq.front(); xq.pop();
      cur_y = yq.front(); yq.pop();
      for(int i=0; i<8; i++) {
        next_x = cur_x+move_x[i];
        next_y = cur_y+move_y[i];
        if(next_x>=0 && next_x<l && next_y>=0 && next_y<l) {
          if(!map[next_y][next_x]) {
            map[next_y][next_x] = 1;
            xq.push(next_x); yq.push(next_y);
            next++;
          }
        }
      }
      cur--;
    }
    cout<<ans<<'\n';
  }
  return 0;
}