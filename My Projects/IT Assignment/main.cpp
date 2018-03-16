#include <iostream>
#include <math.h>

using namespace std;

void number_1()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    if(n%2==0)
        cout << "Even";
    else
        cout << "Odd";
    cout << endl;
}

void number_2()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    if(a>b)
        cout << a << " is larger.";
    else if(b>a)
        cout << b << " is larger.";
    else
        cout << "Equal";
    cout << endl;
}

void number_3()
{
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    if(a<b)
    {
        if(a<c)
        {
            if(b<c)
                cout << a << " " << b << " " << c;
            else
                cout << a << " " << c << " " << b;
        }
        else
            cout << c << " " << a << " " << b;
    }
    else if(b<c)
    {
        if(a<c)
            cout << b << " " << a << " " << c;
        else
            cout << b << " " << c << " " << a;
    }
    else
        cout << c << " " << b << " " << a;
    cout << endl;
}

void number_4()
{
    int sum = 0;
    for (int i = 1; i<=100; ++i)
        sum+=i;
    //Arthimetic Formula
    //sum = (100*(1+100))/2;
    cout << sum << endl;
}

void number_5()
{
    int n, sum = 0;
    cout << "Enter number: ";
    cin >> n;
    for (int i = 2; i<n; i+=2)
        sum+=i;
//    Arthimetic Formula
//    if(n%2==0)
//        sum = (((n/2)-1)*(2+(n-2)))/2;
//    else
//        sum = ((n/2)*(2+(n-1)))/2;
//    cout << sum << endl;
//    //Or
//    sum = (((n/2)-(1-(n%2)))*(2+(n-(2-(n%2)))))/2;
    cout << sum << endl;
}

void number_6()
{
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Average: " << (a+b)/2.0 << endl;
}

void number_7()
{
    double a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    cout << "Average: " << (a+b+c)/3.0 << endl;
    cout << "Maximum: " << max(max(a, b), c) << endl;//max() is a c++ function, it takes two arguments and returns the largest one.
    cout << "Minimum: " << min(min(a, b), c) << endl;//so is min().
    cout << "Sum: " << a+b+c << endl;
//    Or
//    cout << "Maximum: ";
//    if(a>b)
//    {
//        if(a>c)
//            cout << a;
//        else
//            cout << c;
//    }
//    else if(b>c)
//        cout << b;
//    else
//        cout << c;
//    cout << "Minimum: ";
//    if(a<b)
//    {
//        if(a<c)
//            cout << a;
//        else
//            cout << c;
//    }
//    else if(b<c)
//        cout << b;
//    else
//        cout << c;
}

void number_8()
{
    double r, pi = 3.141592653;
    cout << "Enter radius: ";
    cin >> r;
    cout << "Area: " << pi*(r*r) << endl;
}

void number_9()
{
    int a, b, temp;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Unswapped: " << a << " " << b << endl;

    //Swapping
    temp = a;
    a = b;
    b = temp;

    cout << "Swapped: " << a << " " << b << endl;
}

void number_10()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Unswapped: " << a << " " << b << endl;

    a+=b;   //Value of a becomes a+b
    b = a-b;//Value of b becomes a, which is a+b, minus b => (a+b)-b = a. So current value of b becomes a.
    a = a-b;//Value of a becomes a, which is a+b, minus b, which is a. So current value of a become (a+b)-a = b.

    cout << "Swapped: " << a << " " << b << endl;
}

void number_11()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    if(n%2==0)
        cout << "This number is Even";
    else
        cout << "This number is Odd";
    cout << endl;
}

void number_12()
{
    int amn_gr_50 = 0;
    for(int i = 1; i<=10; ++i)
    {
        int n;
        cout << "Enter number " << i << ": ";
        cin >> n;
        while(n<0||n>100)
        {
            cout << "Try Again: ";
            cin >> n;
        }
        if(n>50)
            ++amn_gr_50;
    }
    cout << "There are " << amn_gr_50 << " numbers greater than 50." << endl;
}

void number_13()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    int ans = 1;
    for(int i = 2; i<=n; ++i)
        ans*=i;
    cout << "Factorial: " << ans;
}

void number_14()
{
    //A
    //For
    int sum = 0;
    for(int i = 1; i<=100; ++i)
        sum+=i;
    cout << "Sum: " << sum << endl;
    //Do-while
    sum = 0;
    int i = 1;
    do
    {
        sum+=i;
        ++i;
    }while(i<=100);
    cout << "Sum: " << sum << endl;

    //While
    i = 1;
    sum = 0;
    while(i<=100)
    {
        sum+=i;
        ++i;
    }
    cout << "Sum: " << sum << endl;

    //B
    //For
    sum = 0;
    for(i = 1; i<=10; ++i)
        sum+=5*i;
    cout << "Sum: " << sum << endl;

    //Do-while
    i = 1;
    sum = 0;
    do
    {
        sum+=5*i;
        ++i;
    }while(i<=10);
    cout << "Sum: " << sum << endl;

    //While
    i = 1;
    sum = 0;
    while(i<=10)
    {
        sum+=5*i;
        ++i;
    }
    cout << "Sum: " << sum << endl;

    //C
    //For
    double sum_0 = 0.0;
    for(double j = 1; j<=15; ++j)
        sum_0+=1.0/j;
    cout << "Sum: " << sum_0 << endl;

    //Do-While
    sum_0 = 0.0;
    double j = 1;
    do
    {
        sum_0+=1.0/j;
        ++j;
    }while(j<=15);
    cout << "Sum: " << sum_0 << endl;

    //While
    j = 1;
    sum_0 = 0.0;
    while(j<=15)
    {
        sum_0+=1.0/j;
        ++j;
    }
    cout << "Sum: " << sum_0 << endl;

    //D
    //For
    long long fac = 1;
    for(int k = 2; k<=20; ++k)
        fac*=k;
    cout << "Factorial: " << fac << endl;

    //Do-While
    fac = 1;
    int k = 2;
    do
    {
        fac*=k;
        ++k;
    }while(k<=20);
    cout << "Factorial: " << fac << endl;

    //While
    k = 2;
    fac = 1;
    while(k<=20)
    {
        fac*=k;
        ++k;
    }
    cout << "Factorial: " << fac << endl;
}

void number_15()
{
    for(int i = 10; i<=49; ++i)
    {
        cout << i << " ";
        if(i%10==9)
            cout << endl;
    }
}

bool is_prime(int n)  //For question number 16.
{
    if(n==2)
        return true;
    if(n%2==0||n==1)
        return false;
    for(int i = 3; i<=sqrt(n); ++i)
        if(n%i==0)
            return false;
    return true;
}

void number_16()
{
    cout << "Primes: " << endl;
    for(int i = 1; i<=100; ++i)
        if(is_prime(i))
            cout << i << endl;
}

void number_17()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    int n_digits = (int)(log10(n))+1;
    cout << "It has " << n_digits << " number of digit";
    if(n_digits!=1)
        cout << "s";
    cout << "." << endl;

    //Or
    n_digits = 0;
    while(true)
    {
        ++n_digits;
        if(n/10==0)
            break;
        n/=10;
    }
    cout << "It has " << n_digits << " number of digit";
    if(n_digits!=1)
        cout << "s";
    cout << "." << endl;
}

void number_18()
{
    double mid_grade = -1, final_grade = -1;
    while(true)
    {
        while(mid_grade<0||mid_grade>40)
        {
            cout << "Enter mid result: ";
            cin >> mid_grade;
        }
        while(final_grade<0||final_grade>60)
        {
            cout << "Enter final result: ";
            cin >> final_grade;
        }

        double total = mid_grade+final_grade;

        if(total>=90)
            cout << "A" << endl;
        else if(total>=80)
            cout << "B" << endl;
        else if(total>=70)
            cout << "C" << endl;
        else if(total>=60)
            cout << "D" << endl;
        else
            cout << "F" << endl;
        cout << endl;
        mid_grade = -1;
        final_grade = -1;
    }
}

void number_19()
{
    int n = -1;
    while(n<0)
    {
        cout << "Enter number: ";
        cin >> n;
    }

    long long ans = 1;
    for(int i = 1; i<=n; ++i)
        ans*=i;
    cout << "Factorial: " << ans << endl;
}

void number_20()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    long long fac = 1, sum = 0;
    for(int i = 1; i<=n; ++i)
    {
        fac*=i;
        sum+=fac;
    }
    cout << "Result: " << sum << endl;
}

void number_21()
{
    for(int i = 1; i<=5; ++i)
    {
        for(int j = 1; j<=i; ++j)
            cout << (char)(64+j);
        cout << endl;
    }
}

void number_22()
{
    int curr_alpha = 1;

    for(int i = 1; i<=5; ++i)
    {
        for(int j = 1; j<=i; ++j)
        {
            cout << (char)(64+curr_alpha);
            ++curr_alpha;
        }
        cout << endl;
    }
}

void number_23()
{
    //A
    for(int i = 1; i<=5; ++i)
    {
        for(int j = 1; j<=i; ++j)
            cout << "*";
        cout << endl;
    }
    cout << endl;

    //B
    for(int i = 5; i>=1; --i)
    {
        for(int j = 1; j<=i; ++j)
            cout << "*";
        cout << endl;
    }
    cout << endl;

    //C
    for(int i = 4; i>=0; --i)
    {
        for(int j = 1; j<=i; ++j)
            cout << " ";
        int layer = 5-i; //The current row. Since 5 is the largest it can be we subtract i from 5.
        for(int j = 1; j<=(2*layer)-1; ++j)
            cout << "*";
        cout << endl;
    }
    cout << endl;

    //D
    for(int i = 2; i>=-2; --i)  //I went from 2 to -2 to repeat 2 and 1.
    {
        int x = i;
        if(i<0)
            x*=-1;
        for(int j = 1; j<=x; ++j)
            cout << " ";
        int layer = 3-x;
        for(int j = 1; j<=(2*layer)-1; ++j)
            cout << "*";
        cout << endl;
    }
}

void number_24()
{
    int i = 1;
    double sum = 0.0;
    while(i!=11)
    {
        double x;
        cin >> x;
        sum+=x;
        ++i;
    }
    cout << "Average: " << sum/10.0 << endl;
}

void number_25()
{
    double result = 0.0;
    for(double i = 1; i<=30; ++i)
        result+=((i/3.0)*2.0);
    cout << "Result: " << result << endl;
}

void number_26()
{
    double mark = -1;
    double total_mark = 0.0;
    for(int i = 1; i<=5; ++i)
    {
        while(mark<0||mark>100)
        {
            cout << "Enter mark for student " << i << ": ";
            cin >> mark;
            total_mark+=mark;
        }
        mark = -1;
    }
    cout << "Average: " << mark/5.0 << endl;
}

void number_27()
{
    double a, b;
    char operation;
    cout << "Enter a number, an operation and another number: ";
    cin >> a >> operation >> b;

    switch(operation)
    {
    case '+':
        cout << a << " " << operation << " " << b << " equals to " << a+b << endl;
        break;
    case '-':
        cout << a << " " << operation << " " << b << " equals to " << a-b << endl;
        break;
    case '*':
        cout << a << " " << operation << " " << b << " equals to " << a*b << endl;
        break;
    case '/':
        if(b==0)
            cout << a << " " << operation << " " << b << " can't be computed: denominator is 0." << endl;
        else
            cout << a << " " << operation << " " << b << " equals to " << a/b << endl;
        break;
    default:
        cout << operation << " is an unrecognized operator." << endl;
    }
}

void number_28()
{
    char c;
    cout << "Enter a character: ";
    cin >> c;

    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        cout << "Vowel." << endl;
    else
        cout << "Consonant." << endl;
}

void number_29()
{
    for(int i = 2; i<20; i+=2)
        cout << i << endl;
    cout << endl;
}

void number_30()
{
    int d, m, y;
    cout << "Please enter a date(dd mm yy): ";
    cin >> d >> m >> y;

    if(d<0||d>31)
    {
        cout << "Invalid day of the month: " << d << endl;
        return;
    }
    else if(m<0||m>12)
    {
        cout << "Invalid month: " << m << endl;
        return;
    }
    else if(y<0)
    {
        cout << "Invalid year: " << y << endl;
        return;
    }



    if(m==2)
    {
	bool leap_year = false;
        if(y%100!=0)//Not century year
        {
            if(y%4==0)//Leap year
                leap_year = true;
        }
        else if(y%400==0)//Since it is a century year
        {
            leap_year = true;
        }

	if(leap_year)
	{
	    if(d>29)
	    {
		cout << "Invalid day of month: " << d << endl;
		return;
	    }
        }
	else if(d>28)
        {
                cout << "Invalid day of month: " << d << endl;
            return;
        }
    }
    else if(m<=7)
    {
        if(m%2==0)
        {
            if(d>30)
            {
                cout << "Invalid day of month: " << d << endl;
                return;
            }
        }
        else if(d>31)
        {
            cout << "Invalid day of month: " << d << endl;
            return;
        }
    }
    else if(m%2==0)
    {
        if(d>31)
        {
            cout << "Invalid day of month: " << d << endl;
            return;
        }
    }
    else if(d>30)
    {
        cout << "Invalid day of month: " << d << endl;
        return;
    }

    cout << d << "/" << m << "/" << y << " is a valid date." << endl;
}

int main()
{
    cout << "IT Assignment" << endl;
    cout << "Done by Leul Abiy" << endl << endl;
    cout << "Just enter the question number you would like to run and it will run." << endl;
    cout << "The number must be from 1-30. The second part that starts from 1 to 17 must be as so it continued from 12." << endl;
    cout << "Eg. Question 5 from the second part would be question 17." << endl;
    cout << "If it prints the same result repeatedly, it means I used multiple methods to solve it. You can look at the function." << endl;
    cout << "Every question is a function and is named accordingly." << endl << endl;

    while(true)
    {
        int c;
        cout << "Enter which question you would like to run: " << endl;
        cin >> c;

        switch(c)
        {
        case 1:
            number_1();
            break;
        case 2:
            number_2();
            break;
        case 3:
            number_3();
            break;
        case 4:
            number_4();
            break;
        case 5:
            number_5();
            break;
        case 6:
            number_6();
            break;
        case 7:
            number_7();
            break;
        case 8:
            number_8();
            break;
        case 9:
            number_9();
            break;
        case 10:
            number_10();
            break;
        case 11:
            number_11();
            break;
        case 12:
            number_12();
            break;
        case 13:
            number_13();
            break;
        case 14:
            number_14();
            break;
        case 15:
            number_15();
            break;
        case 16:
            number_16();
            break;
        case 17:
            number_17();
            break;
        case 18:
            number_18();
            break;
        case 19:
            number_19();
            break;
        case 20:
            number_20();
            break;
        case 21:
            number_21();
            break;
        case 22:
            number_22();
            break;
        case 23:
            number_23();
            break;
        case 24:
            number_24();
            break;
        case 25:
            number_25();
            break;
        case 26:
            number_26();
            break;
        case 27:
            number_27();
            break;
        case 28:
            number_28();
            break;
        case 29:
            number_29();
            break;
        case 30:
            number_30();
            break;
        default:
            cout << "Invalid question!" << endl;
        }
    }
}
