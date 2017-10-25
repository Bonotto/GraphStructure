//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_GRAPH_H
#define PROJECT_GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <exception>
#include <stdlib.h>
#include <time.h>
#include <list>

using namespace std;

template<typename T>
class Graph
{
public:
	Graph();
	~Graph();

	void insert(T node);
	void remove(T node);

	void connect(T source, T target);
	void disconnect(T source, T target);

	size_t range();

	unordered_set<T> nodes();
	unordered_set<T> adjacents(T node);
	unordered_set<T> successors(T node);
	unordered_set<T> predecessors(T node);
	unordered_set<T> fonts();
	unordered_set<T> sinks();

	size_t grade(T node);

	T anyNode();

	bool contains(T node);

	bool isRegular();
	bool isComplete();

	list<T> topologicalOrdering();

private:
	void visit(T node, list<T> & list, unordered_set<T> & temporary, unordered_set<T> & permanent);

	unordered_map<T, unordered_set<T>> mForward;
	unordered_map<T, unordered_set<T>> mBackward;
};

template<typename T>
Graph<T>::Graph()
{
	srand(time(NULL));
}

template<typename T>
Graph<T>::~Graph()
{
	
}

template<typename T>
bool Graph<T>::contains(T node)
{
	return mForward.find(node) != mForward.end();
}

template<typename T>
void Graph<T>::insert(T node)
{
	if (contains(node))
		throw out_of_range("The node already exist!");

	mForward[node] = unordered_set<T> {};
	mBackward[node] = unordered_set<T> {};
}

template<typename T>
void Graph<T>::connect(T source, T target)
{
	if (!contains(source) && !contains(target))
		throw out_of_range("Some node doesn't exist!");

	mForward[source].emplace(target);
	mBackward[target].emplace(source);
}

template<typename T>
void Graph<T>::disconnect(T source, T target)
{
	if (!contains(source) && !contains(target))
		throw out_of_range("Some node doesn't exist!");

	mForward[source].erase(target);
	mBackward[target].erase(source);
}

template<typename T>
void Graph<T>::remove(T node)
{
	if (!contains(node))
		throw out_of_range("The node doesn't exist!");

	for (auto n: successors(node))
		disconnect(node, n);

	for (auto n: predecessors(node))
		disconnect(n, node);

	mForward.erase(node);
	mBackward.erase(node);
}

template<typename T>
size_t Graph<T>::range()
{
	return mForward.size();
}

template<typename T>
unordered_set<T> Graph<T>::nodes()
{
	unordered_set<T> allNodes;

	for (auto v: mForward)
		allNodes.emplace(v.first);

	return allNodes;
}

template<typename T>
unordered_set<T> Graph<T>::adjacents(T node)
{
	bool cond = mForward[node].size() < mBackward[node].size();
	unordered_set<T> minor = cond ? mForward[node] : mBackward[node];
	unordered_set<T> major = cond ? mBackward[node] : mForward[node];

	for (auto v : minor)
		major.emplace(v);

	return major;
}
	
template<typename T>
unordered_set<T> Graph<T>::successors(T node)
{
	return mForward[node];
}

template<typename T>
unordered_set<T> Graph<T>::predecessors(T node)
{
	return mBackward[node];
}

template<typename T>
size_t Graph<T>::grade(T node)
{
	return adjacents(node).size();
}

template<typename T>
T Graph<T>::anyNode()
{
	return mForward.begin()->first;
}

template<typename T>
bool  Graph<T>::isRegular()
{
	int grau = -1;
	int aux;

	for (auto v : mForward) {
		aux = grade(v.first);
		if (aux == grau || grau == -1)
			grau = aux;
		else
			return false;
	}

	return true;
}

template<typename T>
bool Graph<T>::isComplete()
{
	size_t counter = 0;
	for (auto v: mForward)
		counter += v.second.size();

	size_t amount = range();

cout << "c " << counter << endl;

	return (counter == ((amount*amount - amount) / 2));
}

template<typename T>
unordered_set<T> Graph<T>::fonts()
{
	unordered_set<T> allFonts;

	for (auto v: mBackward)
		if (v.second.empty())
			allFonts.emplace(v.first);

	return allFonts;
}

template<typename T>
unordered_set<T> Graph<T>::sinks()
{
	unordered_set<T> allSinks;

	for (auto v: mForward)
		if (v.second.empty())
			allSinks.emplace(v.first);

	return allSinks;
}

template<typename T>
list<T> Graph<T>::topologicalOrdering()
{
	list<T> list;
	unordered_set<T> temporary;
	unordered_set<T> permanent;
	unordered_set<T> sink_set = sinks();

	while (!sink_set.empty()) {

		T node = *sink_set.begin();
		sink_set.erase(node);

		visit(node, list, temporary, permanent);
	}

	return list;
}

template<typename T>
void Graph<T>::visit(T node, list<T> & list, unordered_set<T> & temporary, unordered_set<T> & permanent)
{

	if (permanent.find(node) != permanent.end())
		return;

	if (temporary.find(node) != temporary.end()) 
		throw out_of_range("Is not a DAG, contains a cycle!");

	temporary.emplace(node);

	for (auto v: predecessors(node))
		visit(v, list, temporary, permanent);

	temporary.erase(node);
	permanent.emplace(node);

	list.push_back(node);
}

#endif