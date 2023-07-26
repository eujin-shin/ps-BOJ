import java.util.*;

public class Q2439 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for(int i=1; i<=n; i++) {
      int x = n-i;
      for(int a=1; a<=x; a++) {
        System.out.print(" ");
      }
      for(int b=1; b<=i; b++) {
        System.out.print("*");
      }
      System.out.println();
    }
  }
}
