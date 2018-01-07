class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        bool valid = true;
        int i;
        set<char> row1;
        set<char> row2;
        set<char> row3;
        char  r1[]= {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
        row1.insert (r1,r1+20);
        
        char r2[] = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
        row2.insert(r2,r2+18);
        
        char r3[] = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
        row3.insert(r3,r3+14);
        
        vector<string> result;
        
        for(int iter = 0, size = words.size(); iter< size;iter++){
            valid = true;
            for(i = 0; i < words[iter].length(); i++){
                if(row1.find(words[iter][i]) != row1.end() ){
                    continue;
                }
                else{
                    break;
                }
            }
            if(i == words[iter].length()){
                result.push_back(words[iter]);
            }
            //checking row 2
            for(i = 0; i < words[iter].length(); i++){
                if(row2.find(words[iter][i]) != row2.end() ){
                    continue;
                }
                else{
                    break;
                }
            }
            if(i == words[iter].length()){
                result.push_back(words[iter]);
            }
            //checking row 3
            for(i = 0; i < words[iter].length(); i++){
                if(row3.find(words[iter][i]) != row3.end() ){
                    continue;
                }
                else{
                    break;
                }
            }
            if(i == words[iter].length()){
                result.push_back(words[iter]);
            }
            
        }
        return result;
    }
};
