# Simple lexer

This project is a simple test for a LL(1) grammar lexer.

#### BNF:
'Epsilon' means empty set  
$ is the EOF character  
Starting h: 0  

(1) S↓h↑r := a X↓h↑r1 Y↓h↑r2			r:=max(r1,r2)

(2) X↓h↑r := S↓h+1↑r b  
(3) X↓h↑r := Epsilon							r := 3*h

(4) Y↓h↑r := cY↓h+1↑r a  
(5) Y↓h↑r := Epsilon							r := 2^h


##### LL(1) directors:
Dir(1) = {a}

Dir(2) = {a}  
Dir(3) = {b, c, $}

Dir(4) = {c}  
Dir(5) = {a, b, $}