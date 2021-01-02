#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


void find(vector<int>&arr1, vector<int>&arr2, int v, int idx1, int idx2, unordered_map<int, int>&mymap){
    if(idx1>=arr1.size() || idx2>=arr2.size()){
        return;
    }
    // if(mymap.count(v)>0){
        for(int i=idx1;i<arr1.size();i++){
            // v=v|arr1[idx1];
            find(arr1, arr2, v|arr1[i], idx1+1, idx2, mymap);
        }
        for(int j=idx2;j<arr2.size();j++){
            // v=;
            find(arr1, arr2, v&arr2[j], idx1, idx2+1, mymap);
        }
    // }
        mymap[v]=1;
 
}
int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int m,n;
        cin>>m>>n;
        vector<int>arr1(m);
        vector<int>arr2(n);
        for(int i=0;i<m;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        int v=0;
        unordered_map<int, int>mymap;
        vector<vector<int>>dp(m+1,vector<int>(n+1, -1));
        dp[0][0]=0;
        for(int i=0;i<m;i++){
            dp[0][i+1]=arr1[i];
            mymap[arr1[i]]=1;
        }
        for(int i=0;i<n;i++){
            dp[i+1][0]=arr2[i];
            mymap[arr2[i]]=2;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int tcount=0;
                if(!(mymap.count(dp[i][j-1]|dp[i-1][j])>0)){
                    mymap[dp[i][j-1]|dp[i-1][j]]=1;
                    tcount+=1;
                }
                if(!(mymap.count(dp[i][j-1]&dp[i-1][j])>0)){
                    mymap[dp[i][j-1]*dp[i-1][j]]=1;
                    tcount+=1;
                }
                dp[i][j]=tcount;
            }
        }
    }

}