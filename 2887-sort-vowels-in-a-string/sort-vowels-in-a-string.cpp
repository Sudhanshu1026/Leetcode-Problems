class Solution {
public:
    string sortVowels(string s) {
        
vector<int>lower(26,0);
vector<int>upper(26,0);

//Storing the occurence of vowels in upper and lower case !

for(int i=0;i<s.size();i++){

if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ){
   { lower[s[i]-'a']++;
   s[i]='#';      //Making a space in real string 's' for later updation !
   }
}

else if(s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ){
   { upper[s[i]-'A']++;
   s[i]='#';      
   }
}


}


string ans;   //To store sorted vowels!

//Sorting and adding upper case vowels ! in 'ans'
for(int i=0;i<26;i++){
    char c ='A'+i;
    while(upper[i]){
        ans+=c;
        upper[i]--;
    }
}

//Sorting and adding  lower case vowels ! in 'ans'
for(int i=0;i<26;i++){
    char c ='a'+i;
    while(lower[i]){
        ans+=c;
        lower[i]--;
    }
}


//Now we will use two pointers first & second to update sorted vowels in real string 's'

int first=0;
int second=0;

while(second<ans.size()){
    if(s[first]=='#'){
        s[first]=ans[second];
        second++;
    }
    first++;
}

return s;

    }
};