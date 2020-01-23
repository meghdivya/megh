package main
import ("fmt"
        "strconv"
       )


func swap(a *byte, b *byte) {
    tmp := *a
    *a = *b
    *b = tmp
}

func mysort(num []byte) {
    for i:=0; i<len(num); i++ {
        for j:=i; j<len(num); j++ {
            if num[j] > num[j+1] {
                swap(&num[j], &num[j+1])
                fmt.Println("in :",string(num))
            }
        }
    }
}
func next_larger(num []byte) int {
    if(len(num) <=1 ) {
        return -1
    }
    smallest := 1000
    var index_smallest int
    //fmt.Println(num)
    i:= len(num)-1
    for i>0 {
        if smallest > int(num[i]) {
            smallest = int(num[i])
            index_smallest = i
        }
        if num[i] > num[i-1]  {
            swap(&num[index_smallest], &num[i-1])
            //fmt.Println(string(num))
            fmt.Println(string(num[i:len(num)]))
            //sort.Slice(num[i:len(num)],  func(k,m int) bool {
             //   return num[k] < num[m] })
            mysort(num[i:len(num)])
            fmt.Println(string(num[i:len(num)]))
            op,_ := strconv.Atoi(string(num))
            return op
        }
        i--
    }
    return -1
}

func main() {
    var num int
    fmt.Scanf("%d", &num)
    b:= []byte(strconv.Itoa(num))
    fmt.Println(next_larger(b))
}
