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
set_b_ele_min = set_c_min - set_a_min
set_b_ele_max = set_c_max - set_a_max

def insert_in_b(ele_set_b):
    if(ele_set_b > 99):
        return 0
    n = 0
    while n<N[0]:
        #print("in check_p",ele_set_b)
        if (ele_set_b + set_a[n]) not in set_c:
            return
        n+=1
    set_b.add(i)
            
for i in range(set_b_ele_min, set_b_ele_max+1):
    insert_in_b(i)

print(*set_b,sep=' ')
