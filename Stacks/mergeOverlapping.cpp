#include<iostream>
#include<utility> //for pair class
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        pair<int, int>mypair;
        cin>>mypair.first;
        cin>>mypair.second;
        arr.push_back(mypair);
    }
    sort(arr.begin(), arr.end());


    stack<int>stk1;
    stack<int>stk2;
    for(int i=0;i<n;i++){
        int a=arr[i].first;
        int b=arr[i].second;
        bool flag=true;
        if(stk1.size()==0){
            stk1.push(a);
            stk2.push(b);
            continue;
        }
            int r1=stk1.top();
            stk1.pop();
            int r2=stk2.top();
            stk2.pop();
            if(a>=r1 && b<=r2){
                a=r1;
                b=r2;
            }
            else if(a>=r1 && a<=r2){
                a=r1;
                b=b;
            } 
            else if(b <= r2 && b>=r1){
                b=r2;
            }
            else if(r1>=a && r2<=b){
                a=a;
                b=b;
            }
            else if(r1>=a && r1<=b){
                a=a;
                b=b;
            }
            else if(r2<=b && r2>=a){
                a=a;
                b=b;
            }
            else{
                stk1.push(r1);
                stk2.push(r2);
                flag=false;
            }
            stk1.push(a);
            stk2.push(b);
    }
        vector<pair<int,int>>ans;
        while(stk1.size()){
            pair<int, int>mypair;
            mypair.first=stk1.top();
            mypair.second=stk2.top();
            ans.push_back(mypair);
            stk1.pop();
            stk2.pop();
        }
        sort(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }

        return 0;
}