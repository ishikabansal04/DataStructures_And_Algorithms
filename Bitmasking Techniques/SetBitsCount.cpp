#include<iostream>
using namespace std;

//method 1: O(no of bits)

/*int main(){
    int n;
    cin>>n;
    int count=0;
    while(n){
        count+= (n&1);
        n= n>>1;
    }
    cout<<count<<endl;
    return 0;
}*/
/*this concept says if bit is set then it gives 1 for n&1 and adds to count else 0 is added to count 
and by right shift it removes last bit and checks for all bits if 0 or 1 i.e. set or unset*/

//method 2: more optimized : O(no of set bits)
int main(){
    int n;
    cin>>n;
    int count=0;
    while(n){
        n= n&(n-1);
        count++;
    }
    cout<<count<<endl;
    return 0;
}

/*this works by removing the last set bit: for eg let n=13

count = 1
n  = 1101
n-1= 1100
&  = 1100 (Removed 1st set bit from right)

count = 2
n  = 1100
n-1= 1011
&  = 1000 (Removed 1st set bit from right)

count = 3
n  = 1000
n-1= 0111
&  = 0000 (Removed 1st set bit from right)

Thus all set bits are removed and count = 3
*/