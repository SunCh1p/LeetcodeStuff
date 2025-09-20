class Spreadsheet {
public:
    Spreadsheet(int rows) {
    }
    
    void setCell(string cell, int value) {
        hash[cell] = value;
    }
    
    void resetCell(string cell) {
        hash.erase(cell);
    }
    
    int getValue(string formula) {
        string term1 {""};
        string term2 {""};
        bool foundOperator = false;
        //parse of the formula
        for(auto c: formula){
            if(c == '='){
                continue;
            }
            if(c == '+'){
                foundOperator = true;
                continue;
            }
            if(!foundOperator){
                term1+=c;
            } else {
                term2+=c;
            }
        }
        int val1 = 0;
        int val2 = 0;
        //check if term1 exists in hash table
        if(hash.find(term1) != hash.end()){
            val1 = hash[term1];
        } else {
            if(isalpha(term1[0])){
                val1 = 0;
            } else {
                val1 = stoi(term1);
            }
        }
        //check if term2 exists in hash table
        if(hash.find(term2) != hash.end()){
            val2 = hash[term2];
        } else {
            if(isalpha(term2[0])){
                val2 = 0;
            } else {
                val2 = stoi(term2);
            }
        }
        return val1+val2;
    }
private:
    unordered_map<string, int> hash;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */