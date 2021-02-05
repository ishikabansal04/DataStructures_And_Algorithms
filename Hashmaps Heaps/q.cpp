#include <iostream>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {
    
	// your code goes here
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++){
	    int size;
	    cin>>size;
	    int nmin=INT_MAX, nmax=INT_MIN, nmid;
	    int id1=-1, id2=-1;
	    vector<int>arr(size);
	    for(int i=0;i<size;i++){
	        cin>>arr[i];

	        if(nmin> arr[i]){
	            nmin= arr[i];
	            id1=i;
	        }
	        if(nmax< arr[i]){
	            nmax= arr[i];
	            id2=i;
	        }
           
	    }
	    int maxsum =INT_MIN;
	    for(int i=0; (i<size) ;i++){
            // 
            if(i== id1 || i==id2){
                continue;
            }
	        int currsum = abs(nmin-arr[i]) + abs(arr[i]- nmax) + abs(nmax-nmin);
            
	        maxsum= max(currsum, maxsum);
	    }
	    cout<<maxsum<<endl;
	}
	return 0;
}
