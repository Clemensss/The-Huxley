#include <bits/stdc++.h>

#define DEBUG if(0)

typedef std::vector<int> vi;
typedef std::vector<bool> vb;

void make_graph(std::vector<vi> &graph, int edges);
void bfs(int start, vb visited, std::vector<vi> graph);

int main()
{
    int edges, start;
    std::vector<vi> graph;

    std::cin >> edges;
    std::cin >> start;

    vb visited(edges);
    graph.resize(edges);

    make_graph(graph, edges);
    
    bfs(start, visited, graph);

    return 0;
}

void bfs(int start, vb visited, std::vector<vi> graph)
{
    std::queue<int> q;
    int deq, x;

    q.push(start);

    std::cout << start << std::endl;
    visited[start] = true;

    while(!q.empty()){
	
	deq = q.front();
	q.pop();

	for(int i = graph[deq].size(); i--;){
	    
	    x = graph[deq][i];

	    if(!visited[x]){

		visited[x] = true;
		std::cout << x << std::endl;
		q.push(x);

	    }

	}
    }
}

void make_graph(std::vector<vi> &graph, int edges)
{
    int edge, con, size;

    size = edges;

    while(scanf("%d %d", &edge, &con) != EOF){

	DEBUG std::cin >> edge;
	DEBUG std::cin >> con;
	graph[edge].push_back(con);

    }

    DEBUG {for(int i = 0; i < size; i++) {
	    std::cout << "start\n";
	    int size_aux = (int)graph[i].size();

	    std::cout << i << ": ";

	    for(int j = 0; j < size_aux; j++) {
		    std::cout << graph[i][j] << " ";
	    }

	    std::cout << std::endl;
    }}

}

