#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string str;
    cin>>str;
    vector<int>dp(str.length(), 0);
   
    for(int i=0;i<str.length();i++){
        if(i==0){
            if(str[i]=='0'){
                continue;
            }
            else{
                dp[0]=1;
            }
        }
        else{
            if(str[i]=='0' && str[i-1]!='0'){
                if(str[i-1]=='1' || str[i-1]=='2'){
                    if(i<2){
                        dp[i]=1;
                    }
                    else
                        dp[i]=dp[i-2];
                }
            }
            else if(str[i]=='0' && str[i-1]=='0'){
                dp[i]=0;
            }
            else if(str[i]!='0' && str[i-1]=='0'){
                dp[i]=dp[i-1];
            }
            else{
                string temp = str.substr(i-1, 2);
                int num = (str[i-1]-'0')*10 + (str[i]-'0');
                dp[i]=dp[i-1];
                if(num<=26){
                    if(i<2){
                        dp[i]+=1;
                    }
                    else
                        dp[i]+=dp[i-2];
                }
            }
        }
    }

    cout<<dp[str.length()-1]<<endl;
}