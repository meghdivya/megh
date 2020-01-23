#include<stdio.h>
#include<string.h>

void reverse_string(char* input, int m) {
    //int m = strlen(input) - 1;
    int i=0;
    while(i<m) {
        char tmp = input[i];
        input[i] = input[m];
        input[m] = tmp;
        i++;m--;
        printf("%d, %s\n",__LINE__, input);
    }
}

void reverse_words(char* input) {
    int i = 0;
    int start_index = 0;
    int len = strlen(input);
    while(i<len) {
        if(input[i] == ' ' || (i+1)==len) {
            reverse_string(&input[start_index], start_index+i-1);
            start_index = i+1;
        }
        printf("%d, %s\n",__LINE__, input);
        i++;
    }
    reverse_string(input, strlen(input) -1);
    printf("%s\n", input);
}

int main() {
    char input[] = "I am Sugandh";
    reverse_words(input);
    return 0;
}
