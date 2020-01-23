package main
import ("fmt")

func main() {
    var N int
    fmt.Scanf("%d",&N)
    arr := make([]int, N)
    for i:=0;i<N;i++ {
        fmt.Scanf("%d",&arr[i])
    }
    var high int = N-1
    var low = 0
    var mid int
    for low<=high {
        mid = (high+low)/2
        if arr[mid] == 1 && (mid == 0 || arr[mid-1] == 0) {
            fmt.Println("answer: ",mid)
            return
        }
        if arr[mid] == 1 {
            high = mid-1
        }
        if arr[mid] == 0 {
            low = mid+1
        }
    }
    fmt.Println("answer: -1")
    return
}
