/* Implementation of a calculator in infix notation */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "lexer.h"

void parse_S(int h, int* r);
void parse_X(int h, int* r);
void parse_Y(int h, int *r);

/* look a-head */
static token current;
static int att; /* attribute of current */ 

int max(int a, int b)
{
  return (a > b ? a : b);
}

int power2(int h)
{
    int res = 1;
    int i;
    for(i = 0 ; i < h ; i++)
    {
        res *= 2;
    }

    return res;
}

/* parsing of token */
void parse_token(token expected) {
        if (current != expected) {
                printf("ERROR: expected token ");
                display(expected);
                printf(" but found ");
                display(current);
                printf("\nThe word doesn't belong to the langage\n");
                exit(1);
        }
        if (current != END) {
                current = next(&att);
        }
}

void parse_S(int h, int* r) {
    int r1, r2 = 0;
    if(current == a)
    {
        parse_token(a);
        parse_X(h, &r1);
        parse_Y(h, &r2);
        
        *r = max(r1, r2);
    }
    else
    {
        unexpected(current, "S");
    }
}

void parse_X(int h, int* r) {
    if(current == a)
    {
        parse_S(h+1, r);
        parse_token(b);
    }
    else
    {
        *r = 3*h;
    }
}

void parse_Y(int h, int *r) {
    if(current == c)
    {
        parse_token(c);
        parse_Y(h+1, r);
        parse_token(a);
    }
    else
    {
        *r = power2(h);
    }
}

int main() {
        printf("Simple LL(1) parser\n\n") ;
        printf("Enter a word (recognized) finished by '$'\n") ;
        printf("(Enter 'q' to quit)\n");
        current = next(); /* init of current */
        
        int r = 0;
        parse_S(0, &r);
        printf("The word belongs to the langage\n");
        printf("Output attribute: %d\n\n", r);
        
        printf("End of input\n") ;
        return 0;
}
