import itertools

def split_list(l):
    n = (len(l)) // 2 + (len(l) % 2)
    return l[: n], l[n:]

def add_polynomials(p1, p2):
    ret = [a + b for a, b in itertools.zip_longest(p1, p2, fillvalue = 0)]
    return ret

def sub_polynomials(p1, p2):
    ret = [a-b for a, b in itertools.zip_longest(p1, p2, fillvalue = 0)]
    return ret

def multply_polynomials(p1, p2):
    
    if (len(p1) == 0):
        return []
    
    if (len(p1) == 1):
        return [p1[0] * p2[0]]
    if (len(p2) == 2):
        a1b1 = p1[1] * p2[1]
        a0b0 = p1[0] * p2[0]
        mid = (p1[0] + p1[1])*(p2[0] + p2[1])-a1b1-a0b0
        return [a0b0, mid, a1b1]
    
    A0, A1 = split_list(p1)
    B0, B1 = split_list(p2)
    
    
    A0B0 = multply_polynomials(A0, B0)
    A1B1 = multply_polynomials(A1, B1)
    mid = multply_polynomials(add_polynomials(A0, A1), add_polynomials(B0, B1))
    mid = sub_polynomials(mid, A0B0)
    mid = sub_polynomials(mid, A1B1)
    
    c = len(A0)
    ret = [0 for i in range(len(A1B1) + 2 * c)]
    
    for i in range(len(A0B0)):
        ret[i] = A0B0[i]
    
    for i in range(len(mid)):
        ret[i+c] += mid[i]
        
    for i in range(len(A1B1)):
        ret[i+2*c] += A1B1[i]
    
    return ret
    

def multiply(p1, p2):
    n = len(p1)
    m = len(p2)
    if (len(p1) < len(p2)):
        l = [0] * (len(p2) - len(p1))
        p1.extend(l)
    elif (len(p1) > len(p2)):
        l = [0] * (len(p1) - len(p2))
        p2.extend(l)
    
    ret = multply_polynomials(p1, p2)
    return ret[:(n+m)]
    
t = int(input())
for i in range(t):
    n, m = [int(x) for x in input().split()]
    p1 = [int(x) for x in input().split()]
    p2 = [int(x) for x in input().split()]
    res = multiply(p1, p2)
    print(*res)
        
