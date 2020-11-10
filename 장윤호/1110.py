n = int(input())
c = n
i = 0

while True:
    if(0<=n<=99):
        a = sum([int(k) for k in str(n)])
        a = str(a)
        if(n<10):
            n = '0' + str(n)
            n = n[1] + a[0]
            i+=1
        else:
            n = str(n)
            if(int(a)>=10):
                n = n[1] + a[1]
            else:
                n = n[1] + a[0]
            i+=1
        n=int(n)
    if(c == n):
        break
print(i)
# N = int(input())
# n = -1
# t = 0
# while n != N:
# 	if n == -1: n = N
# 	n = (n//10 + n%10)%10 + (n%10)*10
# 	t += 1
# print(t)
