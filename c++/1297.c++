#include <iostream>
#include <math.h>
using namespace std;

int main() {
  double d, h, w;
  cin>>d>>h>>w;
  d *= d;
  h *= h;
  w *= w;
  double height = d/(h+w)*h, width = d/(h+w)*w;
  height = sqrt(height); width = sqrt(width);
  printf("%d %d\n", (int)height, (int)width);
  return 0;
}