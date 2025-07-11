class Solution {
public:


 void lpsfind(vector<int>&lps,string s){

int pre=0,suf=1;
while(suf<s.size()){
    if(s[pre]==s[suf]){
        lps[suf]=pre+1;
        pre++;
        suf++;
    }
    else{
        if(pre==0){
            lps[suf]=0;
            suf++;
        }
            else
            pre=lps[pre-1];
            
        }
    }
}




//Main function
    int KMP_MATCH(string s1, string s2) {
        vector<int>lps(s2.size(),0);
        

        //Function to find LPS of string 2nd 
        lpsfind(lps,s2);

int first=0,second=0;
while( second<s2.size() && first<s1.size()){

    if(s1[first]==s2[second]){        //dono equal hai ,dono age badhenge
        second++;
        first++;
    }
    else{
        if(second==0)               //second already 0 pr hai
        first++;
        else
        second=lps[second-1];         //Last lps pr le jao , wha se comapre kro
    }
}

if(second==s2.size())
return 1;

return 0;
    }


    int repeatedStringMatch(string a, string b) {
        
        //Agar Dono same hai
        if (a==b)
        return 1;
   
     int repeat=1;
     string temp = a;
      

      // 'a' ko 'b' ke size ke barabar ya uss se bada krna hai 
     while(temp.size()<b.size()){
        temp+=a;
        repeat++;
     }
     // KMP pattern search

    if(KMP_MATCH(temp,b)==1)
        return repeat;
    
     //'temp+a' -> KMP pattern search
     
     if(KMP_MATCH(temp+a,b)==1)
        return repeat+1;
     

     return -1;



    }
};