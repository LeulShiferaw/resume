#!/usr/share/python
def gcd(a, b):
    if a==0:
        return b
    elif a==1 or b==1:
        return 1
    else:
        return gcd(b%a, a)

a=long(input("a: "))
b=long(input("b: "))

print "GCD:", gcd(a, b)
