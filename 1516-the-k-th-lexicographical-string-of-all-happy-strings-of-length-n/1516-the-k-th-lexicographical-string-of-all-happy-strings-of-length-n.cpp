class Solution {
public:
    vector<string> arr; //to store all strings of length n which follows all condition as per question
    void solve(vector<string> &arr, string &res, int  n) //we use backtracking 
    {
        if(res.length() == n) //if we found current string length becomes equal to n that means we find one 
        {                                                       //possible string following the given condition
            arr.push_back(res); //push that current string in arr
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++) //condition we can take character from a to c only and make string
        {
            if(!res.empty() && res.back() == ch) //base case : if current string res is not empty and its 
            {                                   //last character is same as current character we skip that 
                continue;                      //character and find string with next character 
            }
        
            //General template for backtracking

            res.push_back(ch); //Do this (push the current character in current string)

            solve(arr,res,n);  //Explore (all possiblity with remaining character present recursively)

            res.pop_back(); //Undo (the current character to check for all other possibility)

        }
    }
    string getHappyString(int n, int k) 
    {   
        string res = ""; //to store current string which we got

        solve(arr,res,n); //call recursively for finding all possible n strings following given condition

        if(arr.size() < k) //if number of strings following given condition is less than k that means we dont
        {
            return ""; //have k th number string so we return empty string
        }

        return arr[k-1]; //at last we return k-1(0-indexed) string from array which stores all n size string 
    }
};