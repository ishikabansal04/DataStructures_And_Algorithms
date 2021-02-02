#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
// struct comp { 
//     template <typename T> 
  
//     // Comparator function 
//     bool operator()(const T& l, 
//                     const T& r) const
//     { 
//         if (l.second != r.second) { 
//             return l.second < r.second; 
//         } 
//         return l.first < r.first; 
//     } 
// }; 

int main(){
    int n;
    cin>>n;
    map<map<char, int>,vector<string>, greater<map<char, int>>>finalmap;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        map<char, int>visited;
        for(int i=0;i<str.length();i++){
            visited[str[i]]+=1;
        }
        auto it =finalmap.find(visited);
        if(it!= finalmap.end()){
            it->second.push_back(str);
        }
        else{
            finalmap[visited].push_back(str);
        }
    }

    map<map<char, int>, vector<string>, greater<map<char, int>>>::iterator it= finalmap.begin();
    vector<vector<string>>res;
    int size= it->second.size();
    while(it!=finalmap.end()){
        if(it->second.size()==size){
            res.push_back(it->second);
            it++;
        }
        else{
            for(int i=0;i<res.size();i++){
                sort(res[i].begin(), res[i].begin()+res[i].size());
            }

            sort(res.begin(), res.begin()+res.size());
            for(int i=0;i<res.size();i++){
                // sort(res[i].begin(), res[i].begin()+res[i].size());
                for(int j=0;j<res[i].size();j++){
                    cout<<res[i][j]<<" ";
                }
                cout<<endl;
            }
            res.clear();
            size= it->second.size();
            // cout<<size<<endl;
        }
      
    }
        for(int i=0;i<res.size();i++){
                sort(res[i].begin(), res[i].begin()+res[i].size());
            }

            sort(res.begin(), res.begin()+res.size());
            for(int i=0;i<res.size();i++){
                // sort(res[i].begin(), res[i].begin()+res[i].size());
                for(int j=0;j<res[i].size();j++){
                    cout<<res[i][j]<<" ";
                }
                cout<<endl;
            }
            res.clear();
    // sort(res.begin(), res.begin()+res.size());
    // for(int i=0;i<res.size();i++){
    //     sort(res[i].begin(), res[i].begin()+res[i].size());
    //     for(int j=0;j<res[i].size();j++){
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}