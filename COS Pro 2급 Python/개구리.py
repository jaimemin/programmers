def solution(stones):
    cnt = 0
    current = 0
    n = len(stones)
    while current < n:
        current += stones[current]

        cnt += 1
    return cnt
