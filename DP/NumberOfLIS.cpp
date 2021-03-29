#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;


    class Pair{
        public:
        int len;
        int val;
        int idx;
        Pair(int len, int val, int idx){
            this->len = len;
            this->val = val;
            this->idx = idx;
        }
    };
    
    int binary(int left, int right, vector<int>&dp, int key){
        if(left>=right){
            return left;
        }
        if(left<right){
            int mid= (left+right)/2;
            if(dp[mid]<key){
                left= mid+1;
            }
            else{
                right=mid;
            }
        }
        return binary(left, right, dp, key);
    }
    
    void lengthOfLIS(vector<int>& nums, vector<int>&LIS) {
        int len = nums.size();
        
        vector<int>dp;
        dp.push_back(nums[0]);
		
        for (int i = 1; i < len; i++){
            
            if (nums[i] > dp[dp.size()-1]){
                dp.push_back(nums[i]);
                LIS[i] = dp.size();
                continue;
            }
            
            int left = 0;
            int right = dp.size()-1;
            
            int idx= binary(left, right, dp, nums[i]);
            dp[idx] = nums[i];
            LIS[i] = dp.size();
        }  
    }
    
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int max_= 1;
        lengthOfLIS(nums, dp);
        for(int i=1; i<nums.size(); i++){
            cout<< dp[i]<<"  ";
            max_ = max(max_, dp[i]);
        }
        cout<< endl<<endl;
        int count = 0;
        queue<Pair*>que;
        for(int i=0; i<nums.size(); i++){
            if(dp[i] == max_)
                que.push(new Pair(max_ , nums[i],i));
        }
        
        while(que.size()!=0){
            Pair * top = que.front();
            que.pop();
            cout<< top->val <<" " << top->idx <<" => ";
            if(top->len == 1){
                count++;
            }
            for(int i=top->idx-1; i>=0; i--){
                if((dp[i]== top->len-1) && (top->val> nums[i])){
                    que.push(new Pair(dp[i], nums[i], i));
                    cout<< nums[i] << "," << i << "     ";
                }
            }
            cout<<endl;
        }
        return count;
    }

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout << findNumberOfLIS(nums);
}