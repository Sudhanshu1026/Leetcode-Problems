class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        //create a queue 
        queue<int>q;
        //Fill queue with the indices
        for(int i=0;i<tickets.size();i++)
        q.push(i);

        int time =0;
        while(tickets[k]!=0){
            tickets[q.front()]--;  //reduce ticket by 1

            //check if will join the queue or not
            if(tickets[q.front()])
            q.push(q.front());

            q.pop();
            time++;
        }
        return time;
    }
};