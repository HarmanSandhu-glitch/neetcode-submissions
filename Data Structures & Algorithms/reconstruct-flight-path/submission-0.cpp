class Solution {
public:
    vector<string> answer;

    void help(map<string, priority_queue<string, vector<string>, greater<string>>> &neighbours,
              string beginStation) {
        
        auto &pq = neighbours[beginStation];
        
        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();
            help(neighbours, next);
        }
        
        answer.push_back(beginStation);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> neighbours;

        for (auto &ticket : tickets) {
            neighbours[ticket[0]].push(ticket[1]);
        }

        help(neighbours, "JFK");
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};