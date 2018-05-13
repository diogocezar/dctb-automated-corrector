## Corretor Automático

![Execução do Corretor Automático](https://raw.githubusercontent.com/diogocezar/dctb-files-equality/master/img/screen.png)

Olá, este é um programa simples para a correção automática de trabalhos.

Para este exemplo foi considerado o seguinte cenário:

1. tem-se uma pasta com várias outras pastas;
2. cada subpasta representa a entrega de um aluno;
3. dentro de cada pasta, se têm apenas um arquivo com a extensão .c;

A seguinte de estrutura representa as entregas:

```
sample
├── ALUNO1
│   └── ex1.c
├── ALUNO2
│   └── ex1.c
├── ALUNO3
│   └── ex1.c
└── ALUNO4
    └── ex1.c
```

Essa pasta deve estar compactada em um .zip;

Este é um script desenvolvido em Python3+ que irá comparar a entrega de cada aluno, com todas as demais.

O script faz uma análise simples de similaridade e retorna a porcentagem de equivalência entre o código analisado do aluno em questão com todos os outros.

Depois disso, o script: executa o código em c, salva o resultado, e o comparara com um gabarito, também passado por parâmetro.

Para usar o script:

```
$python3 tester.py ./sample.zip result-check.txt
```

Onde:

    + __python3__ é o comando para executar o python
    + __teste.py__ é o nome do script para executar os testes
    + __./sample.zip__ é o nome do pack compactado
    + __result-check.txt__ é o nome do arquivo gabarito que deverá ser compatilhado