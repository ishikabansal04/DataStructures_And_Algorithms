/* Problem Statement =>
    Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to
   tile the given board using the 2 x 1 tiles.
    A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically
   i.e., as 2 x 1 tile. */

/* Algorithm =>
    Approach used : Dynamic Programming
    Test cases handled explicitly:
    Case 1: if n == 1 , only 1 configuration of tile is possible
    Case 2: if n == 2 , only 2 configurations are possible
    Case 3: if n > 2, then we got 2 possible subcases:
        Subcase 1: if we place length wise, call dp[i-2];
        Subcase 2: if we place width wise, call dp[i-1];
    at last return, dp[n] for number of ways. */

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        vector<int>dp(envelopes.size(), 1);
        int max_=1;
        for(int i=1; i<envelopes.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1]< envelopes[i][1]){
                    dp[i]= max(dp[i], dp[j]+1);
                }
            }
            max_= max(max_, dp[i]);
        }
        for(int i=0; i<envelopes.size(); i++){
            cout<<dp[i]<<"  ";
        }
        return max_;
    }

    int main(){
        vector<vector<int>> envelopes={{5,4},{6,4},{6,7},{2,3}};
        cout<<maxEnvelopes(envelopes);
    }