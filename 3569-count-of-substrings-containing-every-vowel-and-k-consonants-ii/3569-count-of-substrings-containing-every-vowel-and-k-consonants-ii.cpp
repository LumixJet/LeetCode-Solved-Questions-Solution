class Solution {
public:
    bool isVowel(char ch) //function to check weather the character is vowel or consonant
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    long long countOfSubstrings(string word, int k) 
    {
        int n = word.length();
        unordered_map<char,int> mpp; //to store vowel and there count in a perticular window

        //Preprocessing to be able to find index of just next consonant 

        vector<int> nxtConso(n); //to store index of next nearest consonant in string from current index
        int lastConso = n; //variable to store nearest consonant as we start from last index of string so we initialize it with out of bound 
                                                                        //index as consonant cant be present after last character in string

        for(int i=n-1; i>=0; i--) //iterating from last of string to store nearest consonant of current character in string in O(1) time complexity
        {
            nxtConso[i] = lastConso; //store nearest consonant index at current character index of string

            if(!isVowel(word[i])) //if current character of string is not a vowel then initialize lastConso with current character 
            {                    
                lastConso = i; //index as this is nearest consonant from now onwards to all rest character of string present in left 
            } 
        }

        //Now Normal Sliding Window Technique

        int i=0; //used to shrink the window 
        int j=0; //user to find a valid window

        int conso = 0; //to store count of consonant for window
        long long count = 0; //to store final answer which tells number of possible substrings which we can get

        while(j<n)
        {
            char ch = word[j];
            if(isVowel(ch)) //if current character is vowel then include it in map with its frequency 
            {
                mpp[ch] ++;
            }
            else //otheriwse increase the count of consonant
            {
                conso ++;
            }

            while(conso > k) //if window gets more than k consonant than it will not get valid string so we need 
            {                          //we need to shrink the window size till we dont get consonant less than k

                char ch = word[i]; 
                if(isVowel(ch)) //if current character which is getting removed to shrink the window is vowel 
                {
                    mpp[ch] --; //we decrease its frequency in map
                    if(mpp[ch] == 0) //if frequency of that vowel becomes 0 then we remove that character from map
                    {
                        mpp.erase(ch);
                    }
                }
                else //otherwise if current character is consonant then we decrease count of consonant in window
                {
                    conso --;
                }
                i++; //and we keep on shrinking the size of window by incrementing i pointer till we dont get count of consonant less than k
            }

            while(mpp.size() == 5 && conso == k) //if we get valid window
            {
                int index = nxtConso[j]; //then we find nearest next consonant in right of current window from nxtConso vector
                count += index - j; //and compute total number of valid strings which we can make  

                char ch = word[i]; //after that we shrink the current window
                if(isVowel(ch)) //if character which will get remove is vowel 
                {
                    mpp[ch] --; //then we decrease its frequency from map
                    if(mpp[ch] == 0) //and if frequency of current character gets 0 than we remove current character from map
                    {
                        mpp.erase(ch);
                    }
                }
                else //otherwise if current character is a consonant that we decrease count of consonant 
                {
                    conso --;
                }
                i++; //we keep on shrinking the size of window till the time we get valid window 
            }
            j++; //if we dont get valid window we keep on iterating the strind till the time we dont get valid window
        }

        return count; //at last we return total possible substring which we can get from given string  
    }
};