class Solution {
public:
    const int MOD = 1e9 + 7; //initialize the MOD
    int lengthAfterTransformations(string s, int t)
    {
        int n = s.length();
        vector<int> mp(26, 0); //as all character will lie between 0 to 25
        for(char ch : s)
        {
            mp[ch - 'a'] ++; //store frequency of all character which is present in s
        }
        for(int i=1; i<=t; i++) //traverse all the transforms
        {
            vector<int> mpp(26, 0); //make vector to store frequency of s (after each transforms)
            for(int i=0;i<26;i++)
            {
                char ch = i + 'a'; //converts the character in integer and store in ch
                int freq = mp[i]; //also store its frequency in freq

                if(ch != 'z') //if the character is not z
                {
                    //store its freq in next character in vector
                    mpp[(ch + 1) - 'a'] = (mpp[(ch + 1) - 'a'] + freq) % MOD;
                }
                else //if character is z then store its frequency in a and b
                {
                    mpp['a' - 'a'] = (mpp['a' - 'a'] + freq) % MOD;
                    mpp['b' - 'a'] = (mpp['b' - 'a'] + freq) % MOD;
                }
            }

            mp = move(mpp); //then move the mpp to mp vector to perform next transform
        }

        int res = 0; //after we perform all transforms we find the final string s frequency
        for(int i=0;i<26;i++) //of all characters which are present then that will be the
        {                               //length of new string after transform 1
            res = (res + mp[i]) % MOD;
        }

        return res; //at last we return res (length of string s after all transforms)
    }
};