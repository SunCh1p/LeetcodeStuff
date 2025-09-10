class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> peopleNeedingHelp;
        for(auto friendship: friendships){
            //record langauges first person in pair knows
            unordered_set<int> languagesPersonAKnows;
            for(int language: languages[friendship[0]-1]){
                languagesPersonAKnows.insert(language);
            }
            //see if person b knows them
            bool canCommunicate = false;
            for(int language: languages[friendship[1]-1]){
                if(languagesPersonAKnows.find(language) != languagesPersonAKnows.end()){
                    canCommunicate = true;
                    break;
                }
            }
            //if they can't communicate, add them to the set
            if(!canCommunicate){
                peopleNeedingHelp.insert(friendship[0]-1);
                peopleNeedingHelp.insert(friendship[1]-1);
            }
        }
        //greedily choose most commonly known language among the people who don't know
        int maxCount = 0;
        vector<int> languageCount(n+1, 0);
        for(auto friendship: peopleNeedingHelp){
            for(int lang: languages[friendship]){
                languageCount[lang]++;
                maxCount = max(maxCount, languageCount[lang]);
            }
        }
        //return what ever the max count is subtracted from the population
        return peopleNeedingHelp.size()-maxCount;
    }
};