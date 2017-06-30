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

void marca_caminho(int qnt_vertice, int qnt_aresta, int *caminho_aresta,
    int *caminho, int **N, int *novo_custo, int **residual){
    int vertice_anterior = -1;
    for(int k = qnt_vertice - 1; k >= 0; k--){
        vertice_anterior = caminho[k];
        if(vertice_anterior != -1){
            for(int j = 0; j < qnt_aresta; j++){
                if((N[k][j] == 1) && (N[vertice_anterior][j] == -1)){
                    caminho_aresta[j] = 1;
                }
            }
        }
    }
    cout<<"[";
    for(int j = 0; j < qnt_aresta; j++){
        cout<< caminho_aresta[j] << " ";
    }
    cout<<"]"<<endl;
    for(int i = 0; i < qnt_vertice-1; i++){
        for(int j = 0; j < qnt_aresta; j++){
            if(N[i][j] == -1){
                for(int k = 0; k < qnt_vertice; k++){
                    if(N[k][j] == 1){
                        if(caminho_aresta[j] == 1){
                            novo_custo[j] = residual[i][k];
                        }
                    }
                }
            }
        }
	}
	cout<<"[";
	for(int j = 0; j < qnt_aresta; j++){
        cout<< novo_custo[j] << " ";
    }
}

int busca_caminho(int qnt_vertice, int qnt_aresta, int *caminho, int *visitado, queue<int> &fila,
    int s, int t, int **residual, int *caminho_aresta, int **N, int *novo_custo, int *custo, bool corte){

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
    else{
    }
    cout<<endl;

    marca_caminho(qnt_vertice, qnt_aresta, caminho_aresta, caminho, N, novo_custo, residual);
    cout<<"]"<<endl;
    cout<<"[";
	for(int j = 0; j < qnt_aresta; j++){
        cout<< custo[j] << " ";
    }
    cout<<"]"<<endl;
    return existe_caminho;
}

int retorna_fluxo_max(int qnt_vertice, int qnt_aresta, int **residual, int *caminho,
    int t, int s, int *visitado, queue<int> &fila, int *caminho_aresta, int **N, int *novo_custo, int *custo, bool corte){

    int fluxo_max = 0;

    while(busca_caminho(qnt_vertice, qnt_aresta, caminho, visitado, fila, s, t, residual, caminho_aresta, N, novo_custo, custo, corte)){
        int fluxo = 999999999;
        int v = 0;

        for(int i = t; i != s; i = caminho[i]){
            v = caminho[i];
            if(residual[v][i] < fluxo){
                fluxo = residual[v][i];
            }
        }

        for(int i = t; i != s; i = caminho[i]){
            v = caminho[i];
            residual[v][i] -= fluxo;
            residual[i][v] += fluxo;
        }
        fluxo_max += fluxo;
        cout<<endl;
    }

    return fluxo_max;
}



int main() {

    int qnt_vertice = 0;
    int qnt_aresta = 0;


    //lê dados de entrada
    ifstream file("entrada.txt");
    file >> qnt_vertice;
    file >> qnt_aresta;
    int *custo = new int[qnt_aresta];
    for(int j = 0; j < qnt_aresta; j++){
        file >> custo[j];
    }
    //imprime_vetor(qnt_aresta, custo);
    //cria a matriz de incidência
    int **N = new int*[qnt_vertice];    // cria primeiro as linhas
    for(int i = 0; i < qnt_vertice; i++)
        N[i] = new int[qnt_aresta];      //cria as colunas

    //Recebe matriz de incidência do arquivo
	for (int i = 0; i < qnt_vertice; i++){
		for (int j = 0; j < qnt_aresta; j++)
			file >> N[i][j];
	}
	//imprime_matriz(qnt_vertice, qnt_aresta, N);

	int **adjacencia = new int*[qnt_vertice];
	for(int i = 0; i < qnt_vertice; i++){
        adjacencia[i] = new int[qnt_vertice];
	}

	for(int i = 0; i < qnt_vertice; i++){
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
     bool corte = false;
    int *caminho_aresta = new int[qnt_aresta]();
    int *novo_custo = new int[qnt_aresta]();
    int fluxo_maximo = retorna_fluxo_max(qnt_vertice, qnt_aresta, residual,
    caminho, t, s, visitado, fila, caminho_aresta, N, novo_custo, custo, corte);
    cout<<endl;
    cout << "fluxo maximo: "<< fluxo_maximo <<endl;
    int *corte_minimo = new int[qnt_aresta]();
    int *conjuntoA = new int[qnt_vertice];
    int *conjuntoB = new int[qnt_vertice];

    int k = 0;
    for(int i= 0; i < qnt_vertice; i++){
        if(visitado[i] == 1){
            conjuntoA[k] = i;
             conjuntoB[i] = -1;
        }
        else{
            conjuntoB[k] = i;
            conjuntoA[i] = -1;
        }
        k++;
    }
    for(int i = 0; i < qnt_vertice; i++){
        if(conjuntoA[i] != -1){
            for(int j = 0; j < qnt_aresta; j++){
                if(N[conjuntoA[i]][j] == -1){
                    for(int x = 0; x < qnt_vertice; x++){
                        if(N[x][j] == 1){
                            if(x == conjuntoA[x])
                                continue;
                            else
                                corte_minimo[j] = 1;
                        }
                    }
                }
            }
        }
    }
	cout<<"Corte mínimo: [" ;
	for(int j = 0; j < qnt_aresta; j++){
        cout << corte_minimo[j] << " ";
	}
	cout<<"]";


    return 0;
}



