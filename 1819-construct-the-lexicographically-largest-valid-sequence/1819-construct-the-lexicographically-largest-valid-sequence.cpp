class Solution {
public:
    vector<int> arr; //array to store the final answer which is lexicographically largest valid sequence 
    vector<bool> used; //array to mark which all elements are used 

    int nums; //size of final answer array arr
    bool solve(int pos, int n)
    {
        if(pos == nums) //if pos becomes equal to nums that means we found the valid sequence
        {
            return true; //so we return true 
        }
        if(arr[pos] != 0) //if some number is placed already at current position we 
        {
            return solve(pos+1,n); //move to next number to fill respective vacant places
        }
        for(int i=n;i>0;i--) //To form largest lexicographic sequence we start from end and place largest
        {                                                                           //number in 1st place
            if(used[i] == true) //if the value is used in the sequence previously 
            {
                continue; //then we skip and try to assign the next value at that current place
            }
            if(i == 1) //if we get 1 as current number to fill the current vacant place
            {
                arr[pos] = 1; //fill 1 at that place
                used[i] = true; //mark 1 as used/true

                if(solve(pos+1,n)) //call recursively to fill all the vacant position and to build the complete array 
                {                
                    return true; //and if we are able to build the array by following all the condition then we return true
                }
                arr[pos] = 0; //if not then we mark that position/place as 0 and also mark 1 as false in used array 
                used[i] = false;
            }
            else if(pos + i < nums && arr[pos + i] == 0) //if position + current number is < nums and that place does not has
            {                                                                           //some value present in it previously 
                arr[pos] = arr[pos + i] = i; //place current value at both positions
                used[i] = true; //mark current number as true

                if(solve(pos+1,n)) //call recursively for next vacant places to build lexicographically largest valid sequence 
                {
                    return true; //and if we are able to build the array bu following all condition we return true
                }
                arr[pos] = arr[pos + i] = 0; //if not then we mark both position as 0 and also mark false for current value
                used[i] = false;
            }
        }       //if by trying all possibility we dont return true then at last we return false means required lexicographically
        return false; //largest valid sequence cannot be formed 
    }
    vector<int> constructDistancedSequence(int n) 
    {
        nums = n + (n-1); //lexicographically largest valid sequence will be of this length

        arr.assign(nums,0); //assign 0 intially to all places of array arr
        used.assign(n+1, false); //assign false to all places of used array

        solve(0,n); //call solve function recursively to find the valid sequence 
        return arr; 
    }
};