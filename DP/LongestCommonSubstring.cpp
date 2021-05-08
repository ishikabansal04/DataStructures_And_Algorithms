#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    int n1 = str1.length();
    int n2 = str2.length();
    int max_ = INT_MIN;
    vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, 0));
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            max_ = max(max_, dp[i][j]);
            // cout << dp[i][j] << "   ";
        }
        // cout << endl;
    }
    cout << max_ <<endl;
}