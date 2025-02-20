class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums.size();
        string res = ""; //to store resultant unique binary string

        //Creating Unique string using Cantor's Diagonalization Approach 
        for(int i=0;i<n;i++)
        {
            res += (nums[i][i] == '0') ? '1' : '0';  //take diagonal elements of string and flip them so its 
        }                                         //compulsory we get unique binary string and this is what this claim  

        return res;  //at last return the resultant binary unique string 
    }
};