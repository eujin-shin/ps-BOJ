import java.util.*;
import java.io.*;

public class Q8958 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    for(int i=0; i<N; i++) {
      String c = br.readLine();
      int a = 0;
      int score = 0;
      for(int x=0; x<c.length(); x++) {
        if(c.charAt(x)=='O') {
          a += 1;
          score += a;
        } else {
          a = 0;
        }
      }
      System.out.println(score);    
    }
  }
}
