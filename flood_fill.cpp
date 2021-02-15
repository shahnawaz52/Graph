#include<bits/stdc++.h>
using namespace std;

#define row 8
#define col 8

void floodFillUtil(int screen[][col], int x,int y,int prevC, int newC) {
	if(row<0 || col<0 || x>=row || y>=col) 
		return;
	if(screen[x][y]!=prevC)
		return;
	if(screen[x][y]==newC)
		return;

	screen[x][y] = newC;

	floodFillUtil(screen,x+1,y,prevC,newC);
	floodFillUtil(screen,x-1,y,prevC,newC);
	floodFillUtil(screen,x,y+1,prevC,newC);
	floodFillUtil(screen,x,y-1,prevC,newC);
}


void floodFill(int screen[][col],int x,int y, int newC) {
	int prevC = screen[x][y];
	floodFillUtil(screen,x,y,prevC,newC); 
}

int main() {

	int screen[row][col] = {{1, 1, 1, 1, 1, 1, 1, 1},
		                      {1, 1, 1, 1, 1, 1, 0, 0},
		                      {1, 0, 0, 1, 1, 0, 1, 1},
		                      {1, 2, 2, 2, 2, 0, 1, 0},
		                      {1, 1, 1, 2, 2, 0, 1, 0},
		                      {1, 1, 1, 2, 2, 2, 2, 0},
		                      {1, 1, 1, 1, 1, 2, 1, 1},
		                      {1, 1, 1, 1, 1, 2, 2, 1},
		                     };

	int x = 4,y=4, newC = 3;

	floodFill(screen, x, y, newC);
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			cout<<screen[i][j]<<" ";
		}
		cout<<endl;
	}

}
