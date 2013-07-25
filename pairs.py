def find_pairs(ar, k):
    less = [i - k for i in ar]
    common = common_elements(less, ar)
    return common
    
def common_elements(ar1, ar2):
    i = 0
    j = 0
    common = 0
    while i < len(ar1) and i < len(ar2):
        if ar1[i] < ar2[j]:
            i = i + 1
        elif ar1[i] > ar2[j]:
            j = j + 1
        else:
            common = common + 1
            i = i + 1
            j = j + 1
    return common


[n, k] = [int(i) for i in raw_input().strip().split()]
ar = [int(i) for i in raw_input().strip().split()]
ar.sort()
print find_pairs(ar, k)