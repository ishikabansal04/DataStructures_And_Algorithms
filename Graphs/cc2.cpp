#include<iostream>
#include<vector>
#include<string>
using namespace std;

void find(vector<char>&alphas, int s, int e, char *ch, int idx, string given){
    if(s==e){
        *ch=alphas[s];
        return;
    }
    int mid=(s+e)/2;
    if(given[idx]=='0'){
        e=mid;
        return find(alphas, s,e, ch, idx+1, given);
    }
    else{
        s=mid+1;
        return find(alphas, s,e, ch, idx+1,given);
    }

}

int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int n;
        cin>>n;
        string str;
        cin>>str;
        string res="";
        vector<char>alphas={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
        do{
            string tempstr=str.substr(0,4);
            char ch;
            find(alphas, 0, 15, &ch, 0, tempstr);
            str= str.substr(4);
            res+=ch;
            // cout<<tempstr<<endl;
        }while(str.length()>=4);
        cout<<res<<endl;
    }
    return 0;
}