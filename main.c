#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define SPACER printf("----------------------------------------------\n")

int checkPair(char item1,char item2);
int isParenthesisBalanced(char exp[]);


int main() {
    SPACER;
    printf("\n        Balanced Parenthesis Checker\n\n");
    SPACER;
    
    char exp[MAX], response='y', trash[MAX];
    
    while(response == 'y'){
        printf("Enter your expression: ");
        scanf("%s", &exp);
        printf("\n");

        isParenthesisBalanced(exp) ?
            printf("        Parenthesis Are Balanced\n") :
            printf("        Parenthesis Are Not Balanced\n");
        SPACER;
        
        printf("\nCheck another expression?\n");
        printf("     y:'YES'   n:'NO'\n");
        fgets(trash, 100, stdin);  
        scanf("%c", &response);
    }

    SPACER;
    printf("    Thanks for your time!\n");
    SPACER;
  
}


// Check if the two input parameters are matching parenthesis
int checkPair(char item1,char item2){
    return (( item1=='(' && item2==')' )||( item1=='[' && item2==']' )||( item1=='{' && item2=='}' ));
}


// Check if every opening parenthesis "(-{-[" has the corresponding closing one ")-}-]"
// It takes a string that contains the expression to be checked
// Characters other than "(-{-[-]-}-)" are normally ignored
int isParenthesisBalanced(char exp[]){

    struct stack myStack;
    myStack.top = -1;
      
    for (int i = 0; exp[i]!='\0'; i++){

        // If it is an opening parenthesis "(, [, {", push it to the stack 
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(&myStack, exp[i]); 
        }

        // If it is a closing parenthesis
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){

            // Check if the stack is empty, and there is no corresponding opening one
            if (myStack.top == -1){
                printf("The closing parenthesis \'%c\' at index %d has no correspoding opening\n",
                exp[i], i);
                //SPACER;
                return 0;
            }
            // Check if it is NOT matching with the last opened parenthesis (top of stack)
            else if( !checkPair(myStack.stck[myStack.top], exp[i]) ){
                printf("The closing parenthesis \'%c\' at index %d is not matching with the last opened parenthesis \'%c\'\n",
                exp[i], i, myStack.top);
                //SPACER;
                return 0;
            }
            // Ensure that it is matching with the last opened parenthesis (top of stack)
            else if(checkPair(myStack.stck[myStack.top], exp[i])){
                pop(&myStack);
            }
        }
    }
    // Check if the stack is still NOT empty after parsing the whole expression
    if(myStack.top>-1){
        printf("There are %d opened parenthesis at the end of expression which are not closed\n", myStack.top+1);
        //SPACER;
        return 0;
    }
    // Check that the stack is empty (all opened parenthesis are properly closed)
    else if(myStack.top == -1){
        return 1;
    }
}