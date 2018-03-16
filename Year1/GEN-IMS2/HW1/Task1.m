close all;
clear all;

R=1e5;
C=1;

num=[R*C 0]
den=[R*C 1]

G=tf(num, den);
bode(G);
grid on;