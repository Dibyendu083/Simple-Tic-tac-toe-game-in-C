#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
char board[3][3]={'1','2','3','4','5','6','7','8','9'};

int count=0;
char ply1[20],ply2[20];
void New_board()
{
    int i,j;
    char k='1';
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board[i][j]=k;
            k++;
        }
    }

}
void Drawboard()
{
    int i,j;
    for(i=0;i<3;i++)
        printf("\n");
    printf("\n\t|--|--|--|\n");
    for(i=0;i<3;i++)
    {
        printf("\t|");
        for(j=0;j<3;j++)
        {

            printf("%c |",board[i][j]);

        }
       printf("\n\t|--|--|--|\n");
    }
}
char Check_Win()
{

    if(board[0][0]=='X' && board[0][1]=='X' && board[0][2]=='X')
        return 'X';
    if(board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X')
        return 'X';
    if(board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X')
        return 'X';
    if(board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X')
       return 'X';
    if(board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X')
        return 'X';
    if(board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X')
        return 'X';
    if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')
        return 'X';
    if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')
        return 'X';
     if(board[0][0]=='O' && board[0][1]=='O' && board[0][2]=='O')
        return 'O';
    if(board[1][0]=='O' && board[1][1]=='O' && board[1][2]=='O')
        return 'O';
     if(board[2][0]=='O' && board[2][1]=='O' && board[2][2]=='O')
        return 'O';
     if(board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O')
        return 'O';
     if(board[0][1]=='O' && board[1][1]=='O' && board[2][1]=='O')
        return 'O';
     if(board[0][2]=='O' && board[1][2]=='O' && board[2][2]=='O')
        return 'O';
    if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')
        return 'O';
    if(board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')
        return 'O';
    else return 'D';

}
void input()
{
    int i,j;
    char a,n;
while(1)
{
    Drawboard();
    printf("Its %s Turn :- ",ply1);
    scanf(" %c",&n);
    fflush(stdin);
    count++;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(n==board[i][j])
             {
                if(count%2==0)
                  board[i][j]='O';
                else
                board[i][j]='X';
               break;

             }
        }
    }
    system("cls");
   // clrscr();
    Drawboard();
    a=Check_Win();
    if(a=='X')
    {
    printf("CONGOO !! %s You Won The Game!!",ply1);
    break;
    }


    else if(a=='D' && count==9)
   {
    printf("Its a Draw!!\nGame Over!!");
    count=0;
    break;
   }
system("cls");
//clrscr();
Drawboard();
printf("\n Its %s Turn ",ply2);
scanf(" %c",&n);
fflush(stdin);
count++;

for(i=0;i<3;i++)
{

    for(j=0;j<3;j++)
    {

        if(n==board[i][j])
        {
            if(count%2==0)
                board[i][j]='O';
            else
                board[i][j]='X';
            break;
        }
    }
}
system("cls");
//Drawboard();
a=Check_Win();
if(a=='O')
{
    printf("CONGOO !! %s You Won the Game!!",ply2);
  break;

}


}
}

int main()
{
int ch;
char c;
system("color a9");

printf("\n\n------WELCOME!!! TO THE GAME-------\n\n");
label1:

printf("Select Any Option:--\n\t1.Start the Game\n\t2.Help\n\t3.Exit\n");
scanf("%d",&ch);


switch(ch)
{
    case 1: {
        label:
        Drawboard();
        printf("Who will Play for 'X' ? :");
        scanf("%s",&ply1);
        printf("Who will Play for 'O'? : ");
        scanf("%s",&ply2);
        system("cls");
        //Drawboard();
        input();
        printf("\nPlay Again??(Y/N): ");
        scanf("%c",&c);
        if(c=='y')
        {
            New_board();
            system("cls");
            goto label;
        }

        }
    break;
    case 2: {

        printf("Here Some Basic Instruction You need to follow to play this game:-\n");
        printf("1.Try to Match any one of the three rows or three colomn with same symbol either all X or all");
        printf("\n2.Try to Follow the same Pattern in case of all the other two Diagonals \n\n\n\tHope it Help EnJoy!!\n\n\n");
        printf("Press Any Key To Continue--- \n\n");

        //getch();
    _getch();
    system("cls");

        goto label1;
    }

    case 3: exit(0);
}
getch();
exit(0);
return 0;
}
