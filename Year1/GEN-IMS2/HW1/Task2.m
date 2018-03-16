close all;
clear all;

R=1e3;
C=1;

num=[1];
den=[R*C 1];

G=tf(num, den);
bode(G);
grid on;