#include <iostream>
#include <vector>
using namespace std;

int map[10][10] = {0, }, visit[10][10] = {0, }, ans = 100000;
int moves[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void backTrack(int r, int n, int sum);
int checkPrice(int x, int y);
void checkVisit(int x, int y, int v);

int main() {
  int n;
  cin>>n;
  for(int y = 0; y < n; y++) {
    for(int x = 0; x < n; x++) {
      cin>>map[y][x];
    }
  }
  backTrack(0, n, 0);
  cout<<ans<<'\n';
  return 0;
}

void checkVisit(int x, int y, int v) {
  int mapX, mapY;
  for(int i = 0; i < 5; i++) {
    mapX = x + moves[i][0];
    mapY = y + moves[i][1];
    visit[mapY][mapX] = v;
  }
  return;
}

int checkPrice(int x, int y) {
  int mapX, mapY, price = 0;
   for(int i = 0; i < 5 && price >= 0; i++) {
    mapX = x + moves[i][0];
    mapY = y + moves[i][1];
    price = visit[mapY][mapX] == 1 ? -1 : price + map[mapY][mapX];
  }
  return price;
}

void backTrack(int r, int n, int sum) {
  if(r == 3) {
    ans = ans < sum ? ans : sum;
    return;
  }
  int price;
  for(int y = 1; y < n - 1; y++) {
    for(int x = 1; x < n - 1; x++) {
      price = checkPrice(x, y);
      if(price < 0) {
        continue;
      }
      checkVisit(x, y, 1);
      backTrack(r + 1, n, sum + price);
      checkVisit(x, y, 0);
    }
  }
  return;
}