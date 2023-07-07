#ifndef GRAFO_H
#define GRAFO_H

#include <iostream> //input/output
#include <iterator> //std::forward_iterator_tag
#include <algorithm> //std::swap
#include <cstddef> //std::ptrdiff_t

/**
  @brief classe grafo

  La classe implementa un grafo orientato per elementi generici di tipo T.
  � possibile aggiungere elementi con il metodo add_node e connettere due nodi tra loro con add_arc
  La classe utilizza due strutture di supporto, la matrice di tipo booleano che contiene le connessioni tra i nodi,
  contenuta in un array monodimensionale e un array che contiene i dati dei vari nodi, questi di tipo T.
  Non viene implementato l'operatore == perch� non richiesto.

*/

template <typename T>

class grafo {
	/**
		@brief struct matrix

		La struct contiene un array di elementi ti tipo booleano e il numero di nodi che vengono rappresentati.
		La struttura si occupa di rappresentare solo le connettivit� tra i nodi, lasciando tutto il resto oltre al loro numero a nodes.
		L'operatore = copia nella totalit� la matrice other, sovrascrivendo la matrice precedente.
		Nel copy costructor viene creata una matrice nuova della stessa dimensione di quella other,
		copiando successivamente i dati nello stesso ordine.
		La matrice sar� sempre (virtualmente) quadrata, con i lati lunghi quanto la seconda struttura.
		All'aggiunta di un arco, il primo valore viene mostrato sulle righe, mentre il secondo sulle colonne,
		un esempio sarebbe all'aggiunta di un arco tra (1, 2) verr� messa a vero la cella della riga corrispondente alla posizione di 1
		nella struttura dei nodi e la colonna corrispondente alla posizione di 2.
	*/
	struct matrix {
		bool* connected; //puntatore riservato per l'array/matrice contenente quali dati sono connessi
		unsigned int _nodes; //numero di nodi del grafo (lunghezza dei lati)
		/**
			costruttore di default
			@post connected == nullptr
			@post _nodes == 0
		*/
		matrix() : connected(nullptr), _nodes(0) {}
		/**
			costruttore secondario (usato solo internamente)
			@param nodes numero di nodi da rappresentare/lunghezza lati della matrice

			@post _nodes == nodes

			Crea connected come un array di bool di dimensione _nodes * _nodes
		*/
		explicit matrix(const unsigned int& nodes) {
			_nodes = nodes;
			connected = new bool[_nodes * _nodes];
			try {
				for (int i = 0; i < _nodes * _nodes; i++) {
					connected[i] = 0;
				}
			}
			catch (...) {
				clear();
				throw;
			}
		}
		/**
			copy constructor
			@param other matrixda colpiare

			@post _nodes = other._nodes

			crea un nuovo array di bool di dimensione _nodes * _nodes

			copia i dati di other.connected nella matrice connected
		*/
		matrix(const matrix& other) {
			_nodes = other._nodes;
			connected = new bool[_nodes * _nodes];
			try {
				for (unsigned int i = 0; i < _nodes * _nodes; i++) {
					connected[i] = other.connected[i];
				}
			}
			catch (...) {
				clear();

				throw;
			}
		}
		/**
			Operatore di assegnamento

			ritorna una matrice uguale a qella other

			@param other matrix da copiare.

			@return reference alla matrix this

		*/
		matrix& operator=(const matrix& other) {
			if (this != &other) {
				matrix tmp(other);

				this->swap(tmp);
			}
			return *this;
		}
		/**

			Metodo swap.

			effettua lo swap per connected e _nodes, tramite std::swap.

		*/
		void swap(matrix& other) {
			std::swap(connected, other.connected);
			std::swap(_nodes, other._nodes);
		}
		/**

			Metodo size.

			Ritorna la lunghezza dell'array connected

		*/
		const unsigned int size() const {
			return _nodes * _nodes;
		}
		/**

			Distruttore.

		*/
		~matrix() {
			clear();
		}
		/**

			Metodo clear.

			elimina il vettore connected e azzere la variabile _nodes.

		*/
		void clear() {
			delete[] connected;
			_nodes = 0;
		}
	};
	/**
		@brief struct nodes

		La struct contiene un array di elementi ti tipo generico T e il numero di nodi che vengono contenuti al suo interno.
		Questa struttura si occupa di contenere i dati dei nodi, lasciando la connettivit� a matrix.
		L'operatore = copia i dati dell'array relativo a other e il numero di dati contenuti in other.
	*/
	struct nodes {
		T* elements; //array contenente i dati dei vari nodi, di tipo generico
		unsigned int _nodes; //numero di nodi contenuti.
		/**
			costruttore di default
			@post elements == nullptr
			@post _nodes == 0
		*/
		nodes() : elements(nullptr), _nodes(0) {}
		/**
			costruttore secondario (usato solo internamente)
			@param nodes numero di nodi da rappresentare/lunghezza lati della matrice

			@post _nodes == nodes

			Crea elements come un array di tipo generico T di dimensione _nodes
		*/
		nodes(const unsigned int& nodes) {
			_nodes = nodes;
			elements = new T[_nodes];
		}
		/**
			copy constructor
			@param other nodes da colpiare

			@post _nodes = other._nodes

			crea un nuovo array di tipo generico T di dimensione _nodes

			copia i dati di other.elements nel vettore elements
		*/
		nodes(const nodes& other) {
			_nodes = other._nodes;
			elements = new T[_nodes];
			try {
				for (unsigned int i = 0; i < _nodes; i++) {
					elements[i] = other.elements[i];
				}
			}
			catch (...) {
				clear();

				throw;
			}
		}
		/**
			Operatore di assegnamento

			ritorna una struttura nodes con gli elementi di other

			@param other nodes da copiare.

			@return reference alla strutture nodes this

		*/
		nodes& operator= (const nodes& other) {
			if (this != &other) {
				try {
					nodes tmp(other);
					this->swap(tmp);
				}
				catch (...) {
					clear();

					throw;
				}

			}
			return *this;
		}
		/**

			Metodo swap.

			effettua lo swap per elements e _nodes, tramite std::swap.

		*/
		void swap(nodes& other) {
			std::swap(elements, other.elements);
			std::swap(_nodes, other._nodes);
		}
		/**

			Metodo size.

			Ritorna il numero di nodi contenuti

		*/
		const unsigned int size() const {
			return _nodes;
		}
		/**

			Distruttore.

		*/
		~nodes() {
			clear();
		}
		/**

			Metodo clear.

			elimina il vettore elements e azzere la variabile _nodes.

		*/
		void clear() {
			delete[] elements;
			_nodes = 0;
		}
	};
private:
	matrix* matrice; //struttura per la matrice di adiacenza indicativa degli archi
	nodes* nodi; //struttura contenente le informazioni dei nodi

public:
	/**
		costruttore di default
		Crea matrix vuota e nodes vuoto.
	*/
	grafo() {
		try{
				matrice = new matrix();
				nodi = new nodes();
			}catch(...){
				delete matrice;
				delete nodi;
			}
	}
	/**
		copy constructor
		@param other grafo da colpiare

		Crea una nuova matrice di adiacenza tramite il suo copy costructor e una struttura per i nodi sempre tramite il copy costructor.

		I costruttori usati copiano i dati dell'altro grafo.
	*/
	grafo(const grafo& other) {
		try {
			matrice = new matrix(*other.matrice);
			nodi = new nodes(*other.nodi);
		}
		catch (...) {
			delete matrice;
			delete nodi;
			throw;
		}
	}
	/**

		Metodo exists.

		@param node, reference ad un nodo di tipo generico T.

		@return true se node � contenuto in nodi, false altrimenti oppure se non ci sono nodi.

	*/
	bool exists(const T& node) {
		if (nodi->size() == 0)
			return false;
		for (unsigned int i = 0; i < size(); i++) {
			if (nodi->elements[i] == node) {
				return true;
			}
		}
		return false;
	}
	/**

		Metodo connected.

		@param node1, node2 reference a due nodi di tipo generico T.

		@return true se node nella matrice di adiacenza node1 � connesso a node2, false altrimenti.

		@throws Lancia un'eccezzione se uno dei due nodi non esiste.

	*/
	const bool connected(const T& node1, const T& node2) {
		if (!exists(node1) || !exists(node2))
			throw std::invalid_argument("nodo non presente nel grafo ");
		int pos1 = 0;
		int pos2 = 0;
		for (unsigned int i = 0; i < size(); i++) {
			if (nodi->elements[i] == node1)
				pos1 = i;
			if (nodi->elements[i] == node2)
				pos2 = i;
		}
		int position = pos1 * size() + pos2;
		return matrice->connected[position];
	}
	/**
		Operatore di assegnamento

		ritorna un grafo uguale a quello other.

		@param other grafo da copiare.

		@return reference al grafo this.

	*/
	grafo& operator=(const grafo& other) {
		if (this != &other) {
			grafo<T> tmp(other);
			std::swap(nodi, tmp.nodi);
			std::swap(matrice, tmp.matrice);
		}
		return *this;
	}
	/**

		Metodo add_node.

		@param node di tipo generico T.

		Aggiunge un nodo isolato, i suoi dati vengono inseriti in fondo alla struttura nodi
		e vengono create una riga e colonna con valore 0(non connesso a nulla), la riga e colonna vengono aggiunte sempre in fondo.

		@throws Lancia un'eccezzione se il nodo � gi� inserito, non permettendo ripetizioni.

	*/
	void add_node(const T& node) {
		if (exists(node))
			throw std::invalid_argument("nodo gia presente nel grafo");
		nodes tmp_nodes = nodes(nodi->size() + 1);
		try {
			for (unsigned int i = 0; i < size(); i++) {
				tmp_nodes.elements[i] = nodi->elements[i];
			}
		}
		catch (...) {
			tmp_nodes.clear();

			throw;
		}
		tmp_nodes.elements[size()] = node;
		*nodi = tmp_nodes;
		matrix tmp_mat = matrix(size());
		try {
			unsigned int offset = 0;
			for (unsigned int i = 0; i < size() - 1; i++) {
				if (i != size() - 1) {
					for (unsigned int j = 0; j < size() - 1; j++) {
						if (j != size() - 1) {
							tmp_mat.connected[offset] = matrice->connected[i * (size() - 1) + j];
						}
						offset++;
					}
					tmp_mat.connected[offset] = 0;
					offset++;
				}
				offset++;
			}
			for (offset; offset < tmp_mat.size(); offset++) {
				tmp_mat.connected[offset] = 0;
			}
		}
		catch (...) {
			tmp_mat.clear();

			throw;
		}
		*matrice = tmp_mat;
	}
	/**

		Metodo remove_node.

		@param node di tipo generico T.

		Rimuove il nodo, copiando la struttura nodi di dimensione -1 e copiando il resto di quella precedente tranne la colonna del nodo;
		rimuove anche la rispettiva riga e colonna del nodo, rimuovendo quindi le sue connessioni, copiando tutto in una struttura pi� piccola
		e saltando la riga e colonna relativa al nodo da rimuovere.

		@throws Lancia un'eccezzione se il nodo da rimuovere non esiste nel grafo.

	*/
	void remove_node(const T& node) {
		if (!exists(node))
			throw std::invalid_argument("nodo non presente nel grafo");

		nodes tmp_nodes = nodes(nodi->size() - 1);
		int pos = -1;
		for (unsigned int i = 0; i < size(); i++) {
			if (nodi->elements[i] != node) {
				int offset = i;
				if (pos != -1){
					offset--;
				}
				tmp_nodes.elements[offset] = nodi->elements[i];
			}
			else {
				pos = i;
			}
		}
		*nodi = tmp_nodes;
		matrix tmp_mat = matrix(nodi->size());
		int offset = 0;
		for (unsigned int i = 0; i < size()+1; i++) {
			if (i != pos) {
				for (unsigned int j = 0; j < size()+1; j++) {
					if (j != pos) {
						tmp_mat.connected[offset] = matrice->connected[i * (size()+1) + j];
						offset++;
					}
				}
			}
		}
		*matrice = tmp_mat;
	}
	/**

		Metodo add_arc.

		@param node1 e node2 di tipo generico T.

		Se entrambi i nodi esistono, trova le loro posizioni nell'array dei nodi e imposta a vero la cella con le coordinate:
		riga con posizione del node1 e colonna con posizione di node2.

		@throws Lancia un'eccezzione se uno dei nodi non � presente nel grafo

	*/
	void add_arc(const T& node1, const T& node2) {
		if (!exists(node1) || !exists(node2))
			throw std::invalid_argument("nodo non presente nel grafo");
		int pos1 = 0;
		int pos2 = 0;
		for (unsigned int i = 0; i < size(); i++) {
			if (nodi->elements[i] == node1)
				pos1 = i;
			if (nodi->elements[i] == node2)
				pos2 = i;
		}
		int position = pos1 * size() + pos2;
		matrice->connected[position] = 1;

	}
	/**

		Metodo remove_arc.

		@param node1 e node2 di tipo generico T.

		In modo simile ad add_arc trova le posizioni nel vettore dei nodi dei due parametri passati e se sono connessi,
		segna la cella indicata dalla riga della posizione di node1 e la colonna indicata dalla posizione di node2 come falso.

		@throws Lancia un'eccezzione se uno dei nodi non � presenta nel grafo oppure se l'arco non � presente nel grafo.

	*/
	void remove_arc(const T& node1, const T& node2) {
		if (!exists(node1) || !exists(node2))
			throw std::invalid_argument("nodo non presente nel grafo");
		int pos1 = 0;
		int pos2 = 0;
		for (int i = 0; i < size(); i++) {
			if (nodi->elements[i] == node1)
				pos1 = i;
			if (nodi->elements[i] == node2)
				pos2 = i;
		}
		int position = pos1 * size() + pos2;
		if (!matrice->connected[position])
			throw std::invalid_argument("arco non presente nel grafo");
		matrice->connected[position] = false;
	}
	/**

		Metodo size.

		Ritorna il numero di nodi contenuti nel grafo, se la struttura nodi � nulla ritorna 0, indicando che abbiamo un grafo vuoto.

		@return _nodes

	*/
	const unsigned int size() const{
		if (nodi != nullptr)
			return nodi->_nodes;
		else
			return 0;
	}
	/**

		Metodo arcs.

		Ritorna il numero di archi presenti nel grafo, contando quante celle nella matrice di adiacenza sono vere.

		@return il numero di archi

	*/
	const unsigned int arcs() const{
		unsigned int num = 0;
		for (int i = 0; i < size(); i++) {
			for (int j = 0; j < size(); j++) {
				if (matrice->connected[i * size() + j])
					num++;
			}
		}
		return num;
	}
	/**

		Distruttore.

	*/
	~grafo() {
		delete matrice;
		delete nodi;
	}
	/**

		Metodo print_grafo.

		Un metodo che stampa la matrice di adiacenza con i relativi dati dei nodi rispettivi per ogni riga/colonna,
		permettendo una visualizzazione della struttura come intesa.

	*/
	void print_grafo() const{

		std::cout << "#\t" << *this << std::endl;
		for (unsigned int i = 0; i < size(); i++) {
			std::cout << nodi->elements[i] << "\t";
			for (unsigned int j = 0; j < size(); j++) {
				std::cout << matrice->connected[i * size() + j] << "\t";
			}
			std::cout << "\t" << std::endl;
		}
	}
	/**

		Metodo add_nodes.

		@param b ed e, due iteratori generici.

		Per ogni elemento indicato dai due iteratori aggiunge un nodo se possibile, nel caso uno uguale sia gi� inserito,
		controlla l'eccezzione, stampando per� il fatto che si � tentato di aggiungere un dato gi� presente, ma permette di continuare
		ad aggiungere il resto dei dati, saltando quindi quelli ripetuti.

	*/
	template <typename Iter>

	void add_nodes(Iter b, Iter e) {
		for (b; b < e; b++) {
			try {
				add_node(static_cast<T>(*b));
			}
			catch (const std::exception& ex) {
				std::cerr << ex.what() << std::endl;
			}
		}
	}

	/**
	  Funzione GLOBALE che implementa l'operatore di stream.
	  La funzione � templata sul grafo ed � messa
	  friend perch� accediamo ai dati privati di grafo.

	  @param os stream di output
	  @param gr grafo spedire sullo stream

	  @return lo stream di output
	*/
	friend std::ostream& operator<<(std::ostream& os,
		const grafo<T>& gr) {
		grafo<T>::const_iterator ib, ie;
		for (ib = gr.begin(), ie = gr.end(); ib != ie; ib++) {
			std::cout << *ib << "\t";
		}
		return os;
	}

	/**
		Gli iteratori devono iterare sui dati inseriti nella classe
		principale. Siccome nella ordered_list mettiamo dei dati di
		tipo T, l'iteratore deve iterare sui dati di tipo T. NON sui
		nodi della lista che sono un dettaglio implementativo interno.
	  */
	class const_iterator {
		//
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                        value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T* pointer;
		typedef const T& reference;


		const_iterator() : ptr(nullptr) {
			//!!!
		}

		const_iterator(const const_iterator& other) : ptr(other.ptr) {
			//!!!
		}

		const_iterator& operator=(const const_iterator& other) {
			ptr = other.ptr;
			return *this;
		}

		~const_iterator() {
			//!!!
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return *ptr;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return &(*ptr);
		}

		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator tmp(ptr);
			ptr++;
			return tmp;
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			ptr++;
			return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator& other) const {
			return ptr == other.ptr;
		}

		// Diversita'
		bool operator!=(const const_iterator& other) const {
			return ptr != other.ptr;
		}

	private:
		const T* ptr; // puntatore ad elemento di tipo T

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class grafo;

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(const T* p) : ptr(p) {
		}

		// !!! Eventuali altri metodi privati

	}; // classe const_iterator

	const_iterator begin() const {
		return const_iterator(nodi->elements);
	}

	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return const_iterator(nodi->elements + nodi->_nodes);
	}
};


#endif
