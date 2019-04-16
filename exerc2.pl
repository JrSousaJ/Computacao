joga(carlos, basquete).
joga(andre, futebol).
joga(rodrigo,basquete).
luta(luiz,karatê).
luta(fernando, kungFu).
luta(mario, karatê).

jogador(andre).
jogador(carlos).
jogador(joao).
lutador(mario).
lutador(fernando).
vencedor(mario).
vencedor(andre).
vencedor(carlos).
doping(rodrigo).
doping(carlos).
campeao(X,Y):-vencedor(X), joga(X,Y).
campeao(X,Y):-vencedor(X), luta(X,Y).
desclassificado(X,Y):-doping(X), campeao(X,Y).
