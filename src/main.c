// #include "expression_tree.h"
// #include "expression_tree.h"
// #include "stack.h"
#include<stdio.h>
#include <stdlib.h>

typedef enum PreferredType {
    INIT_P,
    NUMBER_P,
    IDENTIFIER_P,
    OPERATOR_P,
} PreferredType;


typedef enum TokenType {
    INIT,
    NUMBER,
    IDENTIFIER,
    OPERATOR,
    PARENTHESIS,
    BRACE,
    BRACKET,
} TokenType;


typedef struct Token {
    void * value;
    TokenType type;
    size_t start ;
    size_t end;
} Token;


typedef struct Range {
    size_t start;
    size_t size;
    char * expression;
    Token token;
} Range ;

#define AND &&
#define OR ||
#define And &&
#define Or ||
#define and &&
#define or ||

// void parse_expression(char *expression, size_t size ) {
//     Stack * stack = create_stack(size);
//     for(int i = size-1; i >= 0 ; i--){
//         printf("%c\n", expression[i]);
//         char token = expression[i];
//         if(token == ')' || token == '}' || token == ']' ) {
//             BracketExpression * expression = create_bracket_expression(i);
//             switch (token) {
//                 case '}':
//                     expression->type = BRACE;
//                     break;

//                 case ']':
//                     expression->type = BRACE;
//                     break;

//                 case ')':
//                     expression->type = PARENTHESIS;
//                     break;
//             }
//             push(stack, expression);
//         } else if (token == '(' || token == '{' || token == '[') {
//             BracketExpression * expression = create_bracket_expression(i);
//             switch (token) {
//                 case '(':
//                     expression->type = PARENTHESIS;
//                     break;

//                 case '{':
//                     expression->type = BRACE;
//                     break;

//                 case '[':
//                     expression->type = BRACKET;
//                     break;
//             }
//             pop(stack);
//         }

//     }
// }

int is_any(char item, char * items){
    int i = 0;

    while(items[i] != '\0') {
        if (items[i] == item) {
            return 1;
        }
        i++;
    }
    return 0;
}


Token *  tokenize(char *expression, size_t size , size_t * count_required) {

    // Stack * tokens_stack = create_stack(size);
    Token * tokens = (Token *) malloc(sizeof(Token) * size );
    int point = 0;

    PreferredType now_parsing =INIT_P;
    int start = 0;
    int count = 0;
    int point_used = 0;



    // for(int i = 0; i < size ; i++){

    //     char token = expression[i];

    //     if((token >= '0' && token <= '9') || token == '.' ) {
    //         if(token == '.' && now_parsing > NUMBER_P) {
    //             printf("Unexpected \".\" found at %d", i);
    //             exit(1);
    //         }
    //         if(now_parsing < NUMBER_P ){
    //             tokens[point].value = NULL;
    //             tokens[point].type = (TokenType)now_parsing;
    //             tokens[point].start = start;
    //             tokens[point].end = start+count;
    //             point++;
    //             start = i;
    //             now_parsing = NUMBER_P;
    //             count = 0;
    //         }else{
    //             count++;
    //         }
    //     }else if((token >= 'a' && token <= 'z' ) || (token >= 'A' && token <= 'Z') || token == '_'){
    //         if(now_parsing < IDENTIFIER_P) {
    //             tokens[point].value = NULL;
    //             tokens[point].type = (TokenType)now_parsing;
    //             tokens[point].start = start;
    //             tokens[point].end = start+count;
    //             point++;
    //             start = i;
    //             count = 0;
    //             now_parsing = IDENTIFIER_P;
    //         }
    //         count++;
    //     }else{
    //         switch (token) {
    //             case '+':
    //             case '-':
    //             case '*':
    //             case '/':
    //             case '!':
    //             case '^':
    //                 if(now_parsing < OPERATOR_P) {
    //                     tokens[point].value = NULL;
    //                     tokens[point].type = (TokenType)now_parsing;
    //                     tokens[point].start = start;
    //                     tokens[point].end = start+count;
    //                     point++;
    //                     start = i;
    //                     count = 0;
    //                     now_parsing = OPERATOR_P;
    //                 }
    //                 count++;
    //                 tokens[point].value = NULL;
    //                 tokens[point].type = (TokenType) now_parsing;
    //                 tokens[point].start = start;
    //                 tokens[point].end = start+count;
    //                 point++;
    //                 start = i;
    //                 count = 0;
    //                 now_parsing = INIT_P;
    //                 break;
    //         }
    //     }

    // }

    for(int i = 0;  i < size ; i++){
        // printf("%c\n", expression[i]);
        char token = expression[i];

        // if the token is a digit
        if( (token >= '0' and token <= '9' )){
            if( now_parsing < NUMBER_P) {
                tokens[point].value = NULL;
            }
        }
    }

    (*count_required) = point;

    return tokens;
}


void print_tokens_stream(Token * tokens , size_t size , char * expression ){
    for (size_t i = 0; i < size; i++) {
        Token token = tokens[i];
        printf("Token(%.*s)\n", (int)(token.end - token.start), expression + token.start);
    }
    printf("\n");
}

int main(){


    // Range range = {0, 21, 22, "a+b^(c-d)+(e-f)^(5/4)"};
    size_t count_required =0 ;
    char* expression = "amainak+b^(c-d)+(e-f)^(5/4)";
    // Stack * context = create_stack(22);
    // Token * tokens = tokenize(expression, 22, &count_required);

    // print_tokens_stream(tokens, count_required, expression);

    // print_stack(stack);

    printf("Hello World\n");
    return 0;
}
