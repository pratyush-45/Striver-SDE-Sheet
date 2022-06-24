void words(string &s, int start, vector<string> &dictionary, vector<string> &res, string &curr){
    // If we have reached the end of string
    if(start >= s.size()){
        res.push_back(curr);
        return;
    }
    
    for(int i= start; i< s.size(); i++){
        string temp = s.substr(start, i-start+1);
        // Check if this word is present in the dictionary
        bool isPresent = false;
        for(auto it: dictionary){
            if(it == temp){
                isPresent = true;
                break;
            }
        }
        //If a word is present in dictionary 
        //then we try reamining string
        if(isPresent){
            string x = curr;
            // Push this to current ans
            curr += temp + " ";

            words(s, i+1, dictionary, res, curr);
            // Backtracking
            curr = x;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> res;
    string curr;
    
    words(s, 0, dictionary, res, curr);
    
    return res;
}