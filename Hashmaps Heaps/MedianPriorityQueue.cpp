#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<map>
using namespace std;

class MedianPriorityQueue{
    public: 
    priority_queue<int>pq1;
    priority_queue<int , vector<int>, greater<int>>pq2;


    void add(int num){
        pq2.push(num);
        if(pq2.size()>pq1.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
        while(pq1.top()>pq2.top()){
            int val1=pq1.top();
            int val2=pq2.top();
            pq1.pop();
            pq2.pop();
            pq1.push(val2);
            pq2.push(val1);
        }
    }

    int peek(){
        return pq1.size()!=0 ? pq1.top(): -1;
    }

    int size(){
        return pq1.size()+ pq2.size();
    }

    int remove(){
        int val=-1;
        if(pq1.size()){
            val=pq1.top();
            pq1.pop();
            if(pq2.size()>pq1.size()){
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
        return val;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    MedianPriorityQueue mp;
    string str;
    do{
        cin>>str;
        if(str=="add"){
            int val;
            cin>>val;
            mp.add(val);
        }
        else if(str=="remove"){
            int val=mp.remove();
            if(val==-1){
                cout<<"Underflow"<<endl;
            }
            else{
                cout<<val<<endl;
            }
        }
        else if(str=="size"){
            cout<<mp.size()<<endl;
        }
        else if(str=="peek"){
            int val=mp.peek();
            if(val==-1){
                cout<<"Underflow"<<endl;
            }
            else{
                cout<<val<<endl;
            }
        }
    }while(str!="quit");
    return 0;
}