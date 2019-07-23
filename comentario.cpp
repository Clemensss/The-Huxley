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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;

vb visited;
vi dist;
vvi adjList;

void initVisited(int size)
{
	visited.clear();
	visited.resize(size);
}

void initDist(int size)
{
	dist.clear();
	dist.resize(size);
}

void initGraph(int size)
{
	initVisited(size);
	initDist(size);

	adjList.clear();
	adjList.resize(size);
}

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

void printDist()
{
	int size = (int)dist.size();

	for(int i = 0; i < size; i++) {
		cout << i << ": " << dist[i] << endl;
	}

	DASH();
}

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

void dfs(int from)
{
	cout << from << " -> ";
	visited[from] = true;

	for(auto x : adjList[from]) {
	
		if(!visited[x]) {

			dist[x] = dist[from] + 1;
			dfs(x);

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
