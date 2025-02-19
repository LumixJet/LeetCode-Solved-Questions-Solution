class Solution {
public:
    string smallestNumber(string pat) 
    {   
        string res = ""; //to store final resultant string 
        int n = pat.length();
        stack<int> st; //taking stack to construct res as smallest lexographic possible string
        int num = 1; 
        for(int i=0;i<=n;i++) //iterate through entire patter string pat.
        {
            st.push(num ++); //to store number one by one in stack as we iterate pat string

            if(i == n || pat[i] == 'I') //if we get I in pat or i gets equal to n 
            {
                while(!st.empty()) //take out all numbers present in stack till the time stack
                {                                                         //does not get empty
                    res += to_string(st.top()); //and store in res string
                    st.pop(); //and pop the numbers from stack simulatenously 
                }
            }
        }             //as per given condtion we built res string and 
        return res; //at last we return final string which is lexographich smallest string 
    }
};