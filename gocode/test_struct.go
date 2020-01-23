package main
import ("fmt")

type Rect struct {
   l, b float64
}

func calArea (R* Rect) (float64){
    return R.l*R.b
}

func (R* Rect) calArea() float64 {
    return R.l*R.b
}

func main() {
    var R1 Rect
    R1.l = 10
    R1.b = 20
    area := calArea(&R1)
    fmt.Println(area)
    area = R1.calArea()
    fmt.Println(area)
    return
}
