class Solution {
public:

    //solution 1 - more Space complexity 

    // vector<string> splitter(string s){
    //     vector<string> arr;
    //     string sr;
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]!=' '){
    //             sr+=s[i];
    //         }else{
    //             arr.push_back(sr);
    //             sr = "";
    //         }
    //     }
    //     if (!sr.empty()) {
    //         arr.push_back(sr);
    //     }
    //     return arr;
    // }
    // int isPrefixOfWord(string sentence, string searchWord) {
    //  vector<string> s;
    //  s = splitter(sentence);  
    //  for(int i=0;i<s.size();i++){
    //      if (s[i].substr(0, searchWord.size()) == searchWord) {
    //         return i+1;
    //     }
    //  } 
    //  return -1;
    // }

    // solution 2

    int isPrefixOfWord(string sentence, string searchWord) {
    int wordIndex = 1;
    int i = 0, n = sentence.length();

    while (i < n) {
        int start = i;
       
        while (i < n && sentence[i] != ' ') {
            i++;
        }

       
        string currentWord = sentence.substr(start, i - start);

       
        if (currentWord.substr(0, searchWord.size()) == searchWord) {
            return wordIndex;
        }

        
        wordIndex++;
        i++;
    }

    return -1; // No match found
}

};