#include <iostream>
#include <queue>
using namespace std;

queue <int> xq;
queue <int> yq;

int Search(int map[][302], int x, int y, int vec, int l) {
  int result = 0;
  switch (vec) {
    case 1:
      if(x<l && y>=0 && !map[y][x]) result = 1;
      break;
    case 2:
      if(x<l && y<l && !map[y][x]) result = 1;
      break;
    case 3:
      if(x>=0 && y<l && !map[y][x]) result = 1;
      break;
    case 4:
      if(x>=0 && y>=0 && !map[y][x]) result = 1;
      break;
  }
  if(result) {
    xq.push(x); yq.push(y);
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, l, cur_x, cur_y, tar_x, tar_y, ans, now, next, temp;
  cin>>t;
  for(int i=0; i<t; i++) {
    int map[302][302] = {0, };
    ans = next = 0, now = 1;
    xq = queue <int>();
    yq = queue <int>();
    cin>>l;
    cin>>cur_x>>cur_y>>tar_x>>tar_y;
    xq.push(cur_x); yq.push(cur_y);
    while(cur_x!=tar_x || cur_y!=tar_y) {
      cur_x = xq.front(); xq.pop();
      cur_y = yq.front(); yq.pop();
      temp = Search(map, cur_x-1, cur_y-2, 4, l);
      if(temp) map[cur_y-2][cur_x-1] = 1; next+=temp;
      temp = Search(map, cur_x-2, cur_y-1, 4, l);
      if(temp) map[cur_y-1][cur_x-2] = 1; next+=temp;
      temp = Search(map, cur_x+1, cur_y-2, 1, l);
      if(temp) map[cur_y-2][cur_x+1] = 1; next+=temp;
      temp = Search(map, cur_x+2, cur_y-1, 1, l);
      if(temp) map[cur_y-1][cur_x+2] = 1; next+=temp;
      temp = Search(map, cur_x+1, cur_y+2, 2, l);
      if(temp) map[cur_y+2][cur_x+1] = 1; next+=temp;
      temp = Search(map, cur_x+2, cur_y+1, 2, l);
      if(temp) map[cur_y+1][cur_x+2] = 1; next+=temp;
      temp = Search(map, cur_x-1, cur_y+2, 3, l);
      if(temp) map[cur_y+2][cur_x-1] = 1; next+=temp;
      temp = Search(map, cur_x-2, cur_y+1, 3, l);
      if(temp) map[cur_y+1][cur_x-2] = 1; next+=temp;
      now--;
      if(now==0) {
        ans++;
        now = next;
        next = 0;
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}