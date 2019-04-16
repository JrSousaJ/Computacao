% país(Nome, Área, População)
país(brasil, 9, 130).
país(china, 12, 1800).
país(eua, 9, 400).
país(índia, 3, 450).

densidade(P, R):- país(P,X,Y), R is Y/X .

difpop(P1,P2,R) :- país(P1, _, PO1),
    país(P2, _, PO2),
    PO1 > PO2,
    R is PO1 - PO2.
difpop(P1,P2,R) :- país(P1, _, PO1),
    país(P2, _, PO2),
    PO2 > PO1,
    R is PO2- PO1.

areaigual(P1,P2,R):-país(P1, D1, _),
    país(P2, D2, _),
    D1 == D2,
    R = 'sim'.

areaigual(P1,P2,R):-país(P1, D1, _),
    país(P2, D2, _),
    D1 \= D2,
    R = 'não'.


maiorq(P1,P2,R) :- país(P1, _, PO1),
    país(P2, _, PO2),
    PO1 > PO2,
    R = 'é maior'.

maiorq(P1,P2,R) :- país(P1, _, PO1),
    país(P2, _, PO2),
    PO1 =< PO2,
    R = 'é menor ou igual'.


paises(L) :-  findall(N, país(N,_,_),L).

popmaior(L) :- findall([N,M],(país(N,_,M), M > 500),L).

densidade(L) :- findall(D, (país(_,M,N), D is N/M), L).

maiorp(L) :- findall([D,E],(país(D,E,_)),L).
