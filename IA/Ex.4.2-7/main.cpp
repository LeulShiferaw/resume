/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  User three real number multiplications to get the real number
 *    		    and the imaginary part of a complex number multiplications
 *
 *        Version:  1.0
 *        Created:  25.12.2016 23:44:32
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
	double a, b, c, d;
	
	printf("A, B, C, D: ");
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

	//p-plus
	//m-minus
	double acpad = a*(c+d);
	double bcmbd = b*(c-d);
	double dapdb = d*(a+b);
	
	double real_part = acpad-dapdb;
	double img_part = bcmbd+dapdb;

	printf("Real: %lf\nImg: %lf\n", real_part, img_part);
	return 0;
}

