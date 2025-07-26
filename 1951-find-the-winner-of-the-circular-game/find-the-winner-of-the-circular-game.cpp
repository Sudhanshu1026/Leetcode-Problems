class Solution {
public:
int winner(vector<bool>&person,int n,int index,int person_left,int k){
    //Base cases
    if(person_left==1){
        //Search for winner
        for(int i=0;i<n;i++)
        {if(person[i]==0)
        return i;}
    }

//int kill :   will store the no's of steps to be moved to reach the next person
int kill=(k-1)%person_left;

while(kill--){
    index=(index+1)%n;

    while(person[index]==1) //moving forward if person is already dead
    index=(index+1)%n;
}
person[index]=1; //Kill the person found alive.

while(person[index]==1) //Finding next person to handover the gun
index=(index+1)%n;


//Call the same function for next alive person found

return winner(person,n,index,person_left-1,k);




}



    int findTheWinner(int n, int k) {
        //Will take a <bool> type 'vector' to keep track of killed persons !
        vector<bool>person(n,0);
        return winner(person,n,0,n,k)+1;  
        
        //winner()+1 :because we have solved for 0 based indexing and it will return 1 previous person as winner.


    }
};