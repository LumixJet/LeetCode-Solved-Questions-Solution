class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> romanMap{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int result=romanMap[s[s.length()-1]];
        for(int i=s.length()-2;i>=0;i--)
        {
            if(romanMap[s[i]]<romanMap[s[i+1]])
            {
                result=result-romanMap[s[i]];
            }
            else
            {
                result=result+romanMap[s[i]];
            }
        }
        return result;
     }
}; 