#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Vertex; //On anticipe car on a besoin de Vertex pour Edge

class Edge { // Arête
public:
    Vertex* start; // Sommet de départ de l'arête
    Vertex* end;   // Sommet de fin de l'arête
    double value;  // Valeur associée à l'arête

    Edge(Vertex* s, Vertex* e, double v) : start(s), end(e), value(v) {} // Constructeur
};

class Vertex { //Sommet
public:
    int value; // Indice du sommet
    std::vector<Edge*> edges; // Liste des arêtes auquel le sommet est relié
    bool visited; // Pour le parcours en profondeur : booléen disant si le sommet a été visité

    Vertex(int val) : value(val), visited(false) {} // Constructeur

    void addEdge(Edge* edge) { edges.push_back(edge); } // Méthode pour ajouter des arêtes au sommet
};

class Graph {
public:
    std::vector<Vertex*> vertices; // Liste des sommets du graphe
    std::vector<Edge*> edges;      // Liste des arêtes du graphe

    ~Graph() { // Destructeur du graphe
        for (Vertex* v : vertices) {
            delete v;
        }
        for (Edge* e : edges) {
            delete e;
        }
    }

    Vertex* addVertex(int val) { // Ajout d'un sommet au graphe
        Vertex* newVertex = new Vertex(val);
        vertices.push_back(newVertex);
        return newVertex;
    }

    Edge* addEdge(Vertex* start, Vertex* end, double value) { // Ajout d'une arête au graphe
        Edge* newEdge = new Edge(start, end, value);
        start->addEdge(newEdge);
        edges.push_back(newEdge);
        return newEdge;
    }

    void depthFirstSearch(Vertex* start) {
        if (start == nullptr) return;
        std::cout << "Sommet de départ : " << start->value << std::endl;
        depthFirstSearchRecursive(start);
    }

private:
    void depthFirstSearchRecursive(Vertex* current) {
        if (current == nullptr || current->visited) return;

        std::cout << "Sommet visité : " << current->value << std::endl;
        current->visited = true;

        for (Edge* edge : current->edges) {
            std::cout << "Arête : " << edge->start->value << " -> " << edge->end->value << " (Value: " << edge->value << ")" << std::endl;
            depthFirstSearchRecursive(edge->end);
        }
    }
};

void read_graph(Graph& graph, const std::string& filename) {
    std::ifstream input_file(filename);

    if (!input_file.is_open()) {
        std::cout << "Cannot open file " << filename << std::endl;
        return;
    }

    int num_vertices;
    input_file >> num_vertices;

    for (int i = 1; i <= num_vertices; ++i) {
        graph.addVertex(i);
    }

    int from, to;
    double value;
    while (input_file >> from >> to >> value) {
        graph.addEdge(graph.vertices[from - 1], graph.vertices[to - 1], value);
    }

    input_file.close();
}

int main() {
    Graph myGraph;
    read_graph(myGraph, "./ex0.gr");
    myGraph.depthFirstSearch(myGraph.vertices[0]); // On fait partir le parcours du premier sommet
    return 0;
}

