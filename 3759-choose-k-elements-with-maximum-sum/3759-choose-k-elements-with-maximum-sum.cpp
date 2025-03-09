class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size();
        priority_queue<int, vector<int>, greater<int>> pq; //min heap to store top k values
        vector<pair<int, pair<int, int>>> arr; //store {nums1[i], i, nums2[i]}
        
        for(int i=0; i<n; i++) //store corresponding values in arr {nums1[i], i, nums2[i]}
        {
            arr.push_back({nums1[i], {i, nums2[i]}});
        }

        sort(arr.begin(), arr.end()); //sort the values with respect to nums1[i]

        vector<long long> res(n,0); //to store final result vector
        long long sum = 0; //to find the corresponding top k elements sum
        
        for(int i=0;i<n;i++) //iterate over array arr
        {
            int index = arr[i].second.first; //find corresponding index of that value
            int value = arr[i].second.second; //find respective values
            
            if(i > 0 && arr[i].first == arr[i-1].first) //if there are duplicate values present in array nums like
            {                                          //test case-2 store its corresponding earlier values
                res[index] = res[arr[i-1].second.first];  //at current place too              
            }
            else //otherwise we store calculated sum value at its corresponding index
            {
                res[index] = sum;
            }

            pq.push(value); //then we push the value in priority queue
            sum += value; //and also add the result to sum
            
            if(pq.size() > k) //if pq gets larger than k the moment, then we pop the element from pq such that we
            {                                                           //have top k elements present in heap
                sum -= pq.top(); //also we subtract the value from sum
                pq.pop(); //and remove from heap
            }
        }
        return res; //finally we return the res vector
    }
};