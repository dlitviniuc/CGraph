#include "grafo.h"
#include <vector>
#include <cstdlib>

void test_costruttori() {
	std::cout << "***************  Test costruttori  ***************" << std::endl;
	std::cout << "grafo base vuoto" << std::endl;
	grafo<int> g;
	std::cout << "grafo size " << g.size() << std::endl;
	std::cout << "aggiunta nodi 1, 2, 3" << std::endl;
	g.add_node(1);
	g.add_node(2);
	g.add_node(3);
	std::cout << "esiste 1 " << g.exists(1) << std::endl;
	std::cout << "esiste 15 " << g.exists(15) << std::endl;
	g.print_grafo();
	std::cout << "creazione grafo2 con copy costructor " << std::endl;
	grafo<int> g2(g);
	std::cout << "grafo2 size " << g2.size() << std::endl;
	g2.print_grafo();
	std::cout << "***************  Test di rimozione di tutti i nodi due volte ***************" << std::endl;
	std::cout << "rimozione di tutti i nodi per g2(individualmente)" << std::endl;
	try {
		g2.remove_node(1);
		g2.remove_node(2);
		g2.remove_node(3);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	g2.print_grafo();
	std::cout << "rimozione secondaria di tutti i nodi per g2" << std::endl;
	try {
		g2.remove_node(1);
		g2.remove_node(2);
		g2.remove_node(3);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	g2.print_grafo();
	std::cout << "***************  Test copy costructor con aggiunta successiva di nodi ***************" << std::endl;
	std::cout << "creazione grafo g3 di interi" << std::endl;
	grafo<int> g3;
	std::cout << "aggiunta nodo 1 e 2 a g3" << std::endl;
	g3.add_node(1);
	g3.add_node(2);
	std::cout << "creazione grafo g4 con copy costructor passandogli g3" << std::endl;
	grafo<int> g4(g3);
	std::cout << "aggiunta nodo 3 a g3" << std::endl;
	g3.add_node(3);
	std::cout << "stampa g4" << std::endl;
	g4.print_grafo();
}

void test_add_arc() {
	std::cout << "***************  Test aggiunta archi  ***************" << std::endl;
	std::cout << "grafo base vuoto" << std::endl;
	grafo<int> g;
	std::cout << "grafo size: " << g.size() << " elementi: " << g << std::endl;
	g.add_node(1);
	g.add_node(2);
	g.add_node(3);
	std::cout << "grafo size: " << g.size() << " elementi: " << g << std::endl;
	std::cout << "aggiunta arco tra 1 e 2" << std::endl;
	try {
		g.add_arc(1, 2);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "connected 1 e 2 " << g.connected(1, 2) << std::endl;
	std::cout << "aggiunta arco tra 3 e 4" << std::endl;
	try {
		g.add_arc(3, 4);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << g << std::endl;
	std::cout << "numero archi " << g.arcs() << std::endl;
	g.print_grafo();
	std::cout << "aggiunta arco tra 15 e 25" << std::endl;
	try {
		g.add_arc(15, 25);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "numero archi " << g.arcs() << std::endl;
	g.print_grafo();
}

void test_remove_node() {
	std::cout << "***************  Test rimozione e aggiunta successiva nodi  ***************" << std::endl;
	std::cout << "grafo base vuoto" << std::endl;
	grafo<int> g;
	std::cout << "grafo size " << g.size() << std::endl;
	std::cout << "aggiunta nodo 1, 2, 3" << std::endl;
	try {
		g.add_node(1);
		g.add_node(2);
		g.add_node(3);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "grafo size: " << g.size() << " elementi: " << g << std::endl;
	std::cout << "rimozione nodo 2" << std::endl;
	try {
		g.remove_node(2);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "grafo size: " << g.size() << " elementi: " << g << std::endl;
	std::cout << "aggiunta nodo 3" << std::endl;
	try {
		g.add_node(3);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "aggiunta nodo 4, 5, 6" << std::endl;
	try {
		g.add_node(4);
		g.add_node(5);
		g.add_node(6);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "grafo size: " << g.size() << " elementi: " << g << std::endl;
	std::cout << "aggiunta nodo 2" << std::endl;
	try {
		g.add_node(2);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "grafo size: " << g.size() << " elementi: " << g << std::endl;
	g.print_grafo();
}

void test_connessioni() {
	std::cout << "***************  Test delle connessioni  ***************" << std::endl;
	std::cout << "grafo base vuoto" << std::endl;
	grafo<char> g;
	std::cout << "grafo size " << g.size() << std::endl;
	std::cout << "aggiunta nodo a, b, c, d, e, f" << std::endl;
	try {
		g.add_node('a');
		g.add_node('b');
		g.add_node('c');
		g.add_node('d');
		g.add_node('e');
		g.add_node('f');
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "grafo size: " << g.size() << " elementi: " << g << std::endl;
	std::cout << "aggiunta archi (a,b) (a,c) (c,a) (d,f) (f,a) (b,e)" << std::endl;
	try {
		g.add_arc('a', 'b');
		g.add_arc('a', 'c');
		g.add_arc('c', 'a');
		g.add_arc('d', 'f');
		g.add_arc('f', 'a');
		g.add_arc('b', 'e');
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "numero archi " << g.arcs() << std::endl;
	g.print_grafo();
	std::cout << "rimozione archi (a,b) (c,a) (b,e)" << std::endl;
	try {
		g.remove_arc('a', 'b');
		g.remove_arc('c', 'a');
		g.remove_arc('b', 'e');
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	g.print_grafo();
	std::cout << "aggiunta archi (a,b) (c,a) (d,f) (f,a) (b,e)" << std::endl;
	try {
		g.add_arc('a', 'b');
		g.add_arc('c', 'a');
		g.add_arc('d', 'f');
		g.add_arc('f', 'a');
		g.add_arc('b', 'e');
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "numero archi " << g.arcs() << std::endl;
	g.print_grafo();
	std::cout << "tentativo aggiunta archi (c,f) (e,f) (g,h)" << std::endl;
	try {
		g.add_arc('c', 'f');
		g.add_arc('e', 'f');
		g.add_arc('g', 'h');
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "numero archi " << g.arcs() << std::endl;
	g.print_grafo();
}

typedef grafo<std::string> strgrafo;

void test_strgrafo() {
	std::cout << "***************  Test di uso del grafo con nodi ti tipo string  ***************" << std::endl;
	std::cout << "grafo base vuoto" << std::endl;
	strgrafo g;
	g.print_grafo();
	std::cout << "aggiunta nodo uno, due, tre, marta, john, editor" << std::endl;
	try {
		g.add_node("uno");
		g.add_node("due");
		g.add_node("tre");
		g.add_node("marta");
		g.add_node("john");
		g.add_node("editor");
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	g.print_grafo();
	std::cout << "aggiunta archi (uno,due) (due,editor) (tre,john) (marta,uno) (uno,marta) (editor, tre) (john, uno)" << std::endl;
	try {
		g.add_arc("uno", "due");
		g.add_arc("due", "editor");
		g.add_arc("tre", "john");
		g.add_arc("marta", "uno");
		g.add_arc("uno", "marta");
		g.add_arc("editor", "tre");
		g.add_arc("john", "uno");
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "numero archi " << g.arcs() << std::endl;
	g.print_grafo();
	std::cout << "tentativo rimozione nodo ciao" << std::endl;
	try {
		g.remove_node("ciao");
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	g.print_grafo();
	std::cout << "rimozione archi (due, editor) (marta, uno) (uno, marta) (saluti, due)" << std::endl;
	try {
		g.remove_arc("due", "editor");
		g.remove_arc("marta", "uno");
		g.remove_arc("uno", "marta");
		g.remove_arc("saluti", "due");
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "esiste saluti " << g.exists("saluti") <<std::endl;
	std::cout << "numero archi in g " << g.arcs() <<std::endl;
	std::cout << "esiste arco (editor, tre) " << g.connected("editor", "tre") <<std::endl;
	g.print_grafo();
	std::cout << "operazione assegnamento g2 = g " <<std::endl;
	strgrafo g2 = g;
	std::cout << "stampa g2" <<std::endl;
	g2.print_grafo();
	std::cout << "rimozione nodo john da g2 " <<std::endl;
	g2.remove_node("john");
	std::cout << "stampa g" <<std::endl;
	g.print_grafo();
	std::cout << "stampa g2" <<std::endl;
	g2.print_grafo();
}

/**
  Struct point che implementa un punto 2D.

  @brief Struct point che implementa un punto 2D.
*/
struct point {
	int x; ///< coordinata x del punto
	int y; ///< coordinata y del punto

	point(int xx, int yy) : x(xx), y(yy) {}
	point() : x(0), y(0) {}
	/**
	  operator== per un punto
	*/
	bool operator==(const point& other) {
		return x == other.x && y == other.y;
	}
	/**
	  operator!= per un punto
	*/
	bool operator!=(const point& other) {
		return x != other.x || y != other.y;
	}
};
/**
  Ridefinizione dell'operatore di stream << per un point.
  Necessario per l'operatore di stream della classe ordered_list.
*/
std::ostream& operator<<(std::ostream& os, const point& p) {
	std::cout << "(" << p.x << "," << p.y << ")";
	return os;
}

typedef grafo<point> pointgrafo;

void test_point_grafo() {
	std::cout << "***************  Test di uso del grafo con nodi ti tipo point  ***************" << std::endl;
	std::cout << "grafo base vuoto" << std::endl;
	pointgrafo g;
	g.print_grafo();
	std::cout << "aggiunta nodi (0,0) (1,1) (5,3) (4,20) (3,11)" << std::endl;
	try {
		g.add_node(point(0, 0));
		g.add_node(point(1, 1));
		g.add_node(point(5, 3));
		g.add_node(point(4, 20));
		g.add_node(point(3, 11));
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	g.print_grafo();
	std::cout << "aggiunta archi ((0,0),(1,1)) ((1,1),(1,1)) ((5,3),(1,1)) ((4,20),(1,1)) ((3,11),(1,1))" << std::endl;
	try {
		g.add_arc(point(0, 0), point(1, 1));
		g.add_arc(point(1, 1), point(1, 1));
		g.add_arc(point(5, 3), point(1, 1));
		g.add_arc(point(4, 20), point(1, 1));
		g.add_arc(point(3, 11), point(1, 1));
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "numero archi "<< g.arcs() << std::endl;
	g.print_grafo();
	std::cout << "tentativo rimozione arco tra (3,11) e (50, 120)" << std::endl;
	try {
		g.remove_arc(point(3,11), point(50, 120));
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	g.print_grafo();
	std::cout << "interrogazione se archi esistono: (1,1) (5,3)" << g.connected(point(1,1), point(5,3))  << std::endl;
	std::cout << "interrogazione se archi esistono: (5,3) (1,1)" << g.connected(point(5, 3), point(1, 1)) << std::endl;
	std::cout << "interrogazione se archi esistono: (4,20) (3,11)" << g.connected(point(4, 20), point(3, 11)) << std::endl;
	std::cout << "interrogazione se nodi esistono: (1,1) " << g.exists(point(1, 1)) << std::endl;
	std::cout << "interrogazione se nodi esistono: (5,3) " << g.exists(point(5, 3)) << std::endl;
	std::cout << "interrogazione se nodi esistono: (49,20) " << g.exists(point(49, 20)) << std::endl;
	std::cout << "rimozione nodo (1,1) " << std::endl;
	g.remove_node(point(1, 1));
	std::cout << "interrogazione se nodi esistono: (1,1) " << g.exists(point(1, 1)) << std::endl;
	std::cout << "interrogazione se archi esistono: (5,3) (1,1)" << std::endl;
	try {
		g.connected(point(5, 3), point(1, 1));
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "stampa g" <<std::endl;
	g.print_grafo();
	std::cout << "operazione assegnamento g2 = g " <<std::endl;
	pointgrafo g2 = g;
	std::cout << "numero archi g2 "<< g2.arcs() << std::endl;
	std::cout << "stampa g2" <<std::endl;
	g2.print_grafo();
}

void test_add_iter() {
	std::cout << "***************  Test di uso del metodo add_nodes con iteratori  ***************" << std::endl;
	std::cout << "grafo base vuoto g" << std::endl;
	grafo<int> g;
	std::vector<int> nodi;
	std::cout << "aggiunta di 15 interi random nel vettore tra 0 e 99" << std::endl;
	for(int i=0; i<15; i++){
		nodi.push_back(rand() % 100);
	}
	std::cout << "aggiunta dei 15 valori del vettore nel grafo tramite add_nodes" << std::endl;
	g.add_nodes(nodi.begin(), nodi.end());
	std::cout << "stampa grafo" << std::endl;
	g.print_grafo();
	std::cout << "controllo esistenza dei valori" << std::endl;
	std::cout << "exists " << nodi.at(5) << " " << g.exists(nodi.at(5)) << std::endl;
	std::cout << "exists " << nodi.at(7) << " " << g.exists(nodi.at(7)) << std::endl;
	std::cout << "exists " << nodi.at(3) << " " << g.exists(nodi.at(3)) << std::endl;

	std::cout << "grafo base vuoto g2 " << std::endl;
	grafo<int> g2;
	std::vector<int> nodi2;
	std::cout << "aggiunta di 15 interi random nel vettore tra 0 e 9" << std::endl;
	for (int i = 0; i < 15; i++) {
		nodi2.push_back(rand() % 10);
	}
	std::cout << "aggiunta dei 15 valori del vettore nel grafo tramite add_nodes" << std::endl;
	g2.add_nodes(nodi2.begin(), nodi2.end());
	std::cout << "stampa grafo" << std::endl;
	g2.print_grafo();
	std::cout << "controllo esistenza dei valori" << std::endl;
	int v = rand() % 14;
	std::cout << "exists " << nodi2.at(v) << " " << g2.exists(nodi2.at(v)) << std::endl;
	v = rand() % 14;
	std::cout << "exists " << nodi2.at(v) << " " << g2.exists(nodi2.at(v)) << std::endl;
	v = rand() % 14;
	std::cout << "exists " << nodi2.at(v) << " " << g2.exists(nodi2.at(v)) << std::endl;
	std::cout << "***************  Test uso operatore = per i grafi (usando i dati aggiunti con il metodo add_nodes) ***************" << std::endl;
	std::cout << "stampa g2" << std::endl;
	g2.print_grafo();
	std::cout << "g2 = g" << std::endl;
	g2 = g;
	std::cout << "stampa g2" << std::endl;
	g2.print_grafo();
	std::cout << "g2 = g2" << std::endl;
	g2 = g2;
	std::cout << "stampa g2" << std::endl;
	g2.print_grafo();
}

void test_iteratore() {
	std::cout << "***************  Test del const iterator  ***************" << std::endl;
	std::cout << "grafo base vuoto g" << std::endl;
	grafo<int> g;
	std::vector<int> nodi;
	std::cout << "aggiunta di 15 interi in ordine da 1 a 15" << std::endl;
	for (int i = 0; i < 15; i++) {
		nodi.push_back(i+1);
	}
	std::cout << "aggiunta dei 15 valori del vettore nel grafo tramite add_nodes" << std::endl;
	g.add_nodes(nodi.begin(), nodi.end());
	std::cout << "stampa dei valori tramite gli const_iterator del grafo" << std::endl;
	grafo<int>::const_iterator b, e;
	for (b = g.begin(), e = g.end(); b != e; b++) {
		std::cout << *b << " ";
	}
}


int main() {
	test_costruttori();
	test_add_arc();
	test_remove_node();
	test_connessioni();
	test_strgrafo();
	test_point_grafo();
	test_add_iter();
	test_iteratore();
}
