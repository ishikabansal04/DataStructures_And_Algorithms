#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<climits>
#include<unordered_map>
using namespace std;

long long findMin(priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>&pq, priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>&temp){
    long long currtym=temp.top().first;
    unordered_map<long long, long long>savetime;
    long long n=temp.size();
    while(temp.size()!=0 || pq.size()!=0){
        // cout<<currtym<<endl;
        while(temp.size() && temp.top().first<=currtym){
            pq.push(make_pair(temp.top().second, temp.top().first));  
            temp.pop();
        }
        // long top=pq.top();
        // cout<<pq.top().first<<" "<<pq.top().second<<endl;
        currtym += pq.top().first;
        savetime[currtym]= pq.top().second;
        pq.pop();
    }

    long long sum=0;

    for(auto pair: savetime){
        // cout<<pair.first<<"     "<<pair.second<<endl;
        sum=sum+ pair.first- pair.second;
    }    
    return sum/n;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    int num;
    cin>>num;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>temp;
    for(long i=0;i<num;i++){
        long a, b;
        cin>>a>>b;
        // pq.push(make_pair(b, a));
        temp.push(make_pair(a, b));
    }
    long long mintym= findMin(pq, temp);
    cout<<mintym<<endl;
}