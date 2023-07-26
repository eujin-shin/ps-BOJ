import java.util.*;

class Scan {
  public void getAlp(String s) {
    String alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<26; i++) {
      if(i<25) {
        System.out.print(s.indexOf(alphabet.charAt(i)));
        System.out.print(" ");
      } else {
        System.out.println(s.indexOf(alphabet.charAt(i)));
      }
    }
  }
}

public class Q10809 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    Scan a = new Scan();
    a.getAlp(s);
  }
}
