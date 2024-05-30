#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int column = board[0].size();

        int neighbor[3] = {0,1,-1};

        int dead = 0;

        vector<vector<int>> copyBoard(row, vector<int>(column, 0));



        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                copyBoard[i][j] = board[i][j];
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                int live = 0;

                for (int a = 0; a < 3; a++)
                {
                    for (int b = 0; b < 3; b++)
                    {
                        if (!(neighbor[a] == 0 && neighbor[b] == 0))
                        {
                            int r = (i + neighbor[a]);
                            int c = (j + neighbor[b]);


                            if ((r < row && r >= 0) && (c < column && c >= 0) && (copyBoard[r][c] == 1))
                            {
                                live++;
                            }


                        }
                    }
                }


                if ((copyBoard[i][j] == 1) && (live < 2 || live > 3))
                {
                    board[i][j] = 0;
                }

                if ((copyBoard[i][j] == 0) && (live == 3))
                {
                    board[i][j] = 1;
                }
            }
        }

       
    }
};