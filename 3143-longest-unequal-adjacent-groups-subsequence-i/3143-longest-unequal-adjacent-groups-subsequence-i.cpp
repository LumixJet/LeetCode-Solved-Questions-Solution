class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        int n = groups.size(); 
        vector<string> res; //this stores the string each time for each traversal 
        vector<string> result; //this stores the string which is our final answer
        int maxi = 0; //maxi stores the length of final string which will be our final answer

        for(int i = 0; i < n; i++) //we iterate over all the characters of the string
        {
            res.clear(); //each time we clear the string to generate the new string
            int temp = groups[i]; //stores groups value in temp 
            res.push_back(words[i]); //and store the character in res
            
            for(int j = i + 1; j < n; j++) //then iterate the next characters present in words
            {
                if(temp != groups[j]) //if temp and groups are different then that means we can take 
                {                         //that index words in our res as it is different from previous one

                    temp = groups[j]; //now we change temp to recent groups[j]
                    res.push_back(words[j]); //and push the corresponding index words in res
                }
            }

            int nums = res.size(); //after one string res is formed then we store its size in nums
            if(maxi < nums) //if we get any string of bigger length then maxi 
            {
                result = res; //then we update our final string result 
                maxi = nums; //and also update maxi with length of new string which get stored in result
            }
        }

        return result; //at last we return result which is our answer
    }
};
