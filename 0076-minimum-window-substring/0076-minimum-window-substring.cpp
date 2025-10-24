//Order does not matter to match t with s
class Solution {
public:
    bool allZeroesOrLess(const unordered_map<char, int> &mppT)
    {
        for(auto & [key, val] : mppT){
            if(val > 0){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) 
    {
        int n = s.size();

        string ans = "";
        int left = 0, right = 0;
        
        unordered_map<char, int> mppT;
        for(char ch : t){
            mppT[ch] ++;
        }

        while(right < n) {
            
            if(mppT.find(s[right]) != mppT.end()){ //if s char is present in t
                mppT[s[right]] --;
            }

            if(allZeroesOrLess(mppT)){        //we got a valid window
                
                while(left <= right && (mppT.find(s[left]) == mppT.end() || mppT[s[left]] < 0)){ 
                    if(mppT.find(s[left]) != mppT.end()){
                        if(mppT[s[left]] < 0){ //means more such value later in window so we can shrink
                            mppT[s[left]] ++;
                        }
                        else{ //window cannot be shrinked this is smallest possible ans window
                            break; 
                        }
                    }

                    left ++;
                }

                if(ans.empty() || ans.size() > (right - left + 1)){
                    ans = s.substr(left, right - left + 1); //always store min window substring till curr pos
                }
            }  

            right ++; 
        }  

        return ans;
    }
};