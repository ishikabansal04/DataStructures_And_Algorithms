#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    vector<long>dp(str.size()+1, 0);
    vector<long>lastidx(26, -1);
    dp[0]=1;
    for(int i=1; i<=str.size(); i++){
        if(lastidx[str[i-1]-'a']==-1){
            dp[i]= 2*dp[i-1];
            lastidx[str[i-1]-'a'] = i;
        }
        else{
            int idx = lastidx[str[i-1] - 'a'] - 1;
            dp[i] = 2*dp[i-1] - dp[idx];
            lastidx[str[i-1]- 'a'] = i;
        }
    }
    cout<<dp[str.size()]-1<<endl;
}