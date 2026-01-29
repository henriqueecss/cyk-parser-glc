#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

using Rule = pair<string, string>; // Uma regra no formato {variável, produção}

map<string, set<string>> parseGrammar(const string& fileName);
vector<vector<set<string>>> applyCYK(const vector<string>& word, const map<string, set<string>>& grammar);
void writeOutput(const vector<vector<set<string>>>& table, const vector<string>& word, const string& outputFile);

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Uso: ./cyk glc.txt palavra saida.txt\n";
        return 1;
    }

    string grammarFile = argv[1];
    string word = argv[2];
    string outputFile = argv[3];

    // Processa gramática
    auto grammar = parseGrammar(grammarFile);

    // Converte a palavra para um vetor de strings
    vector<string> inputWord(word.size());
    for (size_t i = 0; i < word.size(); i++) {
        inputWord[i] = string(1, word[i]);
    }

    // Aplica o algoritmo CYK
    auto table = applyCYK(inputWord, grammar);

    // Gera a saída
    writeOutput(table, inputWord, outputFile);

    return 0;
}

// Função que lê a gramática do arquivo
map<string, set<string>> parseGrammar(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Erro ao abrir o arquivo da gramática.\n";
        exit(1);
    }

    map<string, set<string>> grammar;
    string line;

    while (getline(file, line)) {
        size_t arrowPos = line.find("->");
        if (arrowPos == string::npos) {
            cerr << "Erro no formato das regras da gramática.\n";
            exit(1);
        }

        string variable = line.substr(0, arrowPos - 1);
        string production = line.substr(arrowPos + 3);

        stringstream ss(production);
        string rule;
        while (getline(ss, rule, '|')) {
            grammar[variable].insert(rule);
        }
    }

    return grammar;
}

vector<vector<set<string>>> applyCYK(const vector<string>& word, const map<string, set<string>>& grammar) {
    size_t n = word.size();
    vector<vector<set<string>>> table(n, vector<set<string>>(n));

    // Preenche a primeira linha da tabela (linha 1, produções unitárias)
    for (size_t i = 0; i < n; ++i) {
        for (const auto& [lhs, productions] : grammar) {
            if (productions.count(word[i])) {
                table[0][i].insert(lhs); // Variável que deriva diretamente o terminal
            }
        }
    }

    // Preenche o restante da tabela
    for (size_t row = 1; row < n; ++row) {           // Cada linha
        for (size_t col = 0; col < n - row; ++col) { // Cada coluna na linha
            for (size_t k = 0; k < row; ++k) {       // Divide a subsequência em duas partes
                
                const auto& leftSet = table[k][col]; // Parte 1: esquerda
                const auto& rightSet = table[row - k - 1][col + k + 1]; // Parte 2: direita

                // Combina as produções das partes esquerda e direita
                for (const auto& left : leftSet) {
                    for (const auto& right : rightSet) {
                        string combined = left + right; // Combinação de variáveis

                        // Verifica se alguma regra da gramática deriva essa combinação
                        for (const auto& [lhs, productions] : grammar) {
                            if (productions.count(combined)) {
                                table[row][col].insert(lhs); // Adiciona variável ao nível
                            }
                        }
                    }
                }
            }
        }
    }

    return table;
}

// Função que grava a tabela CYK no arquivo de saída
void writeOutput(const vector<vector<set<string>>>& table, const vector<string>& word, const string& outputFile) {
    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Erro ao criar o arquivo de saída.\n";
        exit(1);
    }

    // Escreve a tabela de cima para baixo (linha de saída invertida)
    size_t n = word.size();
    for (size_t row = n; row > 0; --row) {
        for (size_t col = 0; col < n - row + 1; ++col) {
            const auto& cell = table[row - 1][col];
            if (!cell.empty()) {
                outFile << "{";
                for (auto it = cell.begin(); it != cell.end(); ++it) {
                    if (it != cell.begin()) outFile << ",";
                    outFile << *it;
                }
                outFile << "}";
            } else {
                outFile << "{}";
            }
            if (col < n - row) {
                outFile << " ";
            }
        }
        outFile << "\n";
    }

    // Escreve a palavra na última linha
    for (const auto& w : word) {
        outFile << w << " ";
    }
    outFile << "\n";
}