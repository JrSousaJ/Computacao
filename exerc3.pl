amiga(priscila,fernanda).
amiga(fernanda, prisicila).
amiga(fernanda, cris).
amigo(lucio, carla).
amigo(lucio, ana).
gosta(maria, joana).
gosta(maria, lucia).
ama(paula, joao).
ama(joao, paula).
ama(paulo, cris).
ama(cris,paulo).
ama(cris, andre).
namorados(X,Y):- ama(X,Y), ama(Y,X).
amiga_intima(X,Y):- amiga(X,Y), amiga(Y, X).
