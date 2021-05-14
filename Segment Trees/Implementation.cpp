#include<iostream>
#include<vector>
using namespace std;

// Building our segment tree!
void Buildtree(vector<int>&arr, vector<int>&tree, int start, int end, int treenode){
    if(start == end){
        tree[treenode] = arr[start];
        return;
    }
    int mid = (start + end)/2;
    Buildtree(arr, tree, start, mid, (2 * treenode));
    Buildtree(arr, tree, mid+1, end, (2 * treenode)+1);
    tree[treenode] = tree[2 * treenode] + tree[(2 * treenode) + 1];
}

// Updation of values
void Updatetree(vector<int>&arr, vector<int>&tree, int start, int end, int treenode, int newval, int idx){
    if(start == end && (idx == start)){
        arr[idx] = newval;
        tree[treenode] = newval;
        return;
    }
    int mid = (start + end)/2;
    if(idx <= mid){
        Updatetree(arr, tree, start, mid, (2 * treenode), newval, idx);
    }
    else{
        Updatetree(arr,tree, mid+1, end, (2 * treenode)+1, newval, idx);
    }
    tree[treenode] = tree[2 * treenode] + tree[(2 * treenode) + 1];
}


// Query Operation on Segment tree
int Query(vector<int>&tree, int start, int end, int treenode, int left, int right){
    if(right < start || left > end){
        return 0;
    }
    if(start == left && end == right){
        return tree[treenode];
    }
    int mid = (start + end)/2;
    if(right <= mid){
        return Query(tree, start, mid, (2*treenode), left, right);
    }
    else if(left > mid){
        return Query(tree, mid + 1, end, (2*treenode)+1 , left, right);
    }
    else{
        int leftsum = Query(tree, start, mid, (2*treenode), left, mid);
        int rightsum = Query(tree, mid+1, end, (2*treenode)+1, mid+1, right);
        return leftsum + rightsum;
    }
}


int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // size of segment tree should always be 4*n approximately!
    vector<int>tree(4*n);

    // Building initial tree
    Buildtree(arr, tree, 0, n-1, 1);

    cout << "Menu: \n1. Query \n2. Update \n3. Display \n4. Quit \n\n";
    int operation;
    cout << "Enter operation number: ";
    cin >> operation;
    while(operation >0 && operation <4){
        if(operation == 1){
            
            // Query Opertion 
                int left, right;
                cout << "Enter range: ";
                cin >> left >> right;
                cout << Query(tree, 0, n-1, 1, left, right) << endl;
        }
        else if(operation == 2){

            // Updating values in initial tree
                int idx, newval;
                cout << "Enter new index and newvalue respectively: ";
                cin >> idx >> newval;
                Updatetree(arr, tree, 0, n-1, 1, newval, idx);
        }
        else if(operation == 3){

            // Display current segment tree            
                for(int i=1; i<(2*n); i++){
                    cout << tree[i] << "    ";
                }
                cout << endl; 
        }
        else{
            break;
        }
        cout << "Enter operation number: ";
        cin >> operation;
    }
    return 0;
}