#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int n, c;
    cin>>n>>c;
    vector<vector<int>>arr(n, vector<int>(c));
    for(int i=0;i<n;i++){
        for(int j=0;j<c; j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>dp(n, vector<int>(c));
    int least=INT_MAX;
    int sleast = INT_MAX;
    for(int i=0; i<c; i++){
        dp[0][i]= arr[0][i];
        if(dp[0][i]< least){
            sleast= least;
            least=dp[0][i];
        }
        if(dp[0][i] < sleast && dp[0][i]>least){
            sleast= dp[0][i];
        }
    }
    cout<<least<<" "<<sleast<<endl;
    
    for(int i=1; i<n; i++){
        int nleast = INT_MAX;
        int nsleast= INT_MAX;
        for(int j=0; j<c; j++){
            if(dp[i-1][j] == least){
                dp[i][j] = arr[i][j] + sleast;
            }
            else{
                dp[i][j] = arr[i][j] + least;
            }

            if(dp[i][j]< nleast){
                nsleast= nleast;
                nleast= dp[i][j];
            }
            if(dp[i][j] < nsleast && dp[i][j]>nleast){
                nsleast= dp[i][j];
            }
        }
        least= nleast;
        sleast= nsleast;
    }

    cout<<endl<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<c; j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }
    cout<<least<<endl;
}