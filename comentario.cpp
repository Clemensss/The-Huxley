#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair 
#define MAX_SIZE (1 << 20)
#define READ(x) cin >> x;
#define PRT(x) cout << x << endl;
#define REP(i, n) for(i = 0; i < n; i++)
#define REP1(i, n) for(i = 1; i < n; i++)
#define REVREP(i, n) for(i = n - 1; i >= 0; i--)
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define DASH() cout << "-------------------------" << endl;

typedef long long lli;

/*
 * define tipo "vi" como um vetor de inteiros
 * e vvi como um vetor de vetores
 * e vb como um vetor de tipo boleano
 */

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;

/* declara a lista de elementos visitados,
 * a lista de adjacencia, q eh uma representacao
 * das coneccoes entre os vertices do grafo
 */

vb visited;
vi dist;
vvi adjList;

/*inicia a lista de visitados, ou seja apaga
e realoca o tamanho desejado*/
void initVisited(int size)
{
	visited.clear();
	visited.resize(size);
}

/*mesma coisa com a lista que define a distancia entre
o starting point e o node em questao*/
void initDist(int size)
{
	dist.clear();
	dist.resize(size);
}

/* inicia grafo, que é composto de um lista de 
 * adjacencia e as listas de visitado e de
 * "distancias"
 */

void initGraph(int size)
{
	initVisited(size);
	initDist(size);

	adjList.clear();
	adjList.resize(size);
}

//printa os elementos com o uso de dois fors e duas variaveis i e j 
void printGraph()
{
	int size = (int)adjList.size();

	for(int i = 0; i < size; i++) {

		int size_aux = (int)adjList[i].size();
		cout << i << ": ";

		for(int j = 0; j < size_aux; j++) {
			cout << adjList[i][j] << " ";
		}

		cout << endl;
	}

	DASH();
}

//mesma coisa com a lista de distancia
void printDist()
{
	int size = (int)dist.size();

	for(int i = 0; i < size; i++) {
		cout << i << ": " << dist[i] << endl;
	}

	DASH();
}

/*                    
                     ----Breadth first search-----
    
     Conceito:

	   Eh uma busca que se ocorre escolhendo um numero arbitrario 
	do grafo como posicao inicial, e a partir dele buscar todos 
	os elementos a ele conectados. Os elementos ainda nao 
	visitados sao marcados como visitados no vetor boleano, 
	quando todos sao visitados, o proximo elemento q se inicia a 
	busca eh o primeiro item da queue. Os elementos visitados sao 
	guardados numa queue (no fim), e todo elemento q se 
	comeca a busca sofre um pop e eh dequeued. A busca para 
	quando a lista estiver vazia.


    Implementacao:

	   Se inicia uma queue, e o primeiro elemento a ser colocado 
	eh o “from”, ou seja, o elemento q se inicia a busca. Ele 
	eh dequeued e o seu valor eh guardado na variavel de mesmo 
	nome. Um for comeca a procura dos x que estao presentes no 
	vetor de index “dequeued”, ou seja os elementos a ele 
	conectados, para cada elemento ainda nao visitado, se da 
	um push dele pra queue, e eh marcado como verdade na visited. 
	Quando o for terminar, se pega o front da queue, e usa ele 
	como inicio da busca, e o mesmo processo se repete,
	ate que a lista esteja vazia, ou seja, todos os elementos 
	visitados.

*/

void bfs(int from)
{
	initVisited((int)adjList.size());
	initDist((int)adjList.size());
	
	dist[from] = 0;	
	visited[from] = true;

	queue<int> q;
	q.push(from);
	
	cout << from << " -> ";

	while(!q.empty()) {

		int dequeued = q.front(); q.pop();
		
		for(auto x : adjList[dequeued]) {

			if(!visited[x]) {

				visited[x] = true;
				q.push(x);
				dist[x] = dist[dequeued] + 1;

				cout << x << " -> ";

			}
		}
	}

	cout << endl;
}

/*

             ------ Depth first search --------- 

    Conceito:

	   Se busca cada elemento ate o “fundo”. Ou seja, a cada
	elemento visitado, se faz uma busca dos nodes a ele 
	conectados, se algum ainda nao foi visitado (o original 
	eh adicionado a um stack) esse se torna o novo elemento 
	inicial da pesquisa, e se explora os seus nodes, e assim 
	sucessivamente. Quando o programa chega em um node “sem 
	saida”, ou seja, que nao tem mais nodes conectados nao 
	visitados, ele pega o primeiro elemento da stack, e 
	repete o processo, ate q a stack esteja vazia.

    Implementacao:

	   Se usa um “for” q transversa todos os elementos conectados 
	a from, se acha algum que nao foi visitado, ele adiciona o 
	elemento a stack, ou, nesse caso, faz um backtracking com 
	o elemento novo de argumento. Repetindo o processo ate q 
	todos os elementos forem visitados.

*/

void dfs(int from)
{
	cout << from << " -> ";
	visited[from] = true;

	for(auto x : adjList[from]) {
	
		if(!visited[x]) {

			dist[x] = dist[from] + 1;
			dfs(x); //baquitraqui

		}
	}
	
}

int main()
{
	int qnt_vertex, qnt_edges, start_search;
	int u, v;

	cin >> qnt_vertex >> qnt_edges;

	initGraph(qnt_vertex);

	while(qnt_edges--) {
		cin >> u >> v;
		adjList[u].pb(v);
	}

	printGraph();

	cin >> start_search;
	cout << "run dfs from: " << start_search << endl;

	dfs(start_search); cout << endl;

	printDist();

	cout << "run bfs from: " << start_search << endl;

	bfs(start_search);	

	printDist();

	return 0;
}
