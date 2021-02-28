#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<float>weights(n);
    vector<float>value(n);
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    
    float cap;
    cin>>cap;
    unordered_map<float, float>mymap;
    priority_queue<float>pq;
    for(int i=0;i<n;i++){
        pq.push(value[i] / weights[i]);
        mymap[value[i]/ weights[i]]=i;
    }
    float currcap=0;
    float tval=0;
    while(currcap<cap && pq.size()!=0){
        float rn= pq.top();
        pq.pop();
        int idx=mymap[rn];
        int mincap = min(weights[idx], (cap-currcap));
        tval += rn*mincap;
        currcap+=mincap;
    }
    // cout<<fixed<<tval<<endl;
    printf("%0.1f", tval);
    return 0;
}