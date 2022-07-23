//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define UNASSIGNED 0  

//n is used for the size of Sudoku grid.  
//Size will be nxn
#define n 9  
// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValid(int row,int col,int c, int grid[n][n]){
        for(int i=0;i<9;i++){
            if(grid[row][i]==c) return false;
            if(grid[i][col]==c) return false;
            if(grid[3*(row/3) +i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
    
    bool SolveSudoku(int grid[n][n])  
    { 
        // Your code here
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    for(int c=1;c<10;c++){
                        if(isValid(i,j,c,grid)){
                                grid[i][j]=c;
                                if(SolveSudoku(grid)) return true;
                                else grid[i][j]=0;
                            }  
                        }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid(int grid[n][n]) 
    {
        // Your code here 
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << grid[i][j]<<" ";
            }
        }
        
    }
};

//{ Driver Code Starts.

int main(){
	int grid[n][n];	
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		    cin>>grid[i][j];
		        
	Solution object;		
	if(object.SolveSudoku(grid))  
        object.printGrid(grid);  
    else
        cout<<"No solution exists";  
        cout<<endl;
	return 0;
}