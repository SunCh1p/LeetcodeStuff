class Solution {
public:
    bool isVowel(char c){
        c = toupper(c);
        return (c == 'A' || c == 'O' || c == 'E' || c == 'I' || c == 'U');
    }

    string toUpperCase(string s){
        string tmp = "";
        for(auto c: s){
            tmp += toupper(c);
        }
        return tmp;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        //precedence
        //exact match
        unordered_set<string> perfectMatch;
        //capitalization
        unordered_map<string, vector<string>> caseMatch;
        //vowel errors
        unordered_map<string, vector<string>> vowelWords;
        //pre processing phase
        //populate exact match
        for(auto word: wordlist){
            //populate exact match
            perfectMatch.insert(word);
            string tmp = toUpperCase(word);
            //populate case match
            caseMatch[tmp].push_back(word);
            //populate vowel match
            for(int i = 0; i < tmp.size(); i++){
                if(isVowel(tmp[i])){
                    tmp[i] = '*';
                }
            }
            vowelWords[tmp].push_back(word);
        }
        vector<string> res;
        for(auto word: queries){
            if(perfectMatch.contains(word)){
                res.push_back(word);
                continue;
            }
            //check if case match
            string tmp = toUpperCase(word);
            if(caseMatch.contains(tmp)){
                res.push_back(caseMatch[tmp][0]);
                continue;
            }
            //check vowel match
            //convert tmp
            for(int i = 0; i < tmp.size(); i++){
                if(isVowel(tmp[i])){
                    tmp[i] = '*';
                }
            }
            if(vowelWords.contains(tmp)){
                res.push_back(vowelWords[tmp][0]);
                continue;
            }
            res.push_back("");
        }
        return res;
    }
};