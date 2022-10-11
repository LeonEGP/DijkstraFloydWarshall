#include <iostream>
#include <vector>

using namespace std;

void espacio() {
    cout << endl;
}

void imprimirMatriz(vector <vector <int>> matriz) {
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[i].size(); j++) {
            cout << matriz[i][j] << " ";
        }
        espacio();
    }
}

void floyd(vector <vector <int>> matriz) {
    cout << "Floyd :" << endl;
    vector <vector <int>> distancia = matriz;
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz.size(); j++) {
            for (int k = 0; k < matriz.size(); k++) {
                if (distancia[j][i] + distancia[i][k] < distancia[j][k]) {
                    distancia[j][k] = distancia[j][i] + distancia[i][k];
                }
            }
        }
    }
    imprimirMatriz(distancia);
}

int main() {
    int n;
    int menosUno;
    menosUno = 999999999;
    cin >> n;
    vector <vector <int>> matriz;
    for (int i = 0; i < n; i++) {
        vector <int> auxiliar;
        for (int j = 0; j < n; j++) {
            int temporal;
            cin >> temporal;
            if (temporal < 0) {
                auxiliar.push_back(menosUno);
            }
            else {
                auxiliar.push_back(temporal);
            }
        }
        matriz.push_back(auxiliar);
    }
    floyd(matriz);
    return 0;
}