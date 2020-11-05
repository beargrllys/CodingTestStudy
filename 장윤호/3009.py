def four_num():
    a,b = map(int,input("1번 점 좌표: ").split())
    c,d = map(int,input("2번 점 좌표: ").split())
    e,f = map(int,input("3번 점 좌표: ").split())
    g = int(0) #4번 점 x좌표
    h = int(0) #4번 점 y좌표
    if (b == d): #1번 점과 2번 점이 동일 y축에 있을 때 
        h = f #4번 점 y좌표
        if (a == e):
            g = c
        else:
            g = a
    elif (a == c): #1번 점과 2번 점이 동일 x축에 있을 때
        g = e #4번 점 x좌표
        if (b == f):
            h = d
        else:
            h = b
    else: #1번 점과 2번 점이 대각선으로 위치해있을 때
        if(b == f):
            g = a
            h = d
        else:
            g = c
            h = b
               
    print(g,h, end=' ')
four_num()