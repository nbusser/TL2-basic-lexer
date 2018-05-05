/* Interface of a lexer (for calculators) */

#ifndef _LEXER_H
#define _LEXER_H 1

typedef enum { a, b, c, END } token;

extern token next();

/* display t and its possible attribute v
   if v < 0 then v is considered as irrelevant 
   (it is printed as "...")
*/
extern void display(token t);

/* 1) print an error message "unexpected token"
   displaying t and its possible attribute v 
   with an explanation mesg (possibly empty),
   2) then, stop execution (exit).
 */
extern void unexpected(token t, const char *mesg);



#endif /* !_LEXER_H */
