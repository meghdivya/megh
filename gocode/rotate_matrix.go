package main
import ("fmt")


var mat =  [4][4]int {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

func swap(a *int, b *int) {
    tmp := *a;
    *a = *b;
    *b = tmp;
    return
}

func exchange_rows() {
    for i:=0; i<4; i++ {
        for j,k := i,3 ; j<k ; j,k = j+1,k-1 {
            swap(&mat[i][j], &mat[i][k])
        }
    }
}

func exchange_cols() {
    for i:=0; i<4; i++ {
        for j,k := i,3 ; j<k ; j,k = j+1,k-1 {
            if(mat[j][i] == mat[k][i]) {continue}
            swap(&mat[j][i], &mat[k][i])
        }
    }
}

func transpose() {
   for i:=0; i<4; i++ {
        for j:=i; j<4; j++ {
        if(mat[j][i] == mat[i][j]) {continue}
        swap(&mat[i][j], &mat[j][i])
    }
  }
}

func main() {
    fmt.Println(mat)
    transpose()
    //fmt.Println(mat)
    exchange_cols()
    fmt.Println(mat)
    return
}
