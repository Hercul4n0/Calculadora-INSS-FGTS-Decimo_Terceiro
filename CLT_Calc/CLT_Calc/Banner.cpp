#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Banner.h"

void BrasilBanner() {
    using namespace std;

    // Texto original (altura = 8 linhas, largura ~ 63 colunas)
    vector<string> art = {
"  /$$$$$$ /$$   /$$$$$$$$        /$$$$$$          /$$         ",
" /$$__  $| $$  |__  $$__/       /$$__  $$        | $$         ",
"| $$  \\__| $$     | $$         | $$  \\__/ /$$$$$$| $$ /$$$$$$$",
"| $$     | $$     | $$         | $$      |____  $| $$/$$_____/ ",
"| $$     | $$     | $$         | $$       /$$$$$$| $| $$      ",
"| $$    $| $$     | $$         | $$    $$/$$__  $| $| $$      ",
"|  $$$$$$| $$$$$$$| $$         |  $$$$$$|  $$$$$$| $|  $$$$$$$",
" \\______/|________|__/          \\______/ \\_______|__/\\_______/  "
    };

    const string GREEN = "\033[38;5;34m";
    const string YELLOW = "\033[38;5;226m";
    const string BLUE = "\033[38;5;21m";
    const string WHITE = "\033[97m";
    const string RESET = "\033[0m";

    int rows = art.size();
    int cols = art[0].size();

    // Centro aproximado do texto
    float cx = cols / 2.0f;
    float cy = rows / 2.0f;

    // Raio do círculo azul
    float circleRadius = min(rows, cols) * 0.18f;

    // Dimensão do losango (baseado na distância de Manhattan)
    float diamondSize = min(rows, cols) * 0.32f;

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {

            char c = art[y][x];

            if (c == ' ') {
                cout << " ";
                continue;
            }

            // Distância para o losango
            float diamondDist = fabs(x - cx) + fabs(y - cy);

            // Distância para o círculo
            float circleDist = sqrt(pow(x - cx, 2) + pow(y - cy, 2));

            // Escolha de cor pela posição
            string color;

            if (circleDist <= circleRadius * 0.55) {
                // Região interna ? círculo azul
                color = BLUE;
            }
            else if (diamondDist <= diamondSize) {
                // Região intermediária ? losango amarelo
                color = YELLOW;
            }
            else {
                // Área externa ? fundo verde
                color = GREEN;
            }

            cout << color << c << RESET;
        }
        cout << "\n";
    }
}