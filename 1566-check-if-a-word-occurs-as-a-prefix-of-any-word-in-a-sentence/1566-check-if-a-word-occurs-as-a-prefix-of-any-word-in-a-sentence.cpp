class Solution {
public:
    vector<string> splitter(string s){
        vector<string> arr;
        string sr;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                sr+=s[i];
            }else{
                arr.push_back(sr);
                sr = "";
            }
        }
        if (!sr.empty()) {
            arr.push_back(sr);
        }
        return arr;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
     vector<string> s;
     s = splitter(sentence);  
     for(int i=0;i<s.size();i++){
         if (s[i].substr(0, searchWord.size()) == searchWord) {
            return i+1;
        }
     } 
     return -1;
    }
};