#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<utility>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long>zeroend(n+1, 0);
    vector<long long>oneend(n+1, 0);
    zeroend[1]=1;
    oneend[1]=1;
    for(int i=2;i<=n;i++){
        zeroend[i]= oneend[i-1];
        oneend[i]= oneend[i-1] + zeroend[i-1];
    }
    cout<<(long long)pow((zeroend[n] + oneend[n]), 2)<<endl;
}