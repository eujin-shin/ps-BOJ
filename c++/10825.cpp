#include <iostream>
using namespace std;

typedef struct {
  int kor, math, eng;
  string name;
} student;

int Cmp(const void *a, const void *b) {
  student x = *(student *)a, y = *(student *)b;
  int ret = y.kor-x.kor;
  if(ret == 0) {
    ret = x.eng-y.eng;
  }
  if(ret == 0) {
    ret = y.math-x.math;
  } 
  if(ret == 0) {
    ret = x.name.compare(y.name);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  student arr[100001] = {0, };
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i].name>>arr[i].kor>>arr[i].eng>>arr[i].math;
  }
  qsort(arr, n, sizeof(student), Cmp);
  for(int i=0; i<n; i++) {
    cout<<arr[i].name<<endl;
  }
}