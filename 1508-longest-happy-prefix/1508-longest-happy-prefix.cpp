class Solution {
public:
    int computeLPS(string &s, vector<int> &lps)
    {
        int n = lps.size();

        lps[0] = 0;

        int len = 0;
        int i = 1;
        while(i < n)
        {
            if(s[i] == s[len])
            {   
                len ++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len == 0)
                {
                    lps[i] = len;
                    i ++;
                }
                else
                {
                    len = lps[len - 1];
                }
            }
        }
        return lps[n-1];
    }
    string longestPrefix(string s) //just use KMP and find longest substring which is proper 
    {                             //prefix and suffix and that will be the answer
        int n = s.length();

        vector<int> lps(n, 0);
        int maxLenHappy = computeLPS(s, lps);

        string ans = s.substr(0, maxLenHappy);
        return ans; 
    }
};