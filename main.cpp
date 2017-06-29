#include <iostream>
#include <iostream>
#include <fstream>
#include<queue>


using namespace std;

void imprime_vetor(int tamanho, int *vetor){
    for(int i = 0; i < tamanho; i++){
        cout << vetor[i] << " ";
    }
}

void imprime_matriz(int linha, int coluna, int **matriz){
    for (int i = 0; i < linha; i++){
		for (int j = 0; j < coluna; j++)
			cout << matriz[i][j] << " ";
        cout << endl;
	}
	cout << endl;
}

int busca_caminho(int qnt_vertice, int *caminho, int *visitado, queue<int> &fila,
    int s, int t, int **residual){

    bool existe_caminho = false;

    for(int i = 0; i < qnt_vertice; i++){
        caminho[i] = -1;
        visitado[i] = 0;
    }
    fila.push(s);
    visitado[s] = 1;

    while(!fila.empty()){
        int vertice = fila.front();
        fila.pop();
        for(int i = 0; i < qnt_vertice; i++){
            if(residual[vertice][i] > 0 && (!visitado[i])){
                caminho[i] = vertice;
                fila.push(i);
                visitado[i] = 1;
            }
        }

    }
    if(visitado[t])
        existe_caminho = true;
    return existe_caminho;
}

int retorna_fluxo_max(int qnt_vertice, int **residual, int *caminho,
    int t, int s, int *visitado, queue<int> &fila){
    int fluxo_max = 0;


    while(busca_caminho(qnt_vertice, caminho, visitado, fila, s, t, residual)){
        int fluxo = 999999999;
        int v = 0;

        for(int i = t; i != s; i = caminho[i]){
            v = caminho[i];
            if(residual[v][i] < fluxo){
                //fluxo = min(fluxo, residual[v][i])
                fluxo = residual[v][i];
            }
        }

        for(int i = t; i != s; i = caminho[i]){
            v = caminho[i];
            residual[v][i] -= fluxo;
            residual[i][v] += fluxo;
        }
        for(int i = 0; i < qnt_vertice; i++){
            for(int j = 0; j< qnt_vertice; j++){
                cout<<residual[i][j] << " ";
            }
            cout <<endl;
        }
        cout<< endl;
        fluxo_max += fluxo;
    }
    return fluxo_max;
}



int main() {

    int qnt_vertice = 0;
    int qnt_aresta = 0;


    //lê dados de entrada
    ifstream file("input.txt");
    file >> qnt_vertice;
    cout << qnt_vertice << endl;
    file >> qnt_aresta;
    cout << qnt_aresta<< endl;
    int *custo = new int[qnt_aresta];
    for(int j = 0; j < qnt_aresta; j++){
        file >> custo[j];
    }
    //imprime_vetor(qnt_aresta, custo);
    cout <<endl;
    //cria a matriz de incidência
    int **N = new int*[qnt_vertice];    // cria primeiro as linhas
    for(int i = 0; i < qnt_vertice; i++)
        N[i] = new int[qnt_aresta];      //cria as colunas

    //Recebe matriz de adjacência do arquivo
	for (int i = 0; i < qnt_vertice; i++){
		for (int j = 0; j < qnt_aresta; j++)
			file >> N[i][j];
	}
	cout << endl;
	//imprime_matriz(qnt_vertice, qnt_aresta, N);

	int **adjacencia = new int*[qnt_vertice];
	for(int i = 0; i < qnt_vertice; i++){
        adjacencia[i] = new int[qnt_vertice];
	}

	for(int i = 0; i < qnt_vertice-1; i++){
        for(int j = 0; j < qnt_aresta; j++){
            if(N[i][j] == -1){
                for(int k = 0; k < qnt_vertice; k++){
                    if(N[k][j] == 1){
                        adjacencia[i][k] = custo[j];
                    }
                }
            }
        }
	}
	cout << endl;
	//imprime_matriz(qnt_vertice, qnt_vertice, adjacencia);

    int s = 0;              //origem
    int t = qnt_vertice-1;  //destino
    queue <int> fila;
    int *visitado = new int[qnt_vertice];
    int *caminho = new int[qnt_vertice];
    int **residual = new int*[qnt_vertice];
    for(int i = 0; i < qnt_vertice; i++)
        residual[i] = new int[qnt_vertice];

    for(int i = 0; i < qnt_vertice; i++){
        for(int j = 0; j < qnt_vertice; j++)
            residual[i][j] = adjacencia[i][j];
    }
    cout << endl;
    //imprime_matriz(qnt_vertice, qnt_vertice, residual);
    int fluxo_maximo = retorna_fluxo_max(qnt_vertice, residual, caminho, t, s, visitado, fila);
    cout << "fluxo maximo: "<< fluxo_maximo <<endl;

    return 0;
}



