#include <math.h>
#include <vector>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;


//Find the determinant of any square matrix
cpp_int determinant(vector<vector<cpp_int>> matrix)
{
    if(matrix.size()==1)
        return matrix[0][0];
    else if(matrix.size()==0)
        return 0;

    //Go through every column
    //This is is the one it is going to skip
    cpp_int result = 0;
    for (int i = 0; i<matrix[0].size(); ++i)
    {
        //Create the new matrix
        //Start from 1 until the end
        vector<vector<cpp_int>> new_matrix;
        for (int j = 1; j<matrix.size(); ++j)
        {
            vector<cpp_int> new_row;
            for (int k = 0; k<matrix[j].size(); ++k)
            {
                if(i==k)
                    continue;
                new_row.push_back(matrix[j][k]);
            }
            new_matrix.push_back(new_row);
        }
        //Compute a11*m11*(-1^(r+c))
        cpp_int temp = (matrix[0][i]*determinant(new_matrix));
        if(i%2!=0)
            temp*=-1;
        result+=temp;
    }
    return result;
}

cpp_int f(cpp_int n)
{
    cpp_int temp = n;
    cpp_int c = -1;
    cpp_int result = 1;
    for(int i = 1; i<=10; ++i)
    {
        result+=(c*n);
        c*=-1;
        n*=temp;
    }
    return result;
    //return n*n*n*n;
}

cpp_int power(int a, int b)
{
    cpp_int result = 1;
    for(int i = 1; i<=b; ++i)
        result*=a;
    return result;
}

int main()
{
    cpp_int ans = 0;
    //The column that I replace when calculating different determinants.
    vector<cpp_int> replacing_col;
    int MAX_D = 10;
    for(int i = 0; i<=MAX_D; ++i)
    {
        replacing_col.push_back(f(i+1));
    }

    for(int d = 0; d<MAX_D; ++d)
    {
        vector<vector<cpp_int>> original_matrix;

        //It is the x^2, x, 1 part of ax^2+bx+c b/c
        //I am given the value of f(x) at certain xs and I'm suppose
        //to look for the value of a, b, and c by using systems of linear equations.
        for(int i = 0; i<=d; ++i)
        {
            vector<cpp_int> temp;
            for(int j = d; j>=0; --j)
                temp.push_back(power(i+1, j));
            original_matrix.push_back(temp);
        }

        cpp_int D_original = determinant(original_matrix); //Determinant

        vector<cpp_int> coefficients;
        vector<vector<cpp_int>> M_vars = original_matrix;

        //Find values of a, b, c... by computing Da/D, Db/D...
        //Just substitute the replacing col to D at each column to find matrix a, matrix b...
        //Find their determinant and compute.
        for(int i = 0; i<=d; ++i)
        {
            for(int j = 0; j<=d; ++j)
                M_vars[j][i] = replacing_col[j];
            coefficients.push_back(determinant(M_vars)/D_original);
            //cout << determinant(M_vars)/D_original << endl;
            M_vars = original_matrix;
        }

        cpp_int temp = 0;
        //Finally compute the next value
        //By the way the x for the next value is d+2
        //Since the degree starts from 0
        for(int i = 0; i<coefficients.size(); ++i)
        {
            temp += coefficients[i]*power(d+2, coefficients.size()-i-1);
            ans+=coefficients[i]*power(d+2, coefficients.size()-i-1);
        }
        cout << temp << endl;
    }
    cout << ans << endl;
}
