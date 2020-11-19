//interview bit in stacks and queues
vector<int> Solution::slidingMaximum(const vector<int> &arr, int B) {
     deque<int> Qi(B); 
    int i; 
    vector<int>ans;
    int n=arr.size();
    for (i = 0; i < B; i++) { 

        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); 
        Qi.push_back(i); 
    } 
    ans.push_back(arr[Qi.front()]);
    for (; i < n; i++) { 
        
        while ((!Qi.empty()) && Qi.front() <= i - B) 
            Qi.pop_front();
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); 
  
        // Add current element at the rear of Qi 
        Qi.push_back(i); 
        ans.push_back(arr[Qi.front()]); 
    } 
    return ans;
    
}
