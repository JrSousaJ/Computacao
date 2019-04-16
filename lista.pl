mostra([]) :- nl.

mostra([X|Y]):- writeln(X), mostra(Y).

tam([],0).

tam([_|Y],T):- tam(Y,TC),T is TC+1 .
