class Solution {
public:
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
        return max_;
    }
};