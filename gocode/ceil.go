package main
import ("fmt")

func test(){
    a:= 10 
    b:= 99 
    sl := make([]int, 0)
    ls := make([][]int, 0)
    for i:=1; i<=b; i++ {
        sl = append(sl, i-1)
        //sl[i] = i
        if ((i>0 && i%a==0) || i==b) {
            ls = append(ls, sl)
            sl = nil
        }
    }
    fmt.Println(ls)
    fmt.Println(len(ls[len(ls)-1:][0]))
    fmt.Println((len(ls) - 1)*len(ls[0]))
    fmt.Println((len(ls) - 1)*len(ls[0]) + len(ls[len(ls)-1:][0]))
    return
}



func main() {
    test()
    return
}
