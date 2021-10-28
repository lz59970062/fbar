
from sympy import solve,symbols
a=symbols('a')
x0,x1,x2,x3,x4=symbols('x0:5')
y0,y1,y2,y3,y4=symbols('y0:5')
'''x10,x11,x12,x13,x14=symbols('x10:5')
y10,y11,y12,y13,y14=symbols('y10:5')'''
x0 = -30
x1= -95
x2= -60
x3= 30
x4 = 60

y0 = 75
y1=0
y2=-85
y3=-85
y4=0
s=0.5*(x4-x1)*(y0)+0.5*((x4-x1)+(x3-x2))*(y1-y2)
solve(1.15*s-0.5*(a*x4-a*x1)*(a*y0-a*y1)+0.5*((a*x4-a*x1)+(a*x3-a*x2))*(a*y1-a*y2),a)