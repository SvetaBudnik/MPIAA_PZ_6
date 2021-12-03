#include<iostream>
#include<string>
#include <vector>
#include<fstream>
#include <queue>

using namespace std;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

static class GraphManager {
public:

	//Initilize matrix-type graph
	static void init_graph(Graph& graph, int n) {
		graph.resize(n);
	}

	//Read graph from file
	static void input_graph(Graph& graph, string filename) {
		fstream fin;
		fin.open(filename, ios::in);
		input_graph(graph, fin);
		fin.close();
	}

	//Read graph from istream
	static void input_graph(Graph& graph, std::istream& in) {
		int n, m, a, b, weight;
		in >> n >> m;
		init_graph(graph, n);
		for (int i = 0; i < m; ++i) {
			in >> a >> b >> weight;
			graph[a - 1].push_back(Edge(b - 1,weight));
			graph[b - 1].push_back(Edge(a - 1, weight));
		}
	}

	//Output graph to file
	static void print_graph(Graph& graph, string filename) {
		fstream fout;
		fout.open(filename, ios::out);
		print_graph(graph, fout);
		fout.close();
	}

	//Output graph to ostream
	static void print_graph(Graph& graph, std::ostream& out) {
			for (int i = 0; i < graph.size(); ++i) {
				out << i + 1 << ":";
				for (int j = 0; j < graph[i].size(); ++j) {
					out << " (" << graph[i][j].first + 1<<","<<graph[i][j].second<<")";
				}
				out << endl;
			}
		
	}

	//Prim's algorithm for minimum spanning tree
	static void algorithm_Prim(Graph& graph, Graph& result, int start) {
		init_graph(result, graph.size());
		auto cmp{ 
			[](pair<int, Edge> l, pair<int, Edge> r) {return (l.second.second > r.second.second); } 
		};
		//Stores start vertex and pair of end vertex and weight
		std::priority_queue<pair<int, Edge>, vector<pair<int, Edge>>, decltype(cmp)> edges(cmp);
		vector <bool> marked(graph.size(), false);
		marked[start] = true;
		bool allchecked = false;
		while (!allchecked) {
			allchecked = true;
			for (int k = 0; k < graph.size(); ++k) {
				if (marked[k]) {
					for (int j = 0; j < graph[k].size(); ++j) {
						if (!marked[graph[k][j].first]) {
							edges.push(pair<int, Edge>(k, graph[k][j]));
						}
					}
				}
				else {
					allchecked = false;
				}
			}
			if (edges.empty()) allchecked = true;
			bool edge_added = false;
			while (!edge_added && !edges.empty()) {
				if (!marked[edges.top().second.first]) {
					edge_added = true;
					marked[edges.top().second.first] = true;
					result[edges.top().first].push_back(edges.top().second);
					result[edges.top().second.first].push_back(pair<int, int>(edges.top().first,edges.top().second.second));
				}
				edges.pop();
			}
		}

	}
};

int main() {
	Graph graph, tree;
	GraphManager::input_graph(graph, "input/2.txt");
	GraphManager::algorithm_Prim(graph, tree, 0);
	GraphManager::print_graph(tree, "output.txt");
}