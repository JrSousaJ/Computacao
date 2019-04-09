soma(0,0).
soma(1,1).
soma(X,R) :- X1 is X-1, som(X1,F1), R is F1+X.

potencia(_,0,1).
potencia(X,E,R) :- E1 is E - 1, pot(X,E1,R1), R is R1*X.
divint(X,Y,R) :-  .
divint(X,Y,R) :- R is X//Y.

restoint(X,Y,R) :- R is X mod Y.

fib(1,1).
fib(2,1).

fib(X,R) :-  X1 is X-1, fib(X1,R1), X2 is X-2, fib(X2,R2), R is R1+R2.
