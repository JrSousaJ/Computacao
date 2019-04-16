progenitor(jairo, jairojr).
progenitor(lucy, jairojr).
progenitor(jairo, evair).
progenitor(jairo, emerson).
progenitor(jairo,marcos).
progenitor(lucy, viviane).
progenitor(honorio, jairo).
progenitor(maria, jairo).
progenitor(honorio, carlos).
progenitor(honorio, amelia).
progenitor(honorio, nelson).
progenitor(nelson, claudia).

homem(jairo).
homem(jairojr).
homem(evair).
homem(emerson).
homem(marcos).
homem(carlos).
homem(nelson).
homem(honorio).

mulher(lucy).
mulher(viviane).
mulher(maria).
mulher(amelia).
mulher(claudia).
pai(X,Y) :-
    progenitor(X,Y),
    homem(X).
mae(X,Y) :-
    progenitor(X,Y),
    mulher(X).
avo(X,Z) :-
    progenitor(X,Y),
    progenitor(Y,Z),
    homem(X).
avó(X,Z) :-
    progenitor(X,Y),
    progenitor(Y,Z),
    mulher(X).
tia(X,Y) :-
    progenitor(Z,X),
    progenitor(Z,K),
    progenitor(K,Y),
    mulher(X).
tio(X,Y) :-
    progenitor(Z,X),
    progenitor(Z,K),
    progenitor(K,Y),
    homem(X)
    .
irma(X,Y) :-
    progenitor(Z,X),
    progenitor(Z,Y),
    mulher(X).
irmao(X,Y) :-
    progenitor(Z,X),
    progenitor(Z,Y),
    homem(X).
prima(X,Y) :-
    progenitor(K,X),
    progenitor(Z,Y),
    progenitor(L,K),
    progenitor(L,Z),
    mulher(X).

primo(X,Y) :-
    progenitor(K,X),
    progenitor(Z,Y),
    K\=Z,
    progenitor(L,K),
    progenitor(L,Z),
    homem(X).



antepassado(X,Y) :- progenitor(X,Y).

antepassado(X,Y) :- progenitor(X,Z), antepassado(Z,Y).







