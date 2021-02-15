#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<utility>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>zeroend(n+1, 0);
    vector<int>oneend(n+1, 0);
    zeroend[1]=1;
    oneend[1]=1;
    for(int i=2;i<=n;i++){
        zeroend[i]= oneend[i-1];
        oneend[i]= oneend[i-1] + zeroend[i-1];
    }
    cout<<zeroend[n] + oneend[n]<<endl;
}