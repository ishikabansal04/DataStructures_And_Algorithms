class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m= matrix[0].size();
        vector<vector<int>>prefix(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(j==0) prefix[i][j] = matrix[i][j];
                else{
                    prefix[i][j] = prefix[i][j-1] + matrix[i][j];
                } 
            }
        }
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=i; j<m; j++){
                // cout<<i<<" "<<j<<"=> ";
                unordered_map<int, int>mymap;
                int sum=0;
                mymap[0]=1;
                for(int k=0; k<n; k++){
                    sum+=prefix[k][j];
                    if(i!=0) sum-=prefix[k][i-1]; 
                    if(mymap.count(sum-target)>0){
                        count+=mymap[sum-target];
                    }
                    // else if(target<0 && mymap.count(sum+target)>0){
                    //     count+=mymap[sum+target];
                    // }
                    mymap[sum]+=1;
                }
                // cout<<count<<endl;
            }
        }
        return count;
    }
};