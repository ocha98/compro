import java.math.BigInteger;
import java.util.*;
class Main{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int k = scan.nextInt();

        BigInteger[][] dp = new BigInteger[k+1][n+1];
        for(int i = 0;i <= k; ++i){
            Arrays.fill(dp[i], BigInteger.ZERO);
        }
        dp[0][0] = BigInteger.ONE;
        for(int i = 1;i <= k; ++i){
            for(int j = 0;j <= n; ++j){
                dp[i][j] = dp[i-1][j];
                if(j-i >= 0){
                    dp[i][j] = dp[i][j].add(dp[i][j-i]);
                }
            }
        }
        System.out.println(dp[k][n]);

    }
}