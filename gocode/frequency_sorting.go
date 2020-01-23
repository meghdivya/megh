package main
import "fmt"
import "sort"
//import "reflect"

//abbbbccdde
//aeccddbbbb
type ss struct  {
    freq int
    ch uint8
}
func frequency_sort(ip string) {
    if len(ip) == 0 {
        return
    }
    var m1 map[uint8]int = make(map[uint8]int, 10)
    for i:=0; i<len(ip); i++ {
        m1[ip[i]]++
    }
    sl := make([]ss, 0)
    for k,v:= range m1 {
        //var tmp ss
        //ss.freq := v
        //ss.ch := k
        var tmp = ss{v, k}
        sl = append(sl, tmp)
    }
    sort.Slice(sl, func(i int, j int) bool {
        return sl[i].freq < sl[j].freq
    })
    op:=make([]uint8, 0)
    for i:=0; i<len(sl); i++ {
        for j:=0; j<sl[i].freq; j++ {
            op = append(op, sl[i].ch)
        }
    }
    fmt.Println(string(op))
    return
}

func main() {
    var input string
    fmt.Scanln(&input)
    frequency_sort(input)
    //fmt.Println(reflect.TypeOf(input[0]))
    return
}
