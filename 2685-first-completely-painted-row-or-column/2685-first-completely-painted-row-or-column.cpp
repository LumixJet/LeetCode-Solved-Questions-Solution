class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, int> mpp; //to store index of elements present in array 
        int len = arr.size();

        for(int i=0;i<len;i++) //store index of each elemet of array 
        {
            mpp[arr[i]] = i;
        }
        
        int ans= INT_MAX;

        //check row painting in matrix by iterating to each row of matrix
        for(int i=0;i<n;i++)
        {
            int curr = INT_MIN;
            for(int j=0;j<m;j++) //check max index which is required to make one row of array painted
            {
                curr = max(curr, mpp[mat[i][j]]); //stores max index of value in array that will make this row 
            }                                     //completely painted.
            //stores min index at which out 
            ans = min(ans, curr); //of all row one row will get completely painted
        }

        //check column painting by iterating throgh each column of matrix
        for(int j=0;j<m;j++)
        {   
            int curr = INT_MIN;
            for(int i=0;i<n;i++) //check max index which is required to make 1 column of array painted
            {
                curr = max(curr, mpp[mat[i][j]]); //stores max index of value in array that will make this column
            }                                     //completely painted
            //stores min index at which out 
            ans = min(ans, curr); //of all column one column will get completely painted 
        }

        return ans; //min(row or column) will make one row or column of matrix completely painted.
    }
};