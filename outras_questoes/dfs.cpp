#include <bits/stdc++.h>

#define DEBUG if(0)

typedef std::vector<int> vi;
typedef std::vector<bool> vb;

void make_graph(std::vector<vi> &graph, int edges);
void dfs(int start, vb visited, std::vector<vi> graph);

int main()
{
    int edges, start;
    std::vector<vi> graph;

    std::cin >> edges;
    std::cin >> start;

    vb visited(edges);
    graph.resize(edges);

    make_graph(graph, edges);
    
    dfs(start, visited, graph);

    return 0;
}
void dfs(int start, vb visited, std::vector<vi> graph)
{
    std::stack<int> staq;
    int dista, x, temp; 
    staq.push(start);

    visited[start] = true;

    while(!staq.empty()) {
	
	dista = staq.top();

	for(auto i = graph[dista].size(); i--;){
	    
	    x = graph[dista][i];

	    if(!visited[x]){
		
		visited[x] = true;
	    	staq.push(x);


		temp++;
	
		break;
	    }
	}

	if(!temp){

	    std::cout << staq.top() << std::endl;
	    staq.pop();

	}

	temp = 0;
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

