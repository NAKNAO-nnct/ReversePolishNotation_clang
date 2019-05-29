#include <stdio.h>
#include <string.h>

// stack
#define STACK_SIZE    100  /* スタックデータ数の最大値 */
#define SUCCESS       1    /* 成功 */
#define FAILURE       0    /* 失敗 */

typedef int data_t;

typedef struct {
    int num;
    data_t data[STACK_SIZE];
} stack_t;

int push(stack_t *stk, data_t push_data)
{
    if (stk->num < STACK_SIZE) {
        stk->data[stk->num] = push_data;
        stk->num ++;
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

int pop(stack_t *stk, data_t *pop_data)
{
    if (stk->num > 0) {
        stk->num --;
        *pop_data = stk->data[stk->num];
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

void stackPrint(stack_t *stk)
{
    int i;

    printf("stack [");
    for (i = 0; i < stk->num; i++) {
        printf("%3d", stk->data[i]);
    }
    printf("]\n");
}

void rmStr(char *str){
//    char c = str;
//    *str++ = '\0';
    const int len = strlen(str);
    char *rt ;

    for(int i=0; i<len; i++){
        if(str[i] == '\'')
            continue;
        *rt = str[i];
//        if(*(str+i) == '/') {
//            *(str+i) = '\0';
//            printf("Fuck you! %d\n", i);
//            break;
//        }
    }
//    *str = '\0';
//    if(*str == '/'){}
//        printf("Fuck you!\n");
//    return *str;
//    str[4] = ' ';
    printf("%s\n", str);
}

int main(int argc, char *argv[]) {

    char *input = "'123.456+3.14/(100-5)'";

    printf("Before: %s\n", input);
    rmStr(input);
    printf("After : %s\n", input);



//    while(1){
//
//    }


    stack_t stk;
    int i, p;

    stk.num = 0; /* スタックのデータ数を 0 に初期化 */
    for (i = 1; i <=4 ; i++) {
        push(&stk, i);                  /* 1 から 4 までの数値を push */
        printf("push %2d :", i);
        stackPrint(&stk);
    }
    while (stk.num > 0) {
        pop(&stk, &p);                /* スタックに残っているデータを全て pop */
        printf("pop  %2d :", p);
        stackPrint(&stk);
    }

    return 0;
}