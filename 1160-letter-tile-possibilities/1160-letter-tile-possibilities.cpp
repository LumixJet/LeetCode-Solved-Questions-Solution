class Solution {
public:
    int n;
    void solve(string &tiles, vector<bool> &used, string &curr, unordered_set<string> &res)
    {
       if(!curr.empty()) //if current string is not empty then insert that string in res 
       {
            res.insert(curr);
       }

        for(int i=0;i<n;i++) //as we need to start exploring all times from start of string tiles to find all possibility
        {
            if(used[i] == true) //Base case : if the current character is used we skip that character as we 
            {                   //have not to repeat the same character
                continue;
            }

            //Following General template of Backtracking

            used[i] = true;   //DO     mark the current charcater as true 
            curr.push_back(tiles[i]); //and push that character in current 

            solve(tiles,used,curr,res); // Explore  all possibility for that character which can be present 

            used[i] = false; //Undo   Mark the current character as false and find all other possibilities with other character
            curr.pop_back(); //present in tile string and also remove that current character from current string
        } 
    }
    int numTilePossibilities(string tiles) 
    {
        n = tiles.length();
        vector<bool> used(n,false); //to mark all characters that has been used so they cannot be repeated
        
        string curr = ""; //to form the current string 
        unordered_set<string> res; //take unordered_set so each string gets stored as an answer only once

        solve(tiles,used,curr,res); //to recusively call to find all possible strings from given string tiles

        return res.size(); //at last size of unordered_set will be answer (as it stores all possible string)
    }
};