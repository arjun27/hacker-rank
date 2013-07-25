# median
# 5 on 10 correct

def solve(operations):
    ar = []
    for op in operations:
        if op[0] == 'r':
            (ar, result) = remove(ar, long(op[1]))
            if not result:
                print 'Wrong!'
                continue
        elif op[0] == 'a':
            ar = add(ar, long(op[1]))
        m = median(ar)
        if not m:
            print 'Wrong!'
        elif m.is_integer():
            print int(m)
        else:
            print m

def remove(ar, i):
    try:
        ar.remove(i)
        return (ar, True)
    except Exception, e:
        return (ar, False)

def add(ar, i):
    ans = []
    appended = False
    for j in ar:
        if j <= i or appended:
            ans.append(j)
        else:
            ans.append(i)
            ans.append(j)
            appended = True
    if not appended:
        ans.append(i)
    return ans

def median(ar):
    n = len(ar)
    if n:
        return 0.5 * (ar[n/2] + ar[(n-1)/2])
    else:
        return None

n = int(input())
operations = []
for i in range(n):
    operations.append(raw_input().strip().split())
solve(operations)