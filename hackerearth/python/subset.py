from __future__ import print_function  # Py 2.6+; In Py 3k not needed
N = map(int, raw_input())
set_a = []
set_a = map(int, raw_input("").split(' '))
M = map(int, raw_input())
set_c = []
set_c = map(int, raw_input("").split(' '))

set_b = set()
set_a.sort()
set_c.sort()
n_set_a = 0
n_set_c = 0
ele_set_b = 0
set_c_min = min(set_c)
set_c_max = max(set_c)
set_a_min = min(set_a)
set_a_max = max(set_a)
def check_possiblity(ele_set_b, set_a, set_c):
    if(ele_set_b > 99):
        return 0
    n = 0
    while n<N[0]:
        #print("in check_p",ele_set_b)
        if (ele_set_b + set_a[n]) not in set_c:
            return 0
        n+=1
    return 1
        
        
while n_set_c<M[0]:
    n_set_a = 0
    while n_set_a<N[0]:
        ele_set_b = set_c[n_set_c]- set_a[n_set_a]
        #print("c,a,b", set_c[n_set_c], set_a[n_set_a], ele_set_b)
        #if ele_set_b > 0 and ele_set_b >= (set_c_min- set_a_max) and ele_set_b <= (set_c_max - set_a_min):
        if ele_set_b > 0:
            if check_possiblity(ele_set_b, set_a, set_c):
                set_b.add(ele_set_b)
        n_set_a+=1
    n_set_c+=1

print(*set_b,sep=' ')
