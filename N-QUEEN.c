#include<stdio.h>
int count=0;
int noAttack(char board[100][100],int row,int col,int n){
    //sabse pehele check kar ki same row me doosri raani toh nahi baithi hai
    for(int y=0;y<n;y++){
        if(board[row][y]=='Q')
        return 0;//mtlb attack hoga
    }
    //ab colm dekho ki same raani toh nahi
    for(int x=0;x<n;x++){
        if(board[x][col]=='Q')
        return 0;//attack hoga
    }
    //ab row colm hogaya diagonal dekhte hai,dekho yaha niche toh hai nahii bas upper left aur right diagonal dekhni hai
    int i=0,j=0;
    //upper left diagonal
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
         if(board[i][j]=='Q')
                return 0;//attack hoga
    }
    //upper right diagonal
     for(i=row,j=col;i>=0 && j<n;i--,j++){

         if(board[i][j]=='Q')
                return 0;//attack hoga
    }
    //Ab agar itna sab check karne ke baad bhi, kuch nahi mila, matlab Sab clear hai, no issue
    //bindass one return kardo.
    return 1;
}
int NQueenProblem(char board[100][100],int n,int row)
{
    //if we get to the end of the board that is last row fir base condn achieved print all sol
    if(row==n){
        printf("-------Solution:%d------------\n",++count);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c",board[i][j]);
            }
            printf("\n");
        }
        //return 1; nahi karna isse sirf ek solution milega
        /*IMPORTANT: Remember if we return 1 we just get one solution that is base solution
        but we want all the possible solutions so return 0 jisse,backtracking complete hogi*/
        return 0;
    }
    //badiya,ab recursion se queen place karni hai row me colm by colm check karte jaenge
    for(int col=0;col<n;col++){
        //pehele check if there is no attack at current position by passing row and colm
        if(noAttack(board,row,col,n)){
            board[row][col]='Q';
            int agliQueenRakhSakte = NQueenProblem(board,n,row+1);
            if(agliQueenRakhSakte==1){
                return 1;
            }
            else{
                board[row][col]='-';
            }
        }
    }
    return 0;//bactrackiing hori hai
}
void main(){
    char board[100][100]; //apne board define karliya size:NXN
    int n;
    printf("\n Enter the number of Queens:\t");
    scanf("%d",&n);
    //saari positions ko initialise kardo with '-'
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]='-';
        }
    }
    //ab yeh board aur no of queens and the starting row ki position yaha 0
    NQueenProblem(board,n,0);
}