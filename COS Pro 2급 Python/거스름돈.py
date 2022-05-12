def solution(price, money):
    sum = 0
    
    for cost in price:
        sum = sum + cost
    
    if money - sum < 0:
        return -1
    
    return money - sum
