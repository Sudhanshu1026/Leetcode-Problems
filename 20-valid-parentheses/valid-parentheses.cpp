class Solution {
public:
    bool isValid(string s) {
        stack <char> st;  // To store open brackets.



     for(int i=0;i<s.size();i++){
     //Get open bracket
     if(s[i]=='(' || s[i]=='{' || s[i]=='[')
      st.push(s[i]);
     else // Get a close bracket
     {
       //Check for empty
       if(st.empty())       //Empty Stack + close bracket= Never possible->Invalid
       return 0;
       else if(s[i]==')')
       {
        if(st.top()!='(')
        return 0;
        else
        st.pop();
       }
       else if(s[i]=='}')
       {
        if(st.top()!='{')
        return 0;
        else
        st.pop();
       }
       else if(s[i]==']')
       {
        if(st.top()!='[')
        return 0;
        else
        st.pop();
       }

     } 

       }
    return st.empty();

    }
};