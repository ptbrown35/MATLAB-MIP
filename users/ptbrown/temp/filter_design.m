clear
clc

syms z

h = 0.01;
t = 1;

s = (2*z - 1)/(h*z + 1);

LP = 1 / (t*s + 1);
HP = t*s/(t*s + 1);

LP = simplify(LP)
HP = simplify(HP)
