#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int tests;
  cin>>tests;
  int velocityList[1000] = {0, };
  int participants, maxBooster, offset;
  double track, maxVelocity, minSec, difference;
  while(tests--) {
    cin>>participants>>track>>maxBooster;
    maxVelocity = 0;
    for(int i = 0; i < participants; i++) {
      cin>>velocityList[i];
      if(i < participants - 1 && velocityList[i] > maxVelocity) {
        maxVelocity = velocityList[i];
      }
    }
    if(maxVelocity < velocityList[participants - 1]) {
      cout<<"0\n";
    } else {
      minSec = track / maxVelocity;
      difference = minSec * (maxVelocity - velocityList[participants - 1]);
      offset = ceil(difference == floor(difference) ? difference + 1 : difference);
      if(velocityList[participants - 1] + offset > maxBooster) {
        cout<<"-1\n";
      } else {
        cout<<velocityList[participants - 1] + offset<<'\n';
      }
    }
  }
  return 0;
}