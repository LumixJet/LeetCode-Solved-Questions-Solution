class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        set<int> temp1;
        set<int> temp2;
        int rev = 0;
        int n = s1.length(); 
        for(int i=0;i<n;i++)
        {
            if(s1[i] != s2[i])
            {
                if(temp2.find(s1[i]) != temp2.end() && temp1.find(s2[i]) != temp1.end())
                {
                    rev ++;
                    temp1.erase(s2[i]);
                    temp2.erase(s1[i]);
                }
                else
                {
                    temp1.insert(s1[i]);
                    temp2.insert(s2[i]);
                }

                if(rev >= 2 || temp1.size() >= 2 && temp2.size() >=2)
                {
                    return false;
                }
            }
        }
        if(temp1.empty() && temp2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};