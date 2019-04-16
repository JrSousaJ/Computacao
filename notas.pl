nota(joao,5.0).
nota(maria,6.0).
nota(joana,8.0).
nota(mariana,9.0).
nota(cleuza,8.5).
nota(jose,6.5).
nota(jaoquim,4.5).
nota(mara,-1).
nota(mary,11).

aprovado(A) :- nota(A,Y), Y>=7 , Y=<10.

recuperacao(A) :- nota(A,Y), Y>=5, Y<7.

reprovado(A) :- nota(A,Y), Y>=0, Y<5.

errado(A) :- nota(A,Y), (Y<0 ; Y>10).
