class Solution {
public:
    bool isArraySpecial(vector<int>& arr) 
    {
        int flag = false;
        int n = arr.size();
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] % 2 == 0 && arr[i + 1] % 2 != 0)
            {
                continue;
            }
            else if(arr[i] % 2 != 0 && arr[i+1] % 2 == 0)
            {
                continue;
            }
            else
            {
                flag = true;
            }
        }
        if(flag == true)
        {
            return false;
        }
        else
        {
            return true;
        }   
    }
};