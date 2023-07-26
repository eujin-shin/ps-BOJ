import java.util.*;
import java.io.*;

class Scoring {
  public int getScore() {
    Scanner sc = new Scanner(System.in);
    String c = sc.nextLine();
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
      return score;
  } 
}

public class Q8958_1 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    int N = Integer.parseInt(br.readLine());
    int[] resultArr = new int[N];
    Scoring scr = new Scoring();
    for(int i=0; i<N; i++) {
      resultArr[i] = scr.getScore();
    }
    for(int i=0; i<N; i++) {
      bw.write(String.valueOf(resultArr[i]));
    }
    bw.flush();
    bw.close();
  }
}
