Este projeto implementa o Algoritmo CYK para verificar se uma Gramática Livre de Contexto (GLC) em Forma Normal de Chomsky (FNC) pode derivar uma palavra de entrada. O aplicativo processa a gramática e a palavra fornecidas através de arquivos e retorna uma tabela triangular CYK em um arquivo de saída.


Requisitos

1. Instale um compilador C++
O projeto foi desenvolvido e testado com o compilador g++.
Verifique se o g++ está instalado em seu sistema. No terminal:
"g++ --version"

2. Sistema Operacional
Compatível com sistemas Unix/Linux e Windows.

3. Estrutura do Projeto
Os arquivos do projeto devem seguir a seguinte estrutura:
cyk.cpp: Arquivo com o código-fonte em C++.
glc.txt: Arquivo de texto definindo a gramática em FNC.
saida.txt: Arquivo gerado pelo programa para armazenar a matriz triangular do algoritmo CYK.


Instruções de Uso

1. Configurar a Gramática (Arquivo glc.txt)
Crie um arquivo glc.txt contendo a gramática em conformidade com o seguinte formato:
Variáveis: Representadas por letras maiúsculas "[A-Z]". A variável inicial deve ser "S".
Terminais: Representados por letras minúsculas "[a-z]".
Definições das Regras: "->" como operador de definição e "|" como separador de produções.
Lambda (produção vazia): Representado pelo símbolo ".".

Exemplo de Gramática em FNC (arquivo glc.txt):
S -> AT | AB
T -> XB
X -> AT | AB
A -> a
B -> b

2. Compilação do Código
Compile o programa usando o g++ no terminal ou no prompt de comando:
"g++ -o ex cyk.cpp"
Esse comando criará um executável chamado "ex".

3. Execução do Programa
Execute o programa a partir do terminal com o seguinte formato:
"./ex glc.txt <palavra> saida.txt"
Exemplo de Execução:
"./ex glc.txt aaabbb saida.txt"
glc.txt: Arquivo contendo a gramática.
aaabbb: Palavra que será verificada.
saida.txt: Nome do arquivo para o qual será salva a tabela CYK.

4. Verificar o Arquivo de Saída
Após a execução, o resultado do algoritmo CYK será salvo no arquivo especificado (saida.txt), contendo a tabela triangular CYK.
Formato do Arquivo de Saída (Exemplo para aaabbb):
{S,X}
{} {T}
{} {S,X} {}
{} {} {T} {}
{} {} {S,X} {} {}
{A} {A} {A} {B} {B} {B}
a a a b b b 

Interpretação:

Cada linha da saída indica as variáveis que podem derivar as subsequências daquela camada da tabela CYK.
A última linha mostra os caracteres da palavra de entrada.
A célula do topo (mais alta da tabela) mostra se a variável inicial (S) foi capaz de derivar a palavra.
