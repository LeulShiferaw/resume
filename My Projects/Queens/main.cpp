#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

constexpr int row = 14;
constexpr int col = 14;

bool board[row][col];

void initialize()
{
    for (int i = 0; i<row; ++i)
        for (int j = 0; j<col; ++j)
        {
            board[i][j] = true;
        }
}

//Galloping Queens
//Calculate how many ways we can place n number of g.queens
//in an n by n matrix.
bool queens_problem(int curr_col, int &n_ways)
{
    for (int i = 0; i<row; ++i)
    {
        if(board[curr_col][i])
        {

            //Go through the previous columns and check if there is
            //any queen
            bool queen = true;
            for (int c = curr_col-1; c>=0; --c)
            {
                if(board[c][i]==false)
                {
                    queen = false;
                    break;
                }

                int ind = i-1-(curr_col-1-c);
                if(ind>=0)
                {
                    if(board[c][ind]==false)
                    {
                        queen = false;
                        break;
                    }

                }
                ind = i+1+(curr_col-1-c);
                if(ind<row)
                    if(board[c][ind]==false)
                    {
                        queen = false;
                        break;
                    }
            }
            //Knigh movements
            if(curr_col-1>=0)
            {
                if(i-2>=0)
                {
                    if(board[curr_col-1][i-2]==false)
                        continue;
                }
                if(i+2<row)
                    if(board[curr_col-1][i+2]==false)
                        continue;
            }
            if(curr_col-2>=0)
            {
                if(i-1>=0)
                    if(board[curr_col-2][i-1]==false)
                        continue;
                if(i+1<row)
                    if(board[curr_col-2][i+1]==false)
                        continue;
            }
            if(curr_col==col-1&&queen)
            {
                ++n_ways;

                for (int i = 0; i<col; ++i)
                {
                    for (int j = 0; j<row; ++j)
                    {
                        if(board[j][i]==false)
                        {
                            cout << "Q ";
                            continue;
                        }
                        if((i+j)%2==0)
                            cout << "X ";
                        else
                            cout << "  ";
                    }
                    cout << endl;
                }
                cout << endl;

                continue;
            }
            if(queen)
            {
                board[curr_col][i] = false;
                queens_problem(curr_col+1, n_ways);
                board[curr_col][i] = true;
            }
        }
    }
    return true;
}


int desired_queens = 4;
//calculate how many possible ways there are to arrange
//desiered_queens number of galloping queens in a row by col matrix.
bool n_queens_problem(int n_queens, int &n_ways)
{

    if(n_queens==desired_queens)
    {
         ++n_ways;
//        for (int i = 0; i<row; ++i)
//        {
//            for (int j = 0; j<col; ++j)
//            {
//                if(board[i][j]==false)
//                    cout << "Q ";
//                else if((i+j)%2==0)
//                    cout << "X ";
//                else
//                    cout << "  ";
//            }
//            cout << endl;
//        }
//        cin.get();
        return true;
    }

    for (int i = 0; i<row; ++i)
    {
        for (int j = 0; j<col; ++j)
        {
            if(board[i][j])
            {
                bool queen = true;
                //Everything before
                for (int c = j-1; c>=0; --c)
                {
                    if(board[i][c]==false)
                    {
                        queen = false;
                        break;
                    }
                    int ind = i-1-(j-1-c);
                    if(ind>=0)
                        if(board[ind][c]==false)
                        {
                            queen = false;
                            break;
                        }
                    ind = i+1+(j-1-c);
                    if(ind<row)
                        if(board[ind][c]==false)
                        {
                            queen = false;
                            break;
                        }
                }
                //Everthing after
                if(queen)
                {
                    for (int c = j+1; c<col; ++c)
                    {
                        if(board[i][c]==false)
                        {
                            queen = false;
                            break;
                        }
                        int ind = i-1-(c-(j+1));
                        if(ind>=0)
                            if(board[ind][c]==false)
                            {
                                queen = false;
                                break;
                            }
                        ind = i+1+(c-(j+1));
                        if(ind<row)
                            if(board[ind][c]==false)
                            {
                                queen = false;
                                break;
                            }
                    }
                }
                //In that col
                if(queen)
                {
                    for (int r = 0; r<row; ++r)
                    {
                        if(r==i)
                            continue;
                        if(board[r][j]==false)
                        {
                            queen = false;
                            break;
                        }
                    }
                }

                //Knight movements
                if(queen)
                {
                    if(j-1>=0)
                    {
                        if(i-2>=0)
                            if(board[i-2][j-1]==false)
                                continue;
                        if(i+2<row)
                            if(board[i+2][j-1]==false)
                                continue;
                    }
                    if(j-2>=0)
                    {
                        if(i-1>=0)
                            if(board[i-1][j-2]==false)
                                continue;
                        if(i+1<row)
                            if(board[i+1][j-2]==false)
                                continue;
                    }

                    if(j+1<col)
                    {
                        if(i-2>=0)
                            if(board[i-2][j+1]==false)
                            {
                                queen = false;
                                continue;
                            }
                        if(i+2<row)
                            if(board[i+2][j+1]==false)
                            {
                                queen = false;
                                continue;
                            }
                    }
                    if(j+2<col)
                    {
                        if(i-1>=0)
                            if(board[i-1][j+2]==false)
                            {
                                queen = false;
                                continue;
                            }
                        if(i+1<row)
                            if(board[i+1][j+2]==false)
                            {
                                queen = false;
                                continue;
                            }
                    }
                }

                //If I can put a queen in this position
                //Set it to false and goto the next queen.
                if(queen)
                {
                    board[i][j] = false;

                    n_queens_problem(n_queens+1, n_ways);

                    board[i][j] = true;
                }
            }
        }
    }
    return true;
}

int factorial(int n)
{
    int result = 1;
    for (int i = 2; i<=n; ++i)
        result*=i;
    return result;
}

int main()
{
    initialize();
    int result = 0;
    n_queens_problem(0, result);
    //Divide by the factorial of the number of queens to convert
    //the result which contains all possibilities in a permuted manner
    //into a combination.
    cout << (double)result/(double)factorial(desired_queens);
}
