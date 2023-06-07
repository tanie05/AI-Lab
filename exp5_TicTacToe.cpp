#include<iostream>
#include<vector>
using namespace std;
int board[10] = {0,2,2,2,2,2,2,2,2,2};
bool gameOver = false;
void display()
{
    char arr[10];
    for(int i=1;i<=9;i++)
    {
        if(board[i]==2)
        arr[i]='_';
        else if(board[i]==5)
        arr[i]='o';
        else
        arr[i]='x';   
    }
    for(int i=1;i<=9;i++)
    {
        cout<<arr[i]<<" ";
        
        if(i%3==0)
        cout<<endl;
    }
    cout<<endl;
}
int make2()
{
    if(board[5]==2)
    return 5;

    // else return any blank non-cornered square (2, 4, 6, 8)
    for(int i=2;i<=8;i=i+2)
    {
        if(board[i]==2)
        return i;
    }

}
void go(int n, int turn)
{
    if(turn%2==0)
    board[n]=5;
    else
    board[n]=3;

}
int emptyIndex(int a, int b, int c)
{
    if(board[a]==2)
    return a;
    if(board[b]==2)
    return b;
    return c;
}
int possWin(char p)
{
    int winProduct;
    if(p=='o')
    winProduct = 50;
    else 
    winProduct = 18;

    int i=1,j=2,k=3;
    //for three rows
    while(i<=7)
    {
        if(board[i]*board[j]*board[k] == winProduct)
        return emptyIndex(i,j,k);

        i+=3;
        j+=3;
        k+=3;
    }
    i=1;j=4;k=7;
    //for three columns
    while(i<=3)
    {
        if(board[i]*board[j]*board[k] == winProduct)
        return emptyIndex(i,j,k);

        i+=1;
        j+=1;
        k+=1;
    }

    //for two diagonals
    if(board[1]*board[5]*board[9]==winProduct)
    return emptyIndex(1,5,9);

    if(board[3]*board[5]*board[7]==winProduct)
    return emptyIndex(3,5,7);

    //winning not possible on this move
    return 0;
}
void computerMove(int turn)
{
    switch (turn)
    {
    case 1:
        go(1,turn);
        break;

    case 2:
        if(board[5]==2)
        go(5,turn);
        else
        go(3,turn);

        break;

    case 3:
        if(board[9]==2)
        go(9,turn);
        else
        go(3,turn);

        break;

    case 4:
        if(possWin('x'))
        go(possWin('x'),turn); //block oppenent's win
        else
        go(make2(),turn);

        break;
    
    case 5:
        if(possWin('x'))
        go(possWin('x'),turn); //winning move
        else if(possWin('o'))
        go(possWin('o'),turn); //block win
        else if(board[7]==2)
        go(7,turn);
        else
        go(3,turn);

        break;
    
    case 6:
        if(possWin('o'))
        go(possWin('o'),turn);//winning move
        else if(possWin('x'))
        go(possWin('x'),turn); //block win
        else
        go(make2(),turn);

        break;

    case 7:
        if(possWin('x'))
        go(possWin('x'),turn);//winning move
        else if(possWin('o'))
        go(possWin('o'),turn); //block win
        else
        {
            //go anywhere blank
            for(int i=1;i<=9;i++)
            {
                if(board[i]==2)
                {
                    go(i,turn);
                    break;
                }
            }
        }

        break;
    
    case 8:
        if(possWin('o'))
        go(possWin('o'), turn);//winning move
        else if(possWin('x'))
        go(possWin('x'),turn);//block win
        else
        {
            //go anywhere blank
            for(int i=1;i<=9;i++)
            {
                if(board[i]==2)
                {go(i,turn);
                break;}
            }
        }
        break;

    case 9:
        if(possWin('x'))
        go(possWin('x'),turn);//winning move
        else if(possWin('o'))
        go(possWin('o'),turn); //block win
        else
        {
            //go anywhere blank
            for(int i=1;i<=9;i++)
            {
                if(board[i]==2)
                {go(i,turn);
                break;}
            }
        }
        break;
    

    default:
        break;
    }
}
void userMove(int turn)
{
    int m;
    cout<<"Choose a square - ";
    cin>>m;

    if(board[m] != 2)
    {
        //non-blanked square choosen
        cout<<"Invalid move!!"<<endl;
        userMove(turn);
    }
    else
    {
        go(m,turn);
    }
}
int check(char ch)
{
    int winProduct;
    if(ch=='o')
    winProduct = 125;
    else 
    winProduct = 27;

    int i=1,j=2,k=3;
    //for three rows
    while(i<=7)
    {
        if(board[i]*board[j]*board[k] == winProduct)
        return winProduct;

        i+=3;
        j+=3;
        k+=3;
    }
    i=1;j=4;k=7;
    //for three columns
    while(i<=3)
    {
        if(board[i]*board[j]*board[k] == winProduct)
        return winProduct;

        i+=1;
        j+=1;
        k+=1;
    }
    //for two diagonals
    if(board[1]*board[5]*board[9]==winProduct)
    return winProduct;
    if(board[3]*board[5]*board[7]==winProduct)
    return winProduct;

    return 0;
}
int main()
{
    /*
        even moves   x   3
        odd moves    o   5
    */
    int turn=1;
    char ch;
    cout<<"Do you want to play first?"<<"y/n"<<endl;
    cin>>ch;
    display();

    if(ch=='y')
    {
        //user plays first | user-x | computer-o
        while(turn<=9 && check('x')!=27 && !check('o')!=125)
        {
            userMove(turn);
            cout<<"Turn-"<<turn<<" (user)"<<endl;
            display();
            turn++;

            if(check('x')==27)
            break;

            if(turn==10)
            break;

            computerMove(turn);
            cout<<"Turn-"<<turn<<" (Computer)"<<endl;
            display();
            turn++;
        }
        
        if(check('o')==125)
        cout<<"-----Computer wins-----"<<endl;
        else if(check('x')==27)
        cout<<"-----User wins-----"<<endl;
        else
        cout<<"-----DRAW-----"<<endl;
        
    }

    else
    {
        //computer plays first  | computer-x | user-o
        while(turn<=9 && !check('x') && !check('o'))
        {
        computerMove(turn);
        cout<<"Turn-"<<turn<<" (Computer)"<<endl;
        display();
        turn++;

        if(check('x')==27)
        break;

        if(turn==10)
        break;
        userMove(turn);
        cout<<"Turn-"<<turn<<" (user)"<<endl;
        display();
        turn++;

        }
        
        if(check('o')==125)
        cout<<"-----User wins-----"<<endl;
        else if(check('x')==27)
        cout<<"-----Computer wins-----"<<endl;
        else
        cout<<"-----DRAW-----"<<endl;

    }
    
}