#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
#include<string>
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
    string s1, s2;
    int count = 0;
    cin >> s1 >> s2;
    for(int i = 0; i < s2.size(); i++){
        s2_chars[s2[i]] += 1;
    }
    for(int i = 0, j = 0; i < s1.size(); i++){
        if(i < s2.size()){
            s1_chars[s1[i]] += 1;
            if(i == s2.size() - 1){
                bool match = true;
                for(auto character : s1_chars){
                    if(s2_chars.count(character.first) == 0 || s2_chars[character.first] != s1_chars[character.first]){
                        match = false;
                        break;
                    }
                }
              
                if(match){
                    cout<<count<<endl;
                  count++;
                }
            }
        }
        else{
            s1_chars[s1[j]] -= 1;
            s1_chars[s1[i]] += 1;

            bool match = true;
            for(auto character : s1_chars){
                if(s2_chars.count(character.first) == 0 || s2_chars[character.first] != s1_chars[character.first]){
                    cout<<character.first<<endl;
                    match = false;
                    break;
                }
            }
            if(match){
                cout<<"h"<<endl;
                count++;
            }
            j++;
        }
    }
     cout << count << '\n';
}