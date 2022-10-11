//Programa que: Implementa el Algoritmo Dijkstra y el Algoritmo Floyd-Warshall.
//Programadores: León Emiliano García Pérez [A00573074] y Carla Morales López [A01639225].
//Fecha de entrega: Martes 11 de Octubre de 2022.

//Inclusión de librerías.
#include <iostream>
#include <vector>

//Ajuste a estandar.
using namespace std;

//Función que imprime un espacio en consola, no recibe valores, no tiene valor de retorno.
void espacio() { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función. 
    cout << endl;
}

//Función que calcula la Distancia Mínima del nodo que no está presente dentro del vector de booleanos que refiere a los nodos visitados; recibe un vector de enteros que refiere a las distancias, y un vector de booleanos que refiere a los nodos visitados, retorna el entero índice.
int distanciaMinima(vector <int> distancia, vector<bool> visitado) { //Complejidad Computacional: O(n), siendo n la longitud del vector de distancias, donde dicha n es el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 

    //Declaración de variables de la función. 
    int minimo;
    int indice;
    minimo = 999999999;
    indice = 0;

    //Ciclo for anidado dentro de otro ciclo for, que implementa la lógica para la determinación del índice que retorna la función.
    for (int i = 0; i < distancia.size(); i++) { //Complejidad Computacional: O(n), siendo n la longitud del vector de distancias, donde dicha n es el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
        if (visitado[i] == false && distancia[i] <= minimo) {
            minimo = distancia[i];
            indice = i;
        }
    }

    //Se retorna el entero índice. 
    return indice;
}

//Función que implementa el Algoritmo Dijkstra, recibe un vector de vectores de enteros que es la Matriz de Adyacencia y un entero que es el nodo desde el cual se analizan las distancias, imprime la distancia de este nodo a los otros nodos, no tiene valor de retorno. 
void dijkstra(vector <vector <int>> matriz, int nodo) { //Complejidad Computacional: O(n^2), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 

    //Declaración de variables de la función. 
    vector<int> distancia;
    vector<bool> visitado;

    //Ciclo for que llena los vectores con valores por defecto.
    for (int i = 0; i < matriz.size(); i++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
        distancia.push_back(999999999);
        visitado.push_back(false);
    }

    distancia[nodo] = 0; //Se omite el nodo el cual se analiza. 

    //Ciclo for anidado dentro de otro ciclo for, que implementa la lógica para la determinación de distancias. Complejidad Computacional: O(n^2), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
    for (int i = 0; i < matriz.size(); i++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
        int minimo = distanciaMinima(distancia, visitado);
        visitado[minimo] = true;
        for (int j = 0; j < matriz.size(); j++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
            if (!visitado[j] && matriz[minimo][j] && distancia[minimo] != 999999999 && distancia[minimo] + matriz[minimo][j] < distancia[j]) {
                distancia[j] = distancia[minimo] + matriz[minimo][j];
            }
        }
    }

    //Ciclo for que imprime la distancia para cada nodo a partir del nodo a analizar que se manda como parámetro en la función. 
    for (int i = 0; i < matriz.size(); i++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
        if (distancia[i] > 0) {
            cout << "node " << nodo + 1 << " to node " << i + 1 << " : " << distancia[i] << endl;
        }
    }
}

//Función que realiza el Algoritmo de Dijkstra para cada nodo de la Matriz de Adyacencia, recibe un vector de vectores de enteros que es la Matriz de Adyacencia, imprime la distancia de cada nodo para los otros nodos restantes, no tiene valor de retorno.
void edsgerDijkstra(vector <vector <int>> matriz) { //Complejidad Computacional: O(n^3), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. Debido a que se ejecuta el Algoritmo de Dijkstra [Complejidad Computacional de O(n^2)] para cada n, logrando así dicha complejidad.

    //Se muestra qué algoritmo se está desarrollando. 
    cout << "Dijkstra :" << endl;

    //Ciclo for que ejecuta el Algoritmo de Dijkstra, para cada nodo de la Matriz de Adyacencia. Como la función es de Complejidad O(n^2), dentro de un ciclo for de Complejidad O(n), se logra una Complejidad Computacional de O(n^3).
    for (int i = 0; i < matriz.size(); i++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
        dijkstra(matriz, i); //Complejidad Computacional: O(n^2), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia.
    }
}

//Función que imprime una Matriz, recibe un vector de vectores de enteros, que es la Matriz, la imprime y no tiene valor de retorno.
void imprimirMatriz(vector <vector <int>> matriz) { //Complejidad Computacional: O(n^2), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
    for (int i = 0; i < matriz.size(); i++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
        for (int j = 0; j < matriz[i].size(); j++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia.  
            cout << matriz[i][j] << " ";
        }
        espacio();
    }
}

//Función que implementa el Algoritmo Floyd-Warshall, recibe un vector de vectores de enteros que es la Matriz de Adyacencia, e imprime la Matriz de Distancia más corta, no tiene valor de retorno.
void floydWarshall(vector <vector <int>> matriz) { //Complejidad Computacional: O(n^3), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia.  

    //Se muestra qué algoritmo se está desarrollando. 
    cout << "Floyd :" << endl; 
    //Declaración de variables de la función. 
    vector <vector <int>> distancia = matriz;

    //Ciclo for anidado dentro de otro ciclo for anidado dentro otro ciclo for, ejecuta la lógica correspondienta al algoritmo Floyd-Warshall. Complejidad Computacional: O(n^3), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
    for (int i = 0; i < matriz.size(); i++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
        for (int j = 0; j < matriz.size(); j++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
            for (int k = 0; k < matriz.size(); k++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
                if (distancia[j][i] + distancia[i][k] < distancia[j][k]) {
                    distancia[j][k] = distancia[j][i] + distancia[i][k];
                }
            }
        }
    }

    //Se imprime la Matriz de Distancia más corta. 
    imprimirMatriz(distancia); //Complejidad Computacional: O(n^2), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
}

//Función main de ejecución del programa, no recibe valores, retorna un valor 0 al finalizar la ejecución.
int main() { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función. Dentro de esta ejecución de una sola instancia [constante], se presenta un ciclo for anidado dentro de otro ciclo for [Complejidad Computacional O(n^2)], siendo n un valor aún no definido, pero que espera ser el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 

    //Inicia programa.
    //Declaración e inicialización de variables.
    int n;
    int menosUno;
    vector <vector <int>> matriz;
    menosUno = 999999999;

    //Se recibe el valor n, que define el tamaño nxn de la Matriz de Adyacencia. 
    cin >> n;

    //Ciclo for anidado dentro de otro ciclo for, permite llenar la Matriz de Adyacencia. Complejidad Computacional: O(n^2), siendo n el valor de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
    for (int i = 0; i < n; i++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
        vector <int> auxiliar;
        for (int j = 0; j < n; j++) { //Complejidad Computacional: O(n), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. 
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

    //Implementación del Algoritmo de Edsger Wybe Dijkstra.
    edsgerDijkstra(matriz); //Complejidad Computacional: O(n^3), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia. Debido a que se ejecuta el Algoritmo de Dijkstra [Complejidad Computacional de O(n^2)] para cada n, logrando así dicha complejidad.
    //Implementación del Algoritmo de Robert W. Floyd y Stephen Warshall.
    floydWarshall(matriz);  //Complejidad Computacional: O(n^3), siendo n el valor de longitud de cada n arreglo [vector (de longitud n)] dentro de la Matriz de Adyacencia.  

    //Termina programa.
    return 0;
}
