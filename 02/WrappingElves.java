import java.io.*;
import java.util.*;

public class WrappingElves {

  public static void main(String args[]){
    try {
      BufferedReader in = new BufferedReader( new FileReader("gifts.txt"));
      String line;
      String[] v_str;
      int[] v_int = new int[3];
      int total_paper = 0, total_ribbon = 0;
      while( (line = in.readLine()) != null ){
        v_str = line.split("x");
        for( int i = 0; i < 3; i++ ){
            v_int[i] = Integer.parseInt(v_str[i]);
        }
        Arrays.sort( v_int ); //lol
        //Paper calcs
        total_paper += 3*v_int[0]*v_int[1];
        total_paper += 2*v_int[0]*v_int[2];
        total_paper += 2*v_int[1]*v_int[2];
        //Ribbon calcs
        total_ribbon += 2*v_int[0] + 2*v_int[1];
        total_ribbon += v_int[0]*v_int[1]*v_int[2];
      }
      System.out.println("Wrapping Paper: " + total_paper);
      System.out.println("Ribbon: " + total_ribbon);
    } catch (Exception e) {

    }
  }
}