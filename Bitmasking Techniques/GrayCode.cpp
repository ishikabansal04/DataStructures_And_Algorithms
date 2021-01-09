#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

vector<string> GrayCode(int n){
    if(n==0){
        vector<string> basearr={"0"};
        return basearr;
    }
    if(n==1){
        vector<string> basearr={"0","1"};
        return basearr;
    }
    vector<string>finalres;
    vector<string>smallres=GrayCode(n-1);
    for(int i=0;i<smallres.size();i++){
        string a=smallres[i];
        a=to_string(0) +a;
        finalres.push_back(a);
    }
    for(int i=smallres.size()-1;i>=0;i--){
        string a=smallres[i];
        a=to_string(1) +a;
        finalres.push_back(a);
    }
    return finalres;
}

int BinaryToDecimal(string s){
    int degree= s.length()-1;
    int res=0;
    for(int i=0;i<s.length();i++){
        res=res+ ((s[i]-'0') *pow(2,degree-i));
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<string>res=GrayCode(n);
    cout<<"[";
    for(int i=0;i<res.size()-1;i++){
        cout<<BinaryToDecimal(res[i])<<", ";
    }
    cout<<BinaryToDecimal(res[res.size()-1])<<"]";
}