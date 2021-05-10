#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    string str;
    cin >> str;
    vector<int>arr(str.length());
    for(int i=0; i<str.length(); i++){
        if(str[i]=='0'){
            arr[i] = 1;
        }
        else{
            arr[i] = -1;
        }
    }
    int maxsum = 0, currbest = 0, i = 0, j = 0;
    for(; i<arr.size(); i++){
        int sum = currbest + arr[i];
        if(sum < arr[i] || sum < 0){
            sum = 0;
        }
        else if(currbest < sum){
            currbest = sum;
            maxsum = max(maxsum, currbest);
        }
        else{
            currbest = sum;
        }
        // cout << arr[i] << "     " << sum << endl;
    }
    if(maxsum == 0){
        maxsum = -1;
    }
    cout << maxsum << endl;
    return 0;
}