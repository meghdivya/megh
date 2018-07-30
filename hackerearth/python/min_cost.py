
# Write your code here                                   
def calculate_minimum_cost_optimize(N,A,B):                
    X = (B*N)/(A+B)                                        
    X1 = (float(B)*float(N))/(float(A)+float(B))           
    if X1-X >= 0.5:                                     
        X+=1                                               
    Y=N-X                                                  
    return min(A*(X**2)+ B*(Y**2), A*(Y**2)+B*(X**2))      
                                                           
                                                           
                                                           
n_tc= raw_input()                                          
n_tc = int(n_tc)                                           
                                                           
while(n_tc):                                               
    N,A,B = raw_input("").split(' ')                       
    N = int(N)                                             
    A = int(A)                                             
    B = int(B)                                             
    print calculate_minimum_cost_optimize(N,A,B)           
    n_tc -= 1                                              
                                  
