# 🧠 Algoritmo CYK — Gramáticas Livres de Contexto
![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=c%2B%2B&logoColor=white)

Implementação do **algoritmo CYK (Cocke–Younger–Kasami)** em C++, utilizada para verificar se uma palavra pertence à linguagem gerada por uma **Gramática Livre de Contexto (GLC)** na **Forma Normal de Chomsky (FNC)**.

Projeto desenvolvido com fins **acadêmicos**, voltado para a disciplina de **Linguagens Formais e Autômatos**.

---

## 🚀 Funcionalidades

- Leitura de gramática livre de contexto a partir de arquivo `.txt`
- Execução do algoritmo CYK
- Geração da tabela CYK completa
- Saída formatada em arquivo de texto
- Implementação em C++ moderno (C++17)

---

## 📁 Estrutura do Projeto
``` text
.
├── cyk.cpp # Código-fonte principal
├── glc.txt # Arquivo de gramática de exemplo
└── README.md # Documentação do projeto
```

---

## 📄 Formato da Gramática

A gramática deve estar na **Forma Normal de Chomsky** e seguir o padrão:

S -> AB | BC
A -> BA | a
B -> CC | b
C -> AB | a


### Observações:
- Produções separadas por `|`
- Terminais representados por símbolos simples (`a`, `b`)
- Espaços obrigatórios ao redor do `->`

---

## ▶️ Como Compilar

No terminal, execute:

```bash
g++ -std=c++17 cyk.cpp -o cyk
```

## ▶️ Como Executar
```bash
./cyk glc.txt palavra saida.txt
```
Exemplo:
```bash
./cyk glc.txt baaba resultado.txt
```

## 📤 Saída
- A tabela CYK é escrita no arquivo informado

- A última linha contém a palavra analisada

- Cada célula apresenta o conjunto de variáveis que derivam aquela substring

## 🛠 Tecnologias Utilizadas
- C++

- STL (map, set, vector, string)

- Compilador g++

## 🎓 Contexto Acadêmico
Projeto desenvolvido como exercício prático para reforçar conceitos de:

- Gramáticas Livres de Contexto

- Forma Normal de Chomsky

- Algoritmos de reconhecimento de linguagens formais

## 👨‍💻 Autor
Henrique Soares
Graduando em Ciência da Computação — UFLA
GitHub: https://github.com/henriqueecss