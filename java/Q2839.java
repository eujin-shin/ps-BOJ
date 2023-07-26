import java.util.*;

public class Q2839 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int five = N/5;
    int n = N%5;
    int ans;
    if(n==0) {
      ans = five;
    } else {
      int three = n/3;
      if(n%3==0) {
        ans = five+three;
      } else if(n%3==1 && five>=1) {
        ans = five+three+1;
      } else if(n%3==2 && five>=2) {
        ans = five+three+2;
      }
      else {
        ans = -1;
      }
    }
    System.out.println(ans);
  }
}
