#include<iostream>
using namespace std;
int count=0;
int m, n, k;
void display(int** board)
{
    count++;
    cout<<"count - "<<count<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==0)
            cout<<"_ ";
            else if(board[i][j] == 1)
            cout<<"K ";
            else 
            cout<<"A ";
        }
        cout<<endl;
    }
    cout<<"-----------------------------"<<endl;
}
void attack(int** board, int i, int j)
{
    if ((i + 2) < m && (j - 1) >= 0) {
        board[i + 2][j - 1] = 2;
    }
    if ((i - 2) >= 0 && (j - 1) >= 0) {
        board[i - 2][j - 1] = 2;
    }
    if ((i + 2) < m && (j + 1) < n) {
        board[i + 2][j + 1] = 2;
    }
    if ((i - 2) >= 0 && (j + 1) < n) {
        board[i - 2][j + 1] = 2;
    }
    if ((i + 1) < m && (j + 2) < n) {
        board[i + 1][j + 2] = 2;
    }
    if ((i - 1) >= 0 && (j + 2) < n) {
        board[i - 1][j + 2] = 2;
    }
    if ((i + 1) < m && (j - 2) >= 0) {
        board[i + 1][j - 2] = 2;
    }
    if ((i - 1) >= 0 && (j - 2) >= 0) {
        board[i - 1][j - 2] = 2;
    }
}
bool canPlace(int** board, int i, int j)
{
    if(board[i][j] == 0)
    return true;
    else
    return false;
}
void place(int i, int j, int** board, int** new_board)
{
    //copy the confriguration
    for (int y = 0; y < m; y++) {
        for (int z = 0; z < n; z++) {
            new_board[y][z] = board[y][z];
        }
    }

    //place the knight
    new_board[i][j] = 1;

    //mark the attacking positions
    attack(new_board, i, j);

}
void KKnight(int k, int sti, int stj, int** board)
{
    if(k==0)
    display(board);

    else
    {
        for(int i=sti;i<m;i++)
        {
            for(int j=stj;j<n;j++)
            {
                if(canPlace(board, i, j))
                {
                    
                    int** new_board = new int*[m];
                    
                    for (int x = 0; x < m; x++) 
                    new_board[x] = new int[n];
                    
                    place(i, j, board, new_board);
                    KKnight(k - 1, i, j, new_board);

                    for (int x = 0; x < m; x++)
                    delete[] new_board[x];
                    
                    delete[] new_board;
                }
                
            }
            stj = 0;
        }
       
    }
}
int main()
{
    cout<<"enter m, n, and k"<<endl;
    cin>>m>>n>>k;

    int** board = new int*[m];
    for (int i = 0; i < m; i++) {
        board[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    KKnight(k, 0, 0, board);

}