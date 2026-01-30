// 948. Bag of Tokens
// You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] denotes the value of tokeni.

// Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

// Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
// Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
// Return the maximum possible score you can achieve after playing any number of tokens.

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0)return 0;
        sort(tokens.begin(),tokens.end());
        deque<int>dq;
        for(int i:tokens)dq.push_back(i);
        int score=0;

        while(dq.size()>1){
            if(score==0 && dq.front()>power)break;
            if(dq.front()<=power){
                power-=dq.front();
                
                dq.pop_front();
                score++;
            }
            else if(dq.size()>1 && score>0){
                power+=dq.back();
                
                dq.pop_back();
                score--;
            }
        }
        if(dq.front()<=power)score++;
        return score;

    }
};