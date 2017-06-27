#include <iostream>
#include <iostream>
#include <fstream>
#include<vector>


using namespace std;
/*

struct TipoAresta{
    int vertice_destino;
    int fluxo;
    int capacidade;
};


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

//adiciona uma aresta no vetor de aresta
void adiciona_aresta(int a, int b, int capacidade, int capacidade_reversa,
    int num_arestas_adicionadas, TipoAresta vetor_arestas[], vector<int> adj_vertices[]){

    vetor_arestas[num_arestas_adicionadas].vertice_destino = b;
    cout<<"destino = "<<vetor_arestas[num_arestas_adicionadas].vertice_destino<<endl;
    vetor_arestas[num_arestas_adicionadas].fluxo = 0;
    cout<<"fluxo = "<<vetor_arestas[num_arestas_adicionadas].fluxo<<endl;
    vetor_arestas[num_arestas_adicionadas].capacidade = capacidade;
    cout<<"capacidade = "<<vetor_arestas[num_arestas_adicionadas].capacidade<<endl;
    adj_vertices[a].push_back(num_arestas_adicionadas++);
   // cout<<adj_vertices[a];
     //###########################COMO PASSAR UM VECTOR POR PARÂMETRO E COMO IMPRIMIR ELE

    //add aresta reversa
    vetor_arestas[num_arestas_adicionadas].vertice_destino = a;
    vetor_arestas[num_arestas_adicionadas].fluxo = 0;
    vetor_arestas[num_arestas_adicionadas].capacidade = capacidade_reversa;
    adj_vertices[b].push_back(num_arestas_adicionadas++);
}

int dfs(int vertice_atual, int t, int fluxo_atual, int *visualizacao, int tempo,
    TipoAresta vetor_arestas[], vector<int> adj_vertices[]){

    if(vertice_atual == t) return fluxo_atual;
    visualizacao[vertice_atual] = tempo;
    for(int i 0: adj_vertices[vertice_atual]){
        if((visualizacao[vetor_arestas[i].vertice_destino < tempo]) &&
            (vetor_arestas[i].capacidade - vetor_arestas[i].fluxo) > 0){
                if(int a = dfs(vetor_arestas[i].vertice_destino, t,
                    min(fluxo_atual, vetor_arestas[i].capacidade - vetor_arestas[i].fluxo),
                     visualizacao, tempo, vetor_arestas, adj_vertices)){
                        vetor_arestas[i].fluxo += a;
                        vetor_arestas[i^1].fluxo -= a;
                        return a;
                    }
        }
    }
    return 0;
}


//retorna quanto de fluxo foi possível aumentar
int fluxo_a_ser_aumentado(int tempo, int s, int t, int *visualizacao,
    TipoAresta vetor_arestas[], vector<int> adj_vertices[]){

    int fluxo = 0;
    //enquanto tiver caminho aumentador, aumenta o fluxo
    while(int a = dfs(s, t, 9999999999, visualizacao, tempo, vetor_arestas, adj_vertices)){  //recebe vertice inicial , destino, fluxo passado até o momento
        fluxo += a;
        tempo++;
    }
    return fluxo;
}

*/

int main() {

    int qnt_vertice = 0;
    int qnt_aresta = 0;


    //lê dados de entrada
    ifstream file("entrada.txt");
    file >> qnt_vertice;
    cout << qnt_vertice << endl;
    file >> qnt_aresta;
    cout << qnt_aresta<< endl;
    int *c = new int[qnt_aresta];
    for(int j = 0; j < qnt_aresta; j++){
        file >> c[j];
    }
    //imprime_vetor(qnt_aresta, c);
    cout << endl;
    cout << endl;

    //cria a matriz de adjacência
    int **N = new int*[qnt_vertice];    // cria primeiro as linhas
    for(int i = 0; i < qnt_vertice; i++)
        N[i] = new int[qnt_aresta];      //cria as colunas

    //Recebe matriz de adjacência do arquivo
	for (int i = 0; i < qnt_vertice; i++){
		for (int j = 0; j < qnt_aresta; j++)
			file >> N[i][j];
	}
    int s = 0;
    int t = qnt_vertice-1;
	//imprime_matriz(qnt_vertice, qnt_aresta, N);
	//cout << endl;

	/*struct Aresta aresta;
    Aresta vetor_de_aresta[qnt_aresta]; //cria uma lista contendo cada uma das aresta

    TipoAresta **lista_arestas = new TipoAresta*[qnt_aresta]();
    for(int i = 0; i < qnt_aresta; i++)
        lista_arestas[i] = new TipoAresta[qnt_aresta];

    */

    // cria vetor de arestas
    /*TipoAresta vetor_arestas[2*qnt_aresta]; // guarda a aresta em x e sua reversa em x+1

    //cada vertice tem uma lista de adjacencia
    vector <int> adj_vertices[2*qnt_vertice]; // guarda o inteiro que mosta a posição no vetor_aresta
    int *visualizacao = new int[qnt_aresta](); //visualizaçãod dos vertices

    int num_arestas_adicionadas = 0;
    int origem = 0;
    int destino = 0;
    int capacidade = 0;
    for(int j = 0; j < qnt_aresta; j++){
        for(int i = 0; i < qnt_vertice; i++){
            if(N[i][j] == 1){
                origem = j;
                destino = i;
                capacidade = c[j];
                adiciona_aresta(origem, destino, capacidade, 0, num_arestas_adicionadas, vetor_arestas, adj_vertices);
            }
        }
    }
    int tempo = 1;
    int fluxo = fluxo_a_ser_aumentado(tempo, s, t, visualizacao, vetor_arestas, adj_vertices);

*/
    return 0;
}



