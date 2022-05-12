# 다음과 같이 import를 사용할 수 있습니다.
# import math

def isFull(garden):
    length = len(garden)
    
    for y in range(length):
        for x in range(length):
            if garden[y][x] == 0:
                return False
    return True

def getCopyGarden(garden):
    length = len(garden)
    copyGarden = [[0 for y in range(length)] for x in range(length)]
        
    for y in range(length):
        for x in range(length):
            copyGarden[y][x] = garden[y][x]
    
    return copyGarden
    
def solution(garden):
    # 여기에 코드를 작성해주세요.
    answer = 0
    length = len(garden)
    
    while not isFull(garden):
        copyGarden = getCopyGarden(garden)
        
        for y in range(length):
            for x in range(length):
                if copyGarden[y][x] == 0:
                    continue
                
                if y != 0:
                    garden[y-1][x] = 1
                if y != length - 1:
                    garden[y+1][x] = 1
                if x != 0:
                    garden[y][x-1] = 1
                if x != length - 1:
                    garden[y][x+1] = 1
        
        answer = answer + 1
    
    return answer

# 아래는 테스트케이스 출력을 해보기 위한 코드입니다.
garden1 = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
ret1 = solution(garden1)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret1, "입니다.")

garden2 = [[1, 1], [1, 1]]
ret2 = solution(garden2)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret2, "입니다.")

garden1 = [[0, 0, 0], [0, 0, 1], [0, 0, 0]]
ret3 = solution(garden1)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret3, "입니다.")
