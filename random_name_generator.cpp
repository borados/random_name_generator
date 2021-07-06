#include <array>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>


using namespace std;


//prvi zadatak
unsigned broj_parova(const int zbroj_koji_se_trazi, std::vector<int>& vect) {
	int counter = 0;
	for (int i = 0; i < vect.size() - 1; i++) {
		for (int j = i; j < vect.size(); j++) {
			if (vect[i] + vect[j] == zbroj_koji_se_trazi)
				counter++;
		}
	}

	return counter;
}

char palatali(int i) {
	if (i == 0)
		return 'z';
	if (i == 1)
		return 's';
	return 'c';
}

//random suglasnici
void suglasnici(int n, std::vector<char> & vect) {
	int a[5];
	int t, prvi;
	int i;
	prvi = rand() % 26 + 65; // da bude veliko slovo i bilo koje iz abecede
	vect.push_back(char(prvi));
	for (i = 0; i < n-1; i++) { //zamjeni x za kusu
		do {
			t = rand() % 26 + 97; //inace 26 ali +3 za sh zh ch
		} while (t == 97 || t == 101 || t == 105 || t == 111 || t == 117); //samoglasnici
		
			vect.push_back(char(t));
		//std::cout << t << std::endl;
		//std::cout << (char)t << std::endl;
	}
} 


//random jedan od njih 5
char rand_samoglasnik() {
	int i = rand() % 5;
	switch (i)
	{
	case 0:
		return 'a';
	case 1:
		return 'e';
	case 2:
		return 'i';
	case 3:
		return 'o';
	case 4:
		return 'u';


	}

}
//print vektora 
void print(std::vector <char> const& a) {
	std::cout << "The vector elements are : ";

	for (int i = 0; i < a.size(); i++)
		std::cout << a.at(i);

	std::cout << std::endl;
}

void print2(std::vector <char> const& a, std::vector <char> const& b) {
	std::cout << "ime i prezime: ";

	for (int i = 0; i < a.size(); i++)
		std::cout << a.at(i);
	std::cout << ' ';
	for (int i = 0; i < b.size(); i++)
		std::cout << b.at(i);

	std::cout << std::endl;
}
// ubaci samoglasnike medu suglasnike
void samoglasnici(int n, std::vector<char>& vect) {
	for (int i = 0; i < n-1; i++) { 
		vect.insert(vect.begin()+ (2 * i + 1), rand_samoglasnik());
	}
}

void zavrsetak(std::vector<char>& vect) {
	int i = rand() % 4;

	if (i = 0) {
		vect.push_back('a');
		vect.push_back('t');
		vect.push_back('o');
	}
	else if (i = 1) {
		vect.push_back('u');
		vect.push_back('k');
		vect.push_back('i');
	}
	else if (i = 2) {
		vect.push_back('i');
		vect.push_back('z');
		vect.push_back('u');
	}
	else 
		vect.push_back(' ');
	
}

void zavrsetak2(std::vector<char>& vect) {
	int i = rand() % 4;

	if (i = 0) {
		vect.push_back('-');
		vect.push_back('s');
		vect.push_back('a');
		vect.push_back('m');
		vect.push_back('a');
	}
	else if (i = 1) {
		vect.push_back('-');
		vect.push_back('k');
		vect.push_back('u');
		vect.push_back('n');
	}
	else if (i = 2) {
		vect.push_back('-');
		vect.push_back('s');
		vect.push_back('a');
		vect.push_back('n');
	}
	else
		vect.push_back(' ');

}


int main() {
	std::vector<char> prezime = {};
	std::vector<char> elementi = {};
	std::vector<int> parovi = {1,3,5,7};
	srand(time(nullptr));
	
//	int a[4] = { 1,3,5,7 };

 std::cout << broj_parova(8, parovi) << std::endl;
		 

	
	
		int r;

		for (int i = 0; i < 50; i++) {
			r = rand() % 3 + 3;
			suglasnici(r, elementi);
			samoglasnici(r, elementi);
			zavrsetak(elementi);

			suglasnici(r, prezime);
			samoglasnici(r, prezime);
			zavrsetak2(prezime);

			print2(elementi, prezime);

			elementi.clear();
			prezime.clear();
		}

	return 0;
}
