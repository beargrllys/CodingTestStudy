list = [i for i in range(1, 10001)]

def self_num():
    a = sum([int(k) for k in str(j)],j) #각 자리의 수 합+ 원래 수
    if a in list:
        list.remove(a)
        while(a>10000):
            self_num()

for j in range(1, len(list)):
    self_num()

print(*list)

