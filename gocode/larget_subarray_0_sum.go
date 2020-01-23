package main
import("fmt")

func check_map(m map[int]bool) {
    if val,ok:= m[0]; ok==true{
        fmt.Println(val,ok)
    }else  {
        fmt.Println("bad",val,ok)
    }
}
func main() {
    var N int
    m := make(map[int]int)
    z := make(map[int]bool)
    z[1] = false
    check_map(z)
    return
    fmt.Scanf("%d", &N)
    arr := make([]int,N)
    sum_till_now := 0
    max_index := 0
    first_index := -1
    fmt.Println(arr)
    var ele int
    for i:=0;i<N;i++ {
       fmt.Scanf("%d", &ele)
       arr[i] = ele
       sum_till_now += arr[i]
       m[sum_till_now]++
       if i>0 {
            if sum_till_now==0 {
                max_index = i
                first_index = 0
            }else {
                if(first_index != 0) {
                    first_index = i
                }
            }

            fmt.Println("ssss: ",m[sum_till_now])
            if val,ok:= m[sum_till_now]; val>1 && ok{
               max_index = i
               fmt.Println("rsss: ",m[sum_till_now], first_index, max_index)
            }
       }
    }
    fmt.Println(m)
    if first_index < max_index && max_index !=0{
        if first_index == -1 {
            first_index = 0
            
        }
        fmt.Println("first, max-index :", first_index, max_index, arr[first_index:max_index+1])
    }else {
        fmt.Println("nothing found\n")
    }
    return
}
