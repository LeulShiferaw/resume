/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Linear Time Max Sub array
 *
 *        Version:  1.0
 *        Created:  23.12.2016 03:04:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Leul Shiferaw (ls), l.shiferaw@jacobs-university.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int main()
{
	int n=16, A[n] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}; 

	int l = -1, r = -1, gl = -1, gr = -1, g_sum = 0, sum = 0;//l-left, r-right, gl-greatest left, ..., sum-current sum
	for(int i = 0; i<n; ++i)
	{
		if(l == -1)//Initial condition
		{
			l = r = gr = gl= i;
			sum = A[i];
			continue;
		}

		sum += A[i];
		if(sum < 0)//If the current sum is less than zero then adding it to MaxSubArray is of no use
		{
			l = r = i+1;
			sum = 0;
			continue;
		}
		else ++r;//Otherwise add the current index to the current sum

		if(sum > g_sum)//This determines the greatest not the current one
		{
			g_sum = sum;
			gl = l;
			gr = r;
		}
	}
	
	printf("L: %d, R: %d, Sum: %d\n", gl+1, gr, g_sum);
	return 0;
}

