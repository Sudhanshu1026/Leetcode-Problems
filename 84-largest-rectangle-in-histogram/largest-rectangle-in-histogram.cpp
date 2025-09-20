class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>Right(n);  //To store NSR of each number
        vector<int>Left(n);  //To store NSL of each number
        stack<int>st;

        //Sabke Nearest Smallest Right-> ko find kro!
       for(int i=0;i<n;i++){
        while(!st.empty()  && heights[st.top()]>heights[i]){
            Right[st.top()]=i;
            st.pop();
        }
        st.push(i);
       }
       while(!st.empty()){  //Store NSR = n ->For those whom NSR do not exist.
        Right[st.top()]=n;
        st.pop();
       }

      

        //Sabke Nearest Smallest Left-> ko find kro!
        for(int i=n-1;i>=0;i--){
        while(!st.empty()  && heights[st.top()]>heights[i]){
            Left[st.top()]=i;
            st.pop();
        }
        st.push(i);
       }
       while(!st.empty()){  //Store NSL = -1  ->For those whom NSR do not exist.
        Left[st.top()]=-1;
        st.pop();
       }

        //Ans-> Sabke AREA ko find kro
        int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans , heights[i]* (Right[i]-Left[i]-1) );
    }

    return ans;
    }
};  