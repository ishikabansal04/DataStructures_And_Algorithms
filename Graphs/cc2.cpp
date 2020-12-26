#include<iostream>
#include<string>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int size;
        cin>>size;
        string s,p;
        cin>>s>>p;
        if(s==p){
            cout<<"Yes"<<endl;
        }
        else{
            int i,j;
            for(i=size-1, j=size-1 ;i>=0 && j>=0;){
                if(s[i]==p[j]){
                    // cout<<i<<"          "<<j<<endl;
                    i--;
                    j--;
                }
                
                else if(s[i]=='1' && p[j]=='0'){
                    cout<<"No"<<endl;
                    break;
                }
                else{
                    int k;
                    for(k=j-1;k>=0;k--){
                        if(s[k]=='1' && p[k]=='0'){
                            j=k-1;
                            i=k-1;
                            // cout<<k<<endl;
                            break;
                        }
                    }
                    if(k==-1){
                        cout<<"No"<<endl;
                        break;
                    }
                }
            }
            if(i==-1 && j==-1){
                cout<<"Yes"<<endl;
            }
        }      

    }
    return 0;
}