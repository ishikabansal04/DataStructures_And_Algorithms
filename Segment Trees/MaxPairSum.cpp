#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Node{
    public:
    int maximum, s_maximum;
};

// Building our segment tree!
void Buildtree(vector<int>&arr, vector<Node*>&tree, int start, int end, int treenode){
    cout <<"Hello" <<endl;
    if(start == end){
        tree[treenode]->maximum = arr[start];
        tree[treenode]->s_maximum = INT_MIN;
        return;
    }
    
    int mid = (start + end)/2;
    Buildtree(arr, tree, start, mid, (2*treenode));
    Buildtree(arr, tree, mid+1, end, (2*treenode)+1);

    Node* left = tree[2*treenode];
    Node* right = tree[2*treenode +1];
    tree[treenode]->maximum = max(left->maximum, right->maximum);
    tree[treenode]->s_maximum = min(max(left->maximum, right->s_maximum), max(right->maximum, left->s_maximum));
    return;
}


int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // size of segment tree should always be 4*n approximately!
    vector<Node*>tree(3*n);

    // Building initial tree
    Buildtree(arr, tree, 0, n-1, 1);

    // cout << "Menu: \n1. Query \n2. Update \n3. Display \n4. Quit \n\n";
    // int operation;
    // cout << "Enter operation number: ";
    // cin >> operation;
    // while(operation >0 && operation <4){
    //     if(operation == 1){
            
    //         // Query Opertion 
    //             int left, right;
    //             cout << "Enter range: ";
    //             cin >> left >> right;
    //             cout << Query(tree, 0, n-1, 1, left, right) << endl;
    //     }
    //     else if(operation == 2){

    //         // Updating values in initial tree
    //             int idx, newval;
    //             cout << "Enter new index and newvalue respectively: ";
    //             cin >> idx >> newval;
    //             Updatetree(arr, tree, 0, n-1, 1, newval, idx);
    //     }
    //     else if(operation == 3){

            // Display current segment tree            
                for(int i=1; i<(3*n); i++){
                    cout << tree[i]->maximum << "    ";
                }
                cout << endl; 
    //     }
    //     else{
    //         break;
    //     }
    //     cout << "Enter operation number: ";
    //     cin >> operation;
    // }
    return 0;
}