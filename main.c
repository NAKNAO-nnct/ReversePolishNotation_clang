#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stack
#define STACK_SIZE    100  /* スタックデータ数の最大値 */
#define SUCCESS       1    /* 成功 */
#define FAILURE       0    /* 失敗 */

typedef int data_t;

typedef struct {
    double num;
//    double decimal;
//    char*
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

// 指定文字列を削除
char* rmStr(char *str, char symbol){

    const int len = strlen(str);
    int count = 0;

    char *rt = (char *)malloc(1000 * sizeof(char));

    for(int i=0; i<len; i++){
        if(str[i] == symbol)
            continue;
        rt[count] = str[i];
        count++;
    }

    return rt;
}

// 指定した文字列までを返す
char* splitSymbol(char *str, char symbol){
    const int len = strlen(str);

    char *rt = (char *)malloc(1000 * sizeof(char));

    for (int i=0; i<len; i++){
        if(str[i] == symbol)
            break;
        rt[i] = str[i];
    }

    return rt;
}

int main(int argc, char *argv[]) {

    char *input = "'123.456+3.14/(100-5)'";

    printf("input: %s\n", input);

    // \'を削除
    char *data =(char *)malloc(1000 * sizeof(char));
    strcpy(rmStr(input, '\''), data);
//    *data = rmStr(input, '\'');
    printf("numFormula  : %s\n", data);

    // 数字分割
    while(1){
        break;
    }



//    while(1){
//
//    }


//    stack_t stk;
//    int i, p;
//
//    stk.num = 0; /* スタックのデータ数を 0 に初期化 */
//    for (i = 1; i <=4 ; i++) {
//        push(&stk, i);                  /* 1 から 4 までの数値を push */
//        printf("push %2d :", i);
//        stackPrint(&stk);
//    }
//    while (stk.num > 0) {
//        pop(&stk, &p);                /* スタックに残っているデータを全て pop */
//        printf("pop  %2d :", p);
//        stackPrint(&stk);
//    }

    return 0;
}

// コマンドに数式をいれて計算する
