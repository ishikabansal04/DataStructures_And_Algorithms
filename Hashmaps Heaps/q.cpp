#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

int main(){
    unordered_map<char, int> s1_chars, s2_chars;
    string s1, s2, result = "", temp = "";
    int match_count = 0;
    cin >> s1 >> s2;
    for(int i = 0; i < s2.size(); i++){
        s2_chars[s2[i]] += 1;
    }
    int  j = 0, i;
    for(i = 0; i < s1.size();){
        if(match_count < s2.size()){
                if(s2_chars[s1[i]] > s1_chars[s1[i]]){
                    match_count++;
                }
                s1_chars[s1[i]] += 1;
                i++;
        }

        if(match_count == s2.size()){
            while(match_count == s2.size()){

                if(s1_chars[s1[j]] > s2_chars[s1[j]] || s2_chars.count(s1[j]) == 0){
                    result = s1.substr(j + 1, i - j - 1);
                    temp = s1.substr(j + 1, i - j - 1);
                    cout << result << '\n';
                    s1_chars[s1[j]]--;
                    // j++;
                }
            
                else{
                    s1_chars[s1[j]]--;
                    match_count--;
                }
                j++;
            }
        }
    }
    cout << result <<"  "<<j << '\n';
    for(; j < s1.size() && match_count==s2.size(); j++){
        if(s1_chars[s1[j]] > s2_chars[s1[j]] || s2_chars.count(s1[j]) == 0){ 
            cout<<s1[j]<<" "<< s1_chars[s1[j]]<<endl;
            result = s1.substr(j + 1, i - j - 1);
            s1_chars[s1[j]]--;
        }
    }
    cout << result << '\n';
}