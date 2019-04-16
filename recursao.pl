som(0,0).
som(1,1).
som(X,R) :- X1 is X-1, som(X1,F1), R is F1+X.

%pot(Valor, expoente, resultado).
pot(_,0,1).

pot(X,E,R) :- E1 is E - 1, pot(X,E1,R1), R is R1*X.
