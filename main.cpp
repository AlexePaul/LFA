#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

ifstream fin("input.txt");

int vertices; // folosit pentru numarul de noduri
vector< pair<int,char> > edges[500];
vector<int> finalNodes;
bool accepted = false;
string word;
int position = 0; // it is used for the position in the word.
vector<int> path;
int wordCount;

void dfs(int nod){
	if(count(finalNodes.begin(),finalNodes.end(),nod) && position >= word.length()){
		accepted = true;
		return;
	}
	else if(position >= word.length()){
		return;
	}
	bool entered = false;
	for(int i = 0; i < edges[nod].size(); ++i){
		if(edges[nod][i].second == word[position]){
			position++;
			path.push_back(edges[nod][i].first);
			dfs(edges[nod][i].first);
			if(accepted == true)
				return;
			path.pop_back();
			position--;
			entered = true;
		}
	}
}

int main(){
	int edgesCount;
	int finalNodesCount;
	int startingNode;
	int x,y;
	char c; //random variables to read with.
	fin >>  vertices;
	fin >> edgesCount;
	for(int i = 0; i < edgesCount; ++i){
		fin >> x >> y >> c;
		edges[x].push_back({y,c});
	}
	fin >> startingNode;
	fin >> finalNodesCount;
	for(int i = 0; i < finalNodesCount; ++i){
		fin >> x;
		finalNodes.push_back(x);
	}
	fin >> wordCount;
	for(int j = 0; j < wordCount; j++){
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
}