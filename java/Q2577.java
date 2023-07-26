import java.util.*;
import java.io.*;

class Test {
  int N;

  public Test(int N) {
    this.N = N;
  }

  public void getNum() {
      int[] numArr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      while(N>0) {
        numArr[N%10]+=1;
        N /= 10;
      }
      for(int i=0; i<numArr.length; i++) {
        System.out.println(numArr[i]);
      } 
  }

}

public class Q2577 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int N = a*b*c;
    Test t = new Test(N);
    t.getNum();
  }
  
}
