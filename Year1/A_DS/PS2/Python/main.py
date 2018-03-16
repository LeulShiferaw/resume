#!/usr/share/python
class RatNum:
    def __init__(self, a, b):
        self.d=a
        self.e=b
        assert (self.e>0),"e is not positive"
    def equal(self, b):
        return self.d*b.e==self.e*b.d
    def gcd(a, b):
        if a > b:
            temp=a
            a=b
            b=temp
        if a==0:
            return b
        return gcd(b%a, a)
    def add(self, b):
        return RatNum(self.d*b.e+self.e*b.d, self.e*b.e)
    def addinv(self):
        return RatNum(-self.d, self.e)
    def mult(self, b):
        return RatNum(self.d*b.d, self.e*b.e)
    def multinv(self):
        return RatNum(self.e, self.d)
    def normal(self):
        g=gcd(self.d, self.e)
        return RatNum(self.d/g, self.e/g)

