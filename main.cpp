#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

ifstream fin("input.txt");

int edgesCount; // Numarul de Muchii 
int finalNodesCount; // Numarul de stari finale
int startingNode; // Starea initiala
int vertices; // Folosit pentru numarul de noduri
vector< pair<int,char> > edges[500]; // Lista de adiacenta
vector<int> finalNodes; // Un Vector in care tin nodurile finale
bool accepted = false; 
string word; // Un string pentru cuvantul citit
int position = 0; // folosit pentru pozitia in cuvant
vector<int> path; // Vector pentru ruta gasita
int wordCount; // numarul de cuvinte ce trebuie prelucrate

void dfs(int nod){
	if(count(finalNodes.begin(),finalNodes.end(),nod) && position >= word.length()){ 
		// Daca cuvantul se afla printre nodurile finale si l-am parcurs pe tot acesta este acceptat 
		accepted = true;
		return;
	}
	else if(position >= word.length()){
		// Daca am ajuns la final dar nu este printre nodurile finale acesta nu este acceptat
		return;
	}
	for(int i = 0; i < edges[nod].size(); ++i){ // parcurg toate muchiile care pleaca din nodul pe care sunt eu acum
		if(edges[nod][i].second == word[position]){ //verific sa fie aceeasi litera pe muchie ca si cea din cuvant unde am ajuns
			position++; //trec pe pozitia urmatoare in cuvant
			path.push_back(edges[nod][i].first); // adaug nodul in ruta
			dfs(edges[nod][i].first); // apelez recursiv dfs pentru urmatorul nod
			if(accepted == true) // pentru a nu mai verifica dupa ce deja este acceptat, ies din toate instantele functiei
				return;
			path.pop_back(); // scot nodul din ruta daca nu ies din instanta
			position--; // ma intorc pe pozitia anterioara din cuvant
		}
	}
}

int main(){
	int x,y;
	char c; // Variabile folosite la citirea muchiilor
	fin >>  vertices;
	fin >> edgesCount;
	for(int i = 0; i < edgesCount; ++i){ // Citesc muchiile
		fin >> x >> y >> c;
		edges[x].push_back(make_pair(y,c));
	}
	fin >> startingNode;
	fin >> finalNodesCount;
	for(int i = 0; i < finalNodesCount; ++i){ // Citesc starile finale
		fin >> x;
		finalNodes.push_back(x);
	}
	fin >> wordCount;
	for(int j = 0; j < wordCount; j++){ // citesc fiecare cuvant si il parcurg
		fin >> word;
		cout << '\n';
		cout << word << '\n';
		path.clear();
		accepted = false;
		position = 0;
		dfs(startingNode);
		if(accepted==true){
			cout << "cuvantul este acceptat\n";
			cout << startingNode << ' ';
			for(int i = 0; i < path.size(); i++)
				cout << path[i] << ' ';
			cout << '\n';
		}
		else
			cout << "cuvantul nu este acceptat\n";
	}
	cout << '\n';
}