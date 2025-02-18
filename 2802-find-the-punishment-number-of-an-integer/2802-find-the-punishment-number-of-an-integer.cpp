class Solution {
public:
    bool check(int index,string s,int i) //check if number can form by doing sum of digits of square of number in any way
    {
        if(index == s.length() && i == 0) //base case : if we traverse string completely or i (current sum) gets 0 
        {
            return true; //means the current number is a punishment number
        }
        for(int j=index;j<s.length();j++) //check for all possible way in which we can make sum of digits = number
        {
            int sum = stoi(s.substr(index,j-index+1)); //find sum of each digit present in square of a number

            if(sum > i) //if sum of digits of square of number is greater than the number  
            {
                return false; //we return false;
            }
            if(check(j+1,s,i-sum)) //check for remaining digits sum  of square of a number weather they can form 
            {
                return true;  // equal to number if yes we return true
            }
        }
        return false; //if we are not able to form sum of digits of square of number in any way we return false
    }
    int punishmentNumber(int n) 
    {
        int res = 0; 
        for(int i=1;i<=n;i++) //iterating from 1 to n to check which number satisfy punishment number case
        {
            int sq = i*i; //finding square of a current number
            string s = to_string(sq); //converting square of a current number to string

            if(check(0,s,i)) //check if the number is a punishment number 
            {
                res += sq; //add its square to the res variable
            }
        }
        return res; //return all punishment number from 1 to n there square sum 
    }
};