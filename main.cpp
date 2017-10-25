
#include <iostream>
#include <utility>
#include <string>

#include "./Discipline.h"
#include "./Graph.h"

using namespace std;

void firstExercise();
void secondExercise(int maxCredits);

int main(int argc, char const *argv[])
{
	firstExercise();
	secondExercise(30);

	return 0;
}

void firstExercise()
{
	Graph< Discipline * > graph;

	Discipline * INE5403 = new Discipline("INE5403", 6);
	Discipline * INE5402 = new Discipline("INE5402", 6);
	Discipline * INE5401 = new Discipline("INE5401", 2);
	Discipline * INE5407 = new Discipline("INE5407", 3);
	Discipline * INE5406 = new Discipline("INE5406", 5);
	Discipline * INE5404 = new Discipline("INE5404", 6);
	Discipline * INE5405 = new Discipline("INE5405", 5);
	Discipline * INE5409 = new Discipline("INE5409", 4);
	Discipline * INE5408 = new Discipline("INE5408", 6);
	Discipline * INE5410 = new Discipline("INE5410", 4);
	Discipline * INE5411 = new Discipline("INE5411", 6);
	Discipline * INE5412 = new Discipline("INE5412", 4);
	Discipline * INE5414 = new Discipline("INE5414", 4);
	Discipline * INE5417 = new Discipline("INE5417", 5);
	Discipline * INE5416 = new Discipline("INE5416", 5);
	Discipline * INE5413 = new Discipline("INE5413", 4);
	Discipline * INE5415 = new Discipline("INE5415", 4);
	Discipline * INE5420 = new Discipline("INE5420", 4);
	Discipline * INE5421 = new Discipline("INE5421", 4);
	Discipline * INE5419 = new Discipline("INE5419", 4);
	Discipline * INE5423 = new Discipline("INE5423", 4);
	Discipline * INE5422 = new Discipline("INE5422", 4);
	Discipline * INE5418 = new Discipline("INE5418", 4);
	Discipline * INE5424 = new Discipline("INE5424", 4);
	Discipline * INE5453 = new Discipline("INE5453", 1);
	Discipline * INE5427 = new Discipline("INE5427", 4);
	Discipline * INE5430 = new Discipline("INE5430", 4);
	Discipline * INE5426 = new Discipline("INE5426", 4);
	Discipline * INE5425 = new Discipline("INE5425", 4);
	Discipline * INE5433 = new Discipline("INE5433", 6);
	Discipline * INE5432 = new Discipline("INE5432", 4);
	Discipline * INE5429 = new Discipline("INE5429", 4);
	Discipline * INE5431 = new Discipline("INE5431", 4);
	Discipline * INE5428 = new Discipline("INE5428", 4);
	Discipline * INE5434 = new Discipline("INE5434", 9);
	Discipline * MTM3100 = new Discipline("MTM3100", 4);
	Discipline * MTM3101 = new Discipline("MTM3101", 4);
	Discipline * MTM5512 = new Discipline("MTM5512", 4);
	Discipline * MTM3102 = new Discipline("MTM3102", 4);
	Discipline * MTM5245 = new Discipline("MTM5245", 4);
	Discipline * EEL5105 = new Discipline("EEL5105", 5);

	graph.insert(INE5403);
	graph.insert(INE5402);
	graph.insert(INE5401);
	graph.insert(INE5407);
	graph.insert(INE5406);
	graph.insert(INE5404);
	graph.insert(INE5405);
	graph.insert(INE5409);
	graph.insert(INE5408);
	graph.insert(INE5410);
	graph.insert(INE5411);
	graph.insert(INE5412);
	graph.insert(INE5414);
	graph.insert(INE5417);
	graph.insert(INE5416);
	graph.insert(INE5413);
	graph.insert(INE5415);
	graph.insert(INE5420);
	graph.insert(INE5421);
	graph.insert(INE5419);
	graph.insert(INE5423);
	graph.insert(INE5422);
	graph.insert(INE5418);
	graph.insert(INE5424);
	graph.insert(INE5453);
	graph.insert(INE5427);
	graph.insert(INE5430);
	graph.insert(INE5426);
	graph.insert(INE5425);
	graph.insert(INE5433);
	graph.insert(INE5432);
	graph.insert(INE5429);
	graph.insert(INE5431);
	graph.insert(INE5428);
	graph.insert(INE5434);
	graph.insert(MTM3100);
	graph.insert(MTM3101);
	graph.insert(MTM5512);
	graph.insert(MTM3102);
	graph.insert(MTM5245);
	graph.insert(EEL5105);
	
	cout << "Numero Todal de Disciplinas = " << graph.range() << endl;
	cout << endl << "Ordenamento Topologico:" << endl << endl;

	graph.connect(MTM3100, MTM3101);
	graph.connect(MTM3101, INE5405);
	graph.connect(MTM3101, MTM3102);
	graph.connect(INE5403, INE5413);
	graph.connect(INE5403, INE5415);
	graph.connect(INE5403, INE5429);
	graph.connect(INE5402, INE5404);
	graph.connect(EEL5105, INE5406);
	graph.connect(INE5405, INE5425);
	graph.connect(INE5405, INE5430);
	graph.connect(MTM3102, INE5409);
	graph.connect(MTM3102, INE5420);
	graph.connect(MTM5512, INE5409);
	graph.connect(MTM5512, MTM5245);
	graph.connect(INE5404, INE5408);
	graph.connect(INE5404, INE5410);
	graph.connect(INE5404, INE5414);
	graph.connect(INE5406, INE5411);
	graph.connect(INE5407, INE5428);
	graph.connect(MTM5245, INE5420);
	graph.connect(INE5408, INE5413);
	graph.connect(INE5408, INE5415);
	graph.connect(INE5408, INE5416);
	graph.connect(INE5408, INE5417);
	graph.connect(INE5408, INE5420);
	graph.connect(INE5408, INE5423);
	graph.connect(INE5410, INE5412);
	graph.connect(INE5411, INE5412);
	graph.connect(INE5415, INE5421);
	graph.connect(INE5413, INE5430);
	graph.connect(INE5416, INE5430);
	graph.connect(INE5417, INE5419);
	graph.connect(INE5417, INE5427);
	graph.connect(INE5417, INE5453);
	graph.connect(INE5423, INE5432);
	graph.connect(INE5427, INE5433);
	graph.connect(INE5453, INE5433);
	graph.connect(INE5433, INE5434);
	graph.connect(INE5414, INE5422);
	graph.connect(INE5414, INE5431);
	graph.connect(INE5414, INE5418);
	graph.connect(INE5414, INE5429);
	graph.connect(INE5421, INE5426);
	graph.connect(INE5412, INE5418);
	graph.connect(INE5412, INE5424);

	list<Discipline *> ordering;

	ordering = graph.topologicalOrdering();

	for (auto & node: ordering)
		cout << node->mName << " - ";

	cout << endl;

}

void secondExercise(int maxCredits)
{
	Graph< Discipline * > graph;

	Discipline * INE5420 = new Discipline("INE5420", 4);
	Discipline * INE5421 = new Discipline("INE5421", 4);
	Discipline * INE5419 = new Discipline("INE5419", 4);
	Discipline * INE5423 = new Discipline("INE5423", 4);
	Discipline * INE5422 = new Discipline("INE5422", 4);
	Discipline * INE5418 = new Discipline("INE5418", 4);
	Discipline * INE5424 = new Discipline("INE5424", 4);
	Discipline * INE5453 = new Discipline("INE5453", 1);
	Discipline * INE5427 = new Discipline("INE5427", 4);
	Discipline * INE5430 = new Discipline("INE5430", 4);
	Discipline * INE5426 = new Discipline("INE5426", 4);
	Discipline * INE5425 = new Discipline("INE5425", 4);
	Discipline * INE5433 = new Discipline("INE5433", 6);
	Discipline * INE5432 = new Discipline("INE5432", 4);
	Discipline * INE5429 = new Discipline("INE5429", 4);
	Discipline * INE5431 = new Discipline("INE5431", 4);
	Discipline * INE5428 = new Discipline("INE5428", 4);
	Discipline * INE5434 = new Discipline("INE5434", 9);


	graph.insert(INE5420);
	graph.insert(INE5421);
	graph.insert(INE5419);
	graph.insert(INE5423);
	graph.insert(INE5422);
	graph.insert(INE5418);
	graph.insert(INE5424);
	graph.insert(INE5453);
	graph.insert(INE5427);
	graph.insert(INE5430);
	graph.insert(INE5426);
	graph.insert(INE5425);
	graph.insert(INE5433);
	graph.insert(INE5432);
	graph.insert(INE5429);
	graph.insert(INE5431);
	graph.insert(INE5428);
	graph.insert(INE5434);
	
	cout << endl << "Numero Todal de Disciplinas que faltam = " << graph.range() << endl;

	graph.connect(INE5423, INE5432);
	graph.connect(INE5427, INE5433);
	graph.connect(INE5453, INE5433);
	graph.connect(INE5433, INE5434);
	graph.connect(INE5421, INE5426);


	Graph<Discipline *> auxGraph = graph;
	list< unordered_set<Discipline *> > semesters;
	semesters.push_front(unordered_set<Discipline *>{});
	int counter = maxCredits;

	while (auxGraph.range()) {

		unordered_set<Discipline *> font = auxGraph.fonts();
		
		for (auto disp: font) {
			counter -= disp->mCredit;

			if (counter >= 0) {				
				auxGraph.remove(disp);
				semesters.back().emplace(disp);

			} else {

				counter = maxCredits;
				semesters.push_back(unordered_set<Discipline *>{});
				break;
			}
		}
	}

	counter = 5;
	for (auto & sem: semesters) {
		cout << endl << "Semestre: " << counter++ << endl << "Disciplinas: ";
		for (auto & disp: sem)
			cout << disp->mName << " - ";
	}

	cout << endl;
}