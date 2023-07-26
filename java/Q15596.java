import java.util.*;

class Test1 {
  long n = 0;
  public long sum (int[] a) {
    for(int i=0; i<a.length; i++) {
      n += a[i];
    }
    return n;
  }
}

public class Q15596 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    for(int i=0; i<n; i++) {
      a[i] = sc.nextInt();
    }
    Test1 t = new Test1();
    System.out.println(t.sum(a));
  }
}
