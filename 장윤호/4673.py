list = [i for i in range(1, 10001)] #1~10000까지의 리스트 생성
for j in range(1, len(list)):
    a = sum([int(k) for k in str(j)],j) #각 자리의 수 합+ 원래 수
    if a in list:
        list.remove(a)
        # 그런데 왜 문제에 언급되어 있는 재귀호출을 사용하지 않았는데도 정답이 출력되었는가?

print(*list)

