import java.util.*;
import java.io.*;

public class Q10951 {
  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    while(sc.hasNextInt()) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      bw.write(String.valueOf(a+b));
      bw.flush();
      bw.newLine();
    }
    bw.close();
  }
}