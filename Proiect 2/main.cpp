#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

unordered_map<char, vector<string>>umap; // folosit pentru a retine productiile
string cuv; // cuvantul generat de gramatica
int lung,productii; // lung reprezinta dimensiunea cuv generate, productii este numarul de productii

bool afisare(){
	for(int i = 0; i < cuv.size(); ++i){
		if(cuv[i] >= 65 && cuv[i] <= 90) // Daca inca mai am neterminale in cuvant, nu il afisez
			return false;
	}
	for(int i = 0; i < cuv.size(); ++i){
		if(cuv[i] != '#') // nu afisez lambda
			fout << cuv[i];
	}
	fout << '\n';
	return true;
}

int sizecuv(){ // am avut nevoie de o functie care sa imi spuna cat de lung este cuvantul in afara de neterminale si lambda
	int temp = cuv.size();
	for(int i = 0; i < cuv.size(); ++i){
		if((cuv[i] >= 'A' && cuv[i] <= 'Z') || cuv[i] == '#'){ 
			temp--;
		}
	}
	return temp;
}

void bkt(){
	if(sizecuv() == lung){ // daca cuvantul este de dimensiune n, pot sa incerc sa il afisez
		if(afisare() == true) // doar in cazul in care am reusit intr-adevar sa il afisez ma pot intoarce in recursivitate
			return;
	}
	if(sizecuv() > lung) // daca deja a depasit n, este clar ca nu voi ajunge la un cuvant generat de dimensioune n
		return;
	for(int i = 0; i < cuv.size(); ++i){ // verific toate productiile, care pleaca din neterminalul gasit
		if(cuv[i] >= 'A' && cuv[i] <= 'Z'){
			char lit = cuv[i];
			string cop = cuv;
			cuv.erase(i, 1);
			for(int j = 0; j < umap[lit].size(); ++j){
				cuv.insert(i, umap[lit][j]);
				bkt();
				cuv.erase(i, umap[lit][j].size());
			}
		}
	}
}

int main(){
	fin >> lung >> productii;
	for(int i = 0; i < productii; ++i){
		char c;
		string s;
		fin >> c;
		fin >> s;
		umap[c].push_back(s);
	}
	cuv.push_back('S'); // neterminalul de start
	bkt();
}