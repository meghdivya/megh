package main
import ("fmt")
import ("time")

func recv(ch chan int) {
    fmt.Println("waiting for channel ", ch)
    val := <-ch
    fmt.Println(val)
}

func main() {
    ch := make(chan int)
    go recv(ch)
    time.Sleep(10)
    fmt.Println("sending after 10 ms")
    ch<-3
    return
}
