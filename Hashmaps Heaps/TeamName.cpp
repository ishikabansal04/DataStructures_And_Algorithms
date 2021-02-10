#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	// your code goes here
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++){
	    int n;
	    cin>>n;
	    unordered_map<string, int>mymap;
	    vector<string>arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        mymap[arr[i]]=1;
	    }
	    int count=0;
	    for(int i=0;i<n-1;i++){
	        for(int j=i+1;j<n;j++){
	            string s1= arr[i];
	            string s2= arr[j];
	            char c1=s1[0];
	            char c2=s2[0];
                string r1 ="", r2="";
                r1 = s1.substr(1);
                r2 = s2.substr(1);
                r1= c2 + r1;
                r2= c1 + r2;
	            if(mymap.count(r1)>0 || mymap.count(r2)>0){
	                continue;
	            }
	            count+=2;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
