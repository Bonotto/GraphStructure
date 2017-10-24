#include "./Graph.h"

using namespace std;

template<typename T>
Graph<T>::Graph()
{
	
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
void Graph<T>::insertNode(T node)
{
	if (!mForward.contains(node)) {
		mForward[node] = unordered_set<T> {};
		mBackward[node] = unordered_set<T> {};
	}
}

template<typename T>
void Graph<T>::connect(T source, T target)
{
	if (!mForward.contains(source) && !mForward.contains(target))
		return; // throw error

	mForward[source].emplace(target);
	mBackward[target].emplace(source);
}

template<typename T>
void Graph<T>::disconnect(T source, T target)
{
	if (!mForward.contains(source) && !mForward.contains(target))
		return; // throw error

	mForward[source].erase(target);
	mBackward[target].erase(source);
}

template<typename T>
void Graph<T>::removeNode(T node)
{
	if (!mForward.contains(node))
		return; // throw error

		for (auto & n: mForward[node])
			disconnectNode(node, n);

		for (auto & n: mBackward[node])
			disconnectNode(n, node);

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

	for (auto & v: mForward)
		allNodes.emplace(v.first);

	return allNodes;
}

template<typename T>
unordered_set<T> Graph<T>::adjacents(T node)
{
	bool cond = mForward[node].size() < mBackward[node].size();
	unordered_set<T> & minor = cond ? mForward[node] : mBackward[node];
	unordered_set<T> & major = cond ? mBackward[node] : mForward[node];

	for (auto & v : minor)
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
	return mForward.begin().first;
}

template<typename T>
bool  Graph<T>::isRegular()
{
	int grade = -1;
	int aux;

	for (auto & v : mForward) {
		aux = grade(v.first);
		if (aux == grade || grade == -1)
			grade = aux;
		else
			return false;
	}

	return true;
}

template<typename T>
bool Graph<T>::isComplete()
{
	size_t counter = 0;
	for (auto & v: mForward)
		counter += v.second.size();

	size_t amount = range();

	return (counter == (amount^2 - amount) / 2);
}