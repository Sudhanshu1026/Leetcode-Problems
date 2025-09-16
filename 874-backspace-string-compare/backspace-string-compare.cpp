class Solution {
public:

string refine(string &str){
    stack<char>st;

    for(int i=0;i<str.size();i++){
        if(str[i]!='#')
        st.push(str[i]);
        else if(!st.empty())
        st.pop();
    }

  string refinedstr;
  while(!st.empty()){
    refinedstr.push_back(st.top());
    st.pop();
  }

    return refinedstr;
}


    bool backspaceCompare(string s, string t) {
        s= refine(s);
        t= refine(t);

        return s==t;
    }
};