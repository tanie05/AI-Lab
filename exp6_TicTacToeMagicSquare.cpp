//tic tac toe using magic square
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int board[10] = {2,2,2,2,2,2,2,2,2,2};
vector<int> ARRo;
vector<int> ARRx;
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
    cout
    <<arr[8]<<"  "<<arr[3]<<"  "<<arr[4]<<endl
    <<arr[1]<<"  "<<arr[5]<<"  "<<arr[9]<<endl
    <<arr[6]<<"  "<<arr[7]<<"  "<<arr[2]<<endl;
    cout<<endl;
}
int make2()
{
    if(board[5]==2)
    return 5;

    // else return any blank non-cornered square (1, 3, 9, 7)
    if(board[1]==2)
    return 1;
    if(board[3]==2)
    return 3;
    if(board[7]==2)
    return 7;
    if(board[9]==2)
    return 9;

}
void go(int n, int turn)
{
    if(turn%2==0){
        board[n]=5;
        ARRo.push_back(n);
    }
    else{
        board[n]=3;
        ARRx.push_back(n);
    }
    
}
int possWin(char p, vector<int> vec)
{
    //every pair in this vector
    
    int n = vec.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int a = vec[i];
            int b = vec[j];
            if(board[15-a-b]==2)
            return 15-a-b;
        }
    }
    return 0;
  
}
void computerMove(int turn)
{
    switch (turn)
    {
    case 1:
        go(8,turn);
        break;

    case 2:
        if(board[5]==2)
        go(5,turn);
        else
        go(4,turn);

        break;

    case 3:
        if(board[2]==2)
        go(2,turn);
        else
        go(4,turn);

        break;

    case 4:
        if(possWin('x', ARRx))
        go(possWin('x', ARRx),turn); //block oppenent's win
        else
        go(make2(),turn);

        break;
    
    case 5:
        if(possWin('x', ARRx))
        go(possWin('x', ARRx),turn); //winning move
        else if(possWin('o', ARRo))
        go(possWin('o', ARRo),turn); //block win
        else if(board[7]==2)
        go(7,turn);
        else
        go(4,turn);

        break;
    
    case 6:
        if(possWin('o', ARRo))
        go(possWin('o', ARRo),turn);//winning move
        else if(possWin('x', ARRx))
        go(possWin('x', ARRx),turn); //block win
        else
        go(make2(),turn);

        break;

    case 7:
        if(possWin('x', ARRx))
        go(possWin('x', ARRx),turn);//winning move
        else if(possWin('o', ARRo))
        go(possWin('o', ARRo),turn); //block win
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
        if(possWin('o', ARRo))
        go(possWin('o', ARRo), turn);//winning move
        else if(possWin('x', ARRx))
        go(possWin('x', ARRx),turn);//block win
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
        if(possWin('x', ARRx))
        go(possWin('x', ARRx),turn);//winning move
        else if(possWin('o', ARRo))
        go(possWin('o', ARRo),turn); //block win
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
    unordered_map<int,int> map;
    map[1]=8;
    map[2]=3;
    map[3]=4;
    map[4]=1;
    map[5]=5;
    map[6]=9;
    map[7]=6;
    map[8]=7;
    map[9]=2;


    if(board[map[m]] != 2)
    {
        //non-blanked square choosen
        cout<<"Invalid move!!"<<endl;
        userMove(turn);
    }
    else
    {
        go(map[m],turn);
    }
}
int check(char ch, vector<int> vec)
{
    //every pair in this vector
    int num;
    if(ch=='o')
    num=125;
    else
    num=27;

    int n = vec.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int a=vec[i];
                int b=vec[j];
                int c=vec[k];
                if(a+b+c==15)
                return num;
            }
        }
    }
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
        while(turn<=9 && check('x', ARRx)!=27 && !check('o', ARRo)!=125)
        {
            userMove(turn);
            cout<<"Turn-"<<turn<<" (user)"<<endl;
            display();
            turn++;

            if(check('x', ARRx)==27)
            break;

            if(turn==10)
            break;

            computerMove(turn);
            cout<<"Turn-"<<turn<<" (Computer)"<<endl;
            display();
            turn++;
            if(check('o', ARRo)==27)
            break;
        }
        
        if(check('o', ARRo)==125)
        cout<<"-----Computer wins-----"<<endl;
        else if(check('x', ARRx)==27)
        cout<<"-----User wins-----"<<endl;
        else
        cout<<"-----DRAW-----"<<endl;
        
    }

    else
    {
        //computer plays first  | computer-x | user-o
        while(turn<=9 && !check('x', ARRx) && !check('o', ARRo))
        {
        computerMove(turn);
        cout<<"Turn-"<<turn<<" (Computer)"<<endl;
        display();
        turn++;

        if(check('x', ARRx)==27)
        break;

        if(turn==10)
        break;
        userMove(turn);
        cout<<"Turn-"<<turn<<" (user)"<<endl;
        display();
        turn++;
        if(check('o', ARRo)==27)
        break;

        }
        
        if(check('o', ARRo)==125)
        cout<<"-----User wins-----"<<endl;
        else if(check('x', ARRx)==27)
        cout<<"-----Computer wins-----"<<endl;
        else
        cout<<"-----DRAW-----"<<endl;

    }
    
}