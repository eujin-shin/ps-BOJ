import java.util.*;

class Calculator {
  public int getAve (int n) {
    Scanner sc = new Scanner(System.in);
    int sum, ave;
    sum = 0;
    for(int i=0; i<n; i++) {
      int x = sc.nextInt();
      if(x<40) {
        x = 40;
      }
      sum += x;
    }
    ave = sum/5;
    return ave;
  }
}

public class Q10039 {
  public static void main(String[] args) {
    Calculator cal = new Calculator();
    System.out.println(cal.getAve(5));
  }
}
