
#include <unordered_map>
#include <unordered_set>
#include <list>


using namespace std;

template<typename T>
class Graph
{
public:
	Graph();
	~Graph();

	void insertNode(T node);
	void removeNode(T node);

	void connect(T source, T target);
	void disconnect(T source, T target);

	size_t range();

	unordered_set<T> nodes();
	unordered_set<T> adjacents(T node);
	unordered_set<T> successors(T node);
	unordered_set<T> predecessors(T node);

	size_t grade(T node);

	T anyNode();

	bool contains(T node);

	/* Funções a mais */
	bool isRegular();
	bool isComplete();
	//bool isConnected();
	//bool isTree();
	//unordered_set transitiveClosure(T & node);

private:
	unordered_map<T, unordered_set<T>> mForward;
	unordered_map<T, unordered_set<T>> mBackward;
};