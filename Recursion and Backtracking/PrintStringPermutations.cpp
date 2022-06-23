#include<bits/stdc++.h>
void findPermutations(int index, string &s, vector<string> &res){
    if(index == s.size()){
        res.push_back(s);
        return;
    }
    
    for(int i= index; i< s.size(); i++){
        swap(s[index], s[i]);
        findPermutations(index+1, s, res);
        swap(s[index], s[i]);
    }
}
vector<string> findPermutations(string &s) {
    vector<string> res;
    findPermutations(0, s, res);
    return res;
}