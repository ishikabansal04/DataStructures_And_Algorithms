#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>

using namespace std;

// for hackerrank take "long long"
int helper(vector<int>& arr){
        vector<int>result(arr.size(), 0);
        vector<int>result2(arr.size(), 0);
        result[0] = 1; 
        result2[arr.size()-1] = 1;
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1]<arr[i]){
                result[i] = result[i-1]+1;
            }
            else{
                result[i] = 1;
            }
        }
        for(int i=arr.size()-2; i>=0; i--){
            if(arr[i+1] >= arr[i]){
                result2[i] = 1;
            }
            else{
                result2[i] = result2[i+1]+1;
            }
        }
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum += max(result[i], result2[i]);
        }
        return sum;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << helper(arr) <<endl;
    return 0;
}