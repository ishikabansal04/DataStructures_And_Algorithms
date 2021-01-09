#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>inp(n);
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    int rnum=inp[0];
    for(int i=1;i<n;i++){
        rnum=rnum^inp[i];
    }
    for(int i=0;i<n;i++){
        rnum=rnum^inp[i];
        rnum=rnum^(i+1);
    }

    int mnum=rnum;
    for(int i=1;i<=n;i++){
        mnum=mnum^i;
        mnum=mnum^inp[i-1];
    }

    cout<<"Missing Number -> "<<mnum<<endl;
    cout<<"Repeating Number -> "<<rnum<<endl;
}