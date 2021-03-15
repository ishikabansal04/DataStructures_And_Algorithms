#include <iostream>
#include<vector>
using namespace std;

// Complete the redJohn function below.
int redJohn(int n) {
    vector<int>dp(n+1, 0);
    for(int i=1;i<=n; i++){
        if(i<4){
            dp[i]=1;
        }
        else if(i==4){
            dp[i]=2;
        }
        else{
            dp[i]= dp[i-1] + dp[i-4];
        }
    }
    long M= (long)dp[n];
    // cout<<M<<endl;
    vector<long>isPrime(M+1, 0);
    if(M==0 || M==1){
        return 0;
    }
    if(M==2){
        return 1;
    }
    
    for(long i=3; i<=M; i+=2){
        isPrime[i]=1;
    }
    for(long i=3; i<=M; i+=2){
        if(isPrime[i]==1){
            for(long j= i*i; j<=M; j+=i){
                isPrime[j]=0;
            }
        }
    }
    isPrime[0]= isPrime[1]= 0;
    isPrime[2]= 1;
    long count=0;
    for(long i=2; i<=M; i++){
        if(isPrime[i]){
            count++;
            // cout<<i<<"  ";
        }
    }
    // cout<<endl;
    return (int)count;
}

int main()
{

    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;

        int result = redJohn(n);

        cout << result << "\n";
    }


    return 0;
}
