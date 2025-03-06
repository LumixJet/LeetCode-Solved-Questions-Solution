class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        int n = nums.size();
        vector<int> left; //to store number which are smaller than pivot in nums
        vector<int> right; //to store number which are greater than pivot in nums
        vector<int> piv; //to store all pivot elements present in nums

        for(int i=0; i<n; i++)
        {
            if(nums[i] == pivot) //if current number is same as pivot 
            {
                piv.push_back(nums[i]); //then we push back the elements in piv array 
            }
            if(nums[i] < pivot) //if current number is less than pivot element 
            {
                left.push_back(nums[i]); //then we push back element in left array 
            }
            if(nums[i] > pivot) //if current number is greater than pivot element 
            {
                right.push_back(nums[i]); //then we push the element in right array
            }
        }
        left.insert(left.end(), piv.begin(), piv.end()); //store all element of piv array at back of left array
        left.insert(left.end(), right.begin(), right.end());//store all element of right array at back of left array

        return left;   //at last we return left array as an answer
    }
};