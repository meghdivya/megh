package main
import ("fmt")

//words = make([]string, 5);

var dict =  []string{"cat", "dog", "sand", "cats" , "dogs", "sand"};

func check_word_in_dict(word string) (bool){
    for i:= range dict {
        if(word == dict[i]) {
            return true
        }
    }
    return false
}
func check_words(partial []string, input string) {
    //fmt.Println("check word called\n")
    if(len(input) == 0) {
        fmt.Println("output", partial)
        return
    }
    for i,_:= range input {
        word := input[:i+1]
        if(check_word_in_dict(word)) {
            partial = append(partial, word)
            fmt.Println("sugandh ",i, partial)
            check_words(partial, input[i+1:])
            partial = partial[:len(partial)-1]
            fmt.Println("sonam",i, partial)
        }
    }
}

func main() {
    //for _,ele := range dict {
     //   fmt.Println(ele)
   // }
    var input = "catsdogsand"
    var partial = make([]string, 5, 5)
    fmt.Println(len(partial), cap(partial))
    check_words(partial, input);
    //fmt.Println(partial, len(partial), cap(partial))
    return
}
