#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

long long findMin(priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>&pq, priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>&temp){
    long long currtym=temp.top().first;
    long long sum=0;
    long long n=temp.size();
    while(temp.size()!=0 || pq.size()!=0){
        cout<<currtym<<endl;
        while(temp.size() && temp.top().first<=currtym){
            pq.push(make_pair(temp.top().second, temp.top().first));
            temp.pop();
        }
        // long top=pq.top();
        cout<<pq.top().first<<" "<<pq.top().second<<endl;

        long long currsum=sum + pq.top().first - pq.top().second;
        sum= sum + currsum;
        cout<<currsum<<"    "<<sum<<endl;
        currtym+=sum;
        pq.pop();
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