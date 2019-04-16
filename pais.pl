% pa�s(Nome, �rea, Popula��o)
pa�s(brasil, 9, 130).
pa�s(china, 12, 1800).
pa�s(eua, 9, 400).
pa�s(�ndia, 3, 450).

densidade(P, R):- pa�s(P,X,Y), R is Y/X .

difpop(P1,P2,R) :- pa�s(P1, _, PO1),
    pa�s(P2, _, PO2),
    PO1 > PO2,
    R is PO1 - PO2.
difpop(P1,P2,R) :- pa�s(P1, _, PO1),
    pa�s(P2, _, PO2),
    PO2 > PO1,
    R is PO2- PO1.

areaigual(P1,P2,R):-pa�s(P1, D1, _),
    pa�s(P2, D2, _),
    D1 == D2,
    R = 'sim'.

areaigual(P1,P2,R):-pa�s(P1, D1, _),
    pa�s(P2, D2, _),
    D1 \= D2,
    R = 'n�o'.


maiorq(P1,P2,R) :- pa�s(P1, _, PO1),
    pa�s(P2, _, PO2),
    PO1 > PO2,
    R = '� maior'.

maiorq(P1,P2,R) :- pa�s(P1, _, PO1),
    pa�s(P2, _, PO2),
    PO1 =< PO2,
    R = '� menor ou igual'.


paises(L) :-  findall(N, pa�s(N,_,_),L).

popmaior(L) :- findall([N,M],(pa�s(N,_,M), M > 500),L).

densidade(L) :- findall(D, (pa�s(_,M,N), D is N/M), L).

maiorp(L) :- findall([D,E],(pa�s(D,E,_)),L).
