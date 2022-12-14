#pragma once
#include "Directory.h"
#include <vector>
class MRUfunction {
private:
	vector<char> frame;
	void guardar(Directory d);
	string cadena;
	int aux2, tam, aux = 0, cont = 0, page = 0;
public:
	bool comparar(vector<char> com, char val);
	void eli_igual(vector<char>& com);
	void MRU(vector<char>& frame, int size, string cad);
	void mostrar(vector<char>& frame);
};


bool MRUfunction::comparar(vector<char> com, char val) {
	for (int j = 0; j < com.size(); j++) {
		if (com[j] == val) {
			aux2 = j;
			return false;
		}
	}
	return true;
}

void MRUfunction::eli_igual(vector<char>& com) {
	auto eli = com.begin() + aux2;
	com.erase(eli);

}

void MRUfunction::MRU(vector<char>& frame, int size, string cad) {
	for (char& c : cad) {
		if (size > aux) {
			if (comparar(frame, c) == true) {
				frame.push_back(c);
				aux++;
			}
			else {
				eli_igual(frame);
				frame.push_back(c);
				cont++;
			}
		}
		else {
			if (comparar(frame, c) == false) {
				eli_igual(frame);
				frame.push_back(c);
				cont++;
			}
			else {
				frame.pop_back();
				frame.push_back(c);
			}
		}
		page++;
	}
}


void MRUfunction::mostrar(vector<char>& frame) {
	for (int i = 0; i < frame.size(); i++) {
		cout << frame[i] << "-";
	}
}
