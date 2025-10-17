Como compilar e executar

1) Compilar:

	gcc logicaSuperTrunfo.c -o logicaSuperTrunfo

2) Executar:

	./logicaSuperTrunfo

Menus (exemplo)

Ao pedir o primeiro atributo, o programa mostra:

  1 - População
  2 - Área
  3 - PIB
  4 - Densidade Populacional
  5 - PIB per Capita
  0 - Aleatório

Depois de escolher o primeiro, o segundo menu NÃO mostrará o atributo já escolhido (para não repetir).

Atributos disponíveis (o que significam)

1 - População (maior é melhor)
2 - Área (maior é melhor)
3 - PIB (maior é melhor)
4 - Densidade Populacional (menor é melhor)
5 - PIB per Capita (maior é melhor)

Observação: digite 0 para deixar a escolha aleatória.

Exemplo de execução (entradas e saídas simplificadas):

1) Entradas (exemplo que você digita):

  Carta 1:
    Estado: A
    Código: A01
    Nome: CidadeA
    População: 10000
    Área: 50
    PIB: 2000
    Pontos turísticos: 5

  Carta 2:
    Estado: B
    Código: B01
    Nome: CidadeB
    População: 15000
    Área: 30
    PIB: 1500
    Pontos turísticos: 3

2) Escolhas de atributos (você digita):

  Primeiro atributo: 1 (População)
  Segundo atributo: 4 (Densidade Populacional)

3) Saída (o que o programa mostra):

  Comparação por atributo 1 (População):
  CidadeA: 10000.00
  CidadeB: 15000.00
  Vencedor do atributo 1: CidadeB

  Comparação por atributo 2 (Densidade Populacional):
  CidadeA: 200.00
  CidadeB: 500.00
  Vencedor do atributo 2: CidadeA

  Soma dos atributos:
  CidadeA: 10200.00
  CidadeB: 15500.00

  Resultado: CidadeB vence pela maior soma.


