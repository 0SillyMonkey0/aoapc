#include<iostream>  
using namespace std;  
int tile = 1;                   
int board[100][100];  

void chessBoard(int rb, int cb, int rt, int ct, int size)
{
	if(size == 1)
		return;
	int t = tile++;
	size /= 2;
	if( rt < rb + size && rt >= rb && ct < cb + size && ct >= cb)  // 1
		chessBoard(rb, cb, rt, ct, size);
	else
	{
		board[rb + size - 1][cb + size - 1] = t;
		chessBoard(rb, cb, rb + size - 1, cb + size - 1, size);
	}
	
	if( rt < rb + size && ct < cb + 2*size && rt >= rb && ct >= cb + size)   // 2
		chessBoard(rb, cb + size, rt, ct, size);
	else
	{
		board[rb + size - 1][cb + size] = t;
		chessBoard(rb, cb + size, rb + size - 1, cb + size, size);
	}
	if( rb + size <= rt && rt < rb + 2*size && ct < cb + size && ct >= cb)  // 3
		chessBoard(rb + size, cb, rt, ct, size);
	else
	{
		board[rb + size][cb + size - 1] = t;
		chessBoard(rb + size, cb, rb + size, cb + size - 1, size);
	}
	if(rb + size <= rt && rt < rb + 2*size && cb + size <= ct && ct < cb + 2*size)  //4
		chessBoard(rb + size, cb + size, rt, ct, size);
	else
	{
		board[rb + size][cb + size] = t;
		chessBoard(rb + size, cb + size, rb + size, cb + size, size);
	}
}
  
int main()  
{  
    int size;  
    cout<<"The size of chess board: ";  
    cin >> size;  
    int index_x, index_y;  
    cout<<"Position of the black point: ";  
    cin >> index_x >> index_y;  
    chessBoard ( 0, 0, index_x, index_y, size );  
    for ( int i = 0; i < size; i++ )  
    {  
        for ( int j = 0; j < size; j++ )  
            cout << board[i][j] << "\t";  
        cout << endl;  
    }  
}

