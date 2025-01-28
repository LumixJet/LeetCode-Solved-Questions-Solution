class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int cnt = 0;
        int nums = derived.size();
        for(int i=0;i<nums;i++) 
        {
            if(derived[i] == 1) //we count the numbe of 1's present in derived array 
            {
                cnt ++;
            }
        }
        if(cnt % 2 == 0) //if the count of 1's in derived array is even then there
        {            //exist a original array from which we can derive derived array
            return true;
        }
        else //otherwise it is not possible to find original array from which we 
        {               //can derive derived array
            return false;
        }    
    }
};