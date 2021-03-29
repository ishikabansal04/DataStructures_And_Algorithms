/* Problem Statement =>
    Given a 2 x n board and tiles of size 2 x 1, count the number of ways to tile the given board using the 2 x 1 tiles. 
    A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. */

import java.util.*;
public class Tiling_2xN {

    static int numberOfWays(int length) {
        int mod = 1000000007;
        int[] dp = new int[length + 1];
        if (length <= 2) {
            return length;
        }

        // Case 1: if n == 1 , only 1 configuration of tile is possible
        dp[1] = 1;

        // Case 2: if n == 2 , only 2 configurations are possible
        dp[2] = 2;

        /* Case 3: if n > 2, then we got 2 possible subcases: 
            Subcase 1: if we place length wise, call dp[i-2];
            Subcase 2: if we place width wise, call dp[i-1];  */
        for (int i = 3; i <= length; i++) {
            dp[i] = ((dp[i - 2] % mod) + (dp[i - 1] % mod) % mod);
        }
        return dp[length] % mod;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter length of the floor:");
        int length = scn.nextInt();
        System.out.println("Number of Ways to tile 2 x " + length + " floor are : " + numberOfWays(length));
        scn.close();
    }
}

/*  Sample Input: n=3

    Sample Output: 3
    
    Expected Time Complexity: O(n)
    
    Expected Space Complexity: O(n) */
    