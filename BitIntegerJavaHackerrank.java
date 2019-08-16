import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the acmTeam function below.
    static int[] acmTeam(String[] topic) {
        int rows = topic.length;
        BigInteger numArr[]=new BigInteger[rows];
        for(int i=0;i<rows;i++){
            numArr[i]=new BigInteger(topic[i],2);
        }
        int max=-1;
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=i+1;j<rows;j++){
                int bitCount = numArr[i].or(numArr[j]).bitCount();
                if(bitCount>max){
                    max=bitCount;
                    count=1;
                }else if(bitCount == max)count++;
            }
        }
        return new int[]{max,count};

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        String[] topic = new String[n];

        for (int i = 0; i < n; i++) {
            String topicItem = scanner.nextLine();
            topic[i] = topicItem;
        }

        int[] result = acmTeam(topic);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
