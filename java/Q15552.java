import java.util.*;
import java.io.*;

public class Q15552 {
  public static void main(String[] args) throws IOException {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    int T = Integer.parseInt(bf.readLine().trim());
    for(int i=1; i<=T; i++) {
      String s = bf.readLine();
      StringTokenizer st = new StringTokenizer(s);
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      bw.write(String.valueOf(a+b));
      bw.newLine();
    }
    bw.flush();
    bw.close();
  }  
}
