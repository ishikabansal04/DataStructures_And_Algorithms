#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxsum=INT_MIN;
    int linc = 0;
    int lexc = 0;
    for(int i=0;i<n;i++){
        int currmax=INT_MIN;
        currmax = max(linc, max(lexc, lexc+arr[i]));
        int temp = lexc;
        lexc = max(linc, lexc);
        linc = temp + arr[i];
        maxsum= max(maxsum, currmax);
    }
    cout<<maxsum;
}