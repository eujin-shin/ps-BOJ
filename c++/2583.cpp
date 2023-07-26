#include <iostream>
#include <queue>
using namespace std;

int map[102][102] = {0, };
int area_arr[5002] = {0, };

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  queue <int> xq; queue <int> yq;
  int move_x[] = {-1, 0, 0, 1};
  int move_y[] = {0, -1, 1, 0};
  int m, n, k, x1, x2, y1, y2;
  cin>>m>>n>>k;
  for(int i=0; i<k; i++) {
    cin>>x1>>y1>>x2>>y2;
    for(int j=x1; j<x2; j++) {
      for(int h=y1; h<y2; h++) {
        map[h][j] = 1;
      }
    }
  }
  int cur_x, cur_y, next_x, next_y, area, count = 0;
  for(int y=0; y<m; y++) {
    for(int x=0; x<n; x++) {
      if(!map[y][x]) {
        area = 0;
        xq.push(x); yq.push(y);
        while(!xq.empty()) {
          cur_x = xq.front(); xq.pop();
          cur_y = yq.front(); yq.pop();
          if(map[cur_y][cur_x]) continue;
          map[cur_y][cur_x] = 1; 
          area++;
          for(int i=0; i<4; i++) {
            next_x = cur_x + move_x[i];
            next_y = cur_y + move_y[i];
            if(next_x>=0 && next_x<n && next_y>=0 && next_y<m && !map[next_y][next_x]) {
              xq.push(next_x); yq.push(next_y);
            }
          }
        }
        area_arr[count] = area;
        count++;
      }
    }
  }
  qsort(area_arr, count, sizeof(int), Cmp);
  cout<<count<<'\n';
  for(int i=0; i<count; i++) {
    cout<<area_arr[i];
    if(i==count-1) {
      cout<<'\n';
    } else {
      cout<<' ';
    }
  }
  return 0;
}