# 24568 : Cupcake Party
a = int(input())
b = int(input())
num = ((a*8) + (b*3)) - 28
if num < 0:
    num = 0
print(num)