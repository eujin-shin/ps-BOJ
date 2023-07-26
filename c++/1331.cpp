#include <iostream>
using namespace std;

int main() {
  int map[7][7] = {0, };
  int x_move[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  int y_move[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  char buffer[3];
  int bx, by, cx, cy, sx, sy;
  bool flag = true, flag2;
  for(int i=0; i<36; i++) {
    flag2 = false;
    cin>>buffer;
    if(!flag) continue;
    cx = buffer[0]-'A'+1;
    cy = buffer[1]-'0';
    cout<<cx<<' '<<cy<<'\n';
    if(map[cx][cy]) flag = false;
    else map[cx][cy]=1;
    if(i==0) {
      sx=cx; bx=cx; sy=cy; by=cy;
      continue;
    } else {
      for(int j=0; j<8; j++) {
        if(bx+x_move[j]==cx && bx+y_move[j]==cy) {
          flag2 = true; break;
        }
      }
      bx=cx; by=cy;
      if(flag2==false) flag = false;
    } 
    if(flag && i==35) {
      flag2 = false;
      for(int j=0; j<8; j++) {
        if(cx+x_move[j]==sx && cy+y_move[j]==sy) {
          flag2 = true; break;
        }
      }
      if(!flag2) flag = false;
    }
  }
  if(flag) cout<<"Valid\n";
  else cout<<"Invalid\n";
  return 0;
}