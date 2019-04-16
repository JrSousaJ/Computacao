exibeInverso([]) :- nl.
exibeInverso([X|Y]) :- exibeInverso(Y), writeln(X).
