class Solution {
public:
    vector<string> answer;
    void help(string s,int pairsLeft,int openBrackets){
        if(pairsLeft == 0){
            while(openBrackets--){
                s += ')';
            }
            answer.push_back(s);
            return;
        }
        if(openBrackets > 0){
            // choosing to close it
            help(s + ')',pairsLeft,openBrackets-1);
        }
        if(pairsLeft > 0){
            help(s+'(',pairsLeft-1,openBrackets+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        help("",n,0);
        return answer;
    }
};
