#include <iostream>
#include <vector>

using namespace std;

void espacio() {
    cout << endl;
}

int distanciaMinima(vector <int> distancia, vector<bool> visitado) {

    int minimo;
    int indice;
    minimo = 999999999;
    indice = 0;

    for (int i = 0; i < distancia.size(); i++) {
        if (visitado[i] == false && distancia[i] <= minimo) {
            minimo = distancia[i];
            indice = i;
        }
    }

    return indice;
}

void dijkstra(vector <vector <int>> matriz, int nodo) {

    vector<int> distancia;
    vector<bool> visitado;

    for (int i = 0; i < matriz.size(); i++) {
        distancia.push_back(999999999);
        visitado.push_back(false);
    }

    distancia[nodo] = 0;

    for (int i = 0; i < matriz.size(); i++) {
        int minimo = distanciaMinima(distancia, visitado);
        visitado[minimo] = true;
        for (int j = 0; j < matriz.size(); j++) {
            if (!visitado[j] && matriz[minimo][j] && distancia[minimo] != 999999999 && distancia[minimo] + matriz[minimo][j] < distancia[j]) {
                distancia[j] = distancia[minimo] + matriz[minimo][j];
            }
        }
    }

    for (int i = 0; i < matriz.size(); i++) {
        char letraOrigen = 65 + i;
        char letraDestino = 65 + nodo;
        if (distancia[i] > 0) {
            cout << "node " << nodo + 1 << " to node " << i + 1 << " : " << distancia[i] << endl;
        }
    }
}

void edsgerDijkstra(vector <vector <int>> matriz) {

    cout << "Dijkstra :" << endl;

    for (int i = 0; i < matriz.size(); i++) {
        dijkstra(matriz, i);
    }
}

void imprimirMatriz(vector <vector <int>> matriz) {
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[i].size(); j++) {
            cout << matriz[i][j] << " ";
        }
        espacio();
    }
}

void floydWarshall(vector <vector <int>> matriz) {

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
    vector <vector <int>> matriz;
    menosUno = 999999999;

    cin >> n;
    
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

    edsgerDijkstra(matriz);
    floydWarshall(matriz);

    return 0;
}