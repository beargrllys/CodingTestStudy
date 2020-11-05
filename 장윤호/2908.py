def rev_num():
    a,b = map(int,input().split())
    c = a//100
    a -= c*100
    c += (a//10)*10+(a%10)*100
    d = b//100
    b -= d*100
    d += (b//10)*10+(b%10)*100
    if (c >= d):
        print(c)
    else:
        print(d)
rev_num()
