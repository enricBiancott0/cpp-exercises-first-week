#include<iostream>
#include<string>
#include<vector>		
#include<algorithm> // used for sorting

using namespace std;

/* Es 2
* 
* Write a function print() that prints a vector of ints to cout.
* Give it two arguments: a string for "labelling" the output
* and a vector.
*/
void print(string label, vector<int> a) {
	cout << "\n";
	for (int i = 0; i < a.size(); i++) {
		cout << label << a[i]<< "\n";
	}
	cout << "\n";
}

/* Es 3
* 
* Create a vector of Fibonacci numbers and print them using the
* function from exercise 2. To create the vector, write a function,
* fibonacci(x, y, v, n), where integers x and y are ints, v is an empty vector<int>,
* and n is the number of elements to put into v; v[0] will be x and v[1] will be y.
* A element is the sum of two previous ones. For example, starting
* with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, ... 
* Your fibonacci() function should make such a sequence starting with its x and y arguments.
*/
void fibonacci(int x, int y, vector<int>& v, int n) {
	if (v.size() < n) { // parse input parameters
		return;
	}
	v[0] = x;
	v[1] = y;
	for (int i = 2; i < n; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
}


/* Es 4
* 
* An int can hold integers only up to a maximum number. 
* Find an approximation of that maximum number by using fibonacci().
*
* An int can store up to 2^31, playing with the dimension of fibonacci() vector, 
* the 46th number of fibonacci sequence genereate overflow so the 45th number of the 
* Fibonacci sequence is an approximation of INT_MAX
*/
void findFibonacciIntMax() {
	vector<int> vi(46); // vettore da passare a fibonacci(x, y, v, n)
	fibonacci(1, 2, vi, vi.size());
	cout << "\n\n" << vi[44] << " e' l'elemento della serie di fibonacci che approssima INT_MAX (" << INT_MAX << ")";
}


/* Es 5 pt 1
* 
* Write a function that reverse the order of elements in a
* vector<int>. For example: 1, 3, 5, 7, 9, becomes 9, 7, 5, 3, 1.
* The first revers function should produce a new vector with the
* reversed sequence, leaving its original vector unchanged.
*/
vector<int> reverseUnchanged(const vector<int>& v) {
	vector<int> reversed(v.size());		// vettore di supporto
	for (int i = 0; i < v.size(); i++) {
		reversed[i] = v[v.size() - i - 1];
	}
	return reversed;
}

/* Es 5 pt 2
*
* Write a function that reverse the order of elements in a
* vector<int>. For example: 1, 3, 5, 7, 9, becomes 9, 7, 5, 3, 1.
* 
* The other reverse function sould reverse the elements of its vector without
* using any other vectors.
*/
void reverseChanged(vector<int>& v) {
	int temp;		// variabile temporanea usata per scambiare 2 elementi
	for (int i = 0; i < v.size()/2; i++) {
		temp = v[i];
		v[i] = v[v.size() - i - 1];
		v[v.size() - i - 1] = temp;
	}
}


/* Es 6
* 
* Design and implement a Name_pairs class holding (name, age) pairs where name 
* is a string and age is a double.
* Represent that as a vector<string> (called name) and a vector<double> (called age) member.
* Provide an input operation read_names() that reads a series of names 
* (you can choose how to stop the input series).
* Provide a read_ages() operation that prompts the user for an age for each name,
* Provide a print() operation that prints out the (name[i], age[i]) pairs 
* (one per line) in the order determined by the name vector.
*/
class Name_pairs {
public:
	void read_names();	// read names from std::cin
	void read_ages();	// read ages from std::cin of names
	void print();		// print sorted pairs: (name[i], age[i])
private:
	vector<string> name;
	vector<double> age;
};

/* Read names
* 
* Provide an input operation read_names() 
* that reads a series of names (you can choose how to stop the input series)
*/
void Name_pairs::read_names() {
	string nome;
	bool notQuitting = true;
	cout << "\n\nInserisci un nome per volta, per confermare premi il tasto INVIO\nPer uscire dal ciclo scrivere \"quit\"\n";
	// cicla per vero fino a che non viene inserito "quit"
	while (notQuitting) {
		cout << "\nInserisci un nome: ";
		cin >> nome;
		notQuitting = nome != "quit";
		// se è stato letto "quit" non salva il nome
		if (notQuitting)
			name.push_back(nome);
	}
}

/* Read ages
* 
* Provide a read_ages() operation that prompts the user for an age for each name
*/
void Name_pairs::read_ages() {
	double eta;
	cout << "\n\nInserisci per ogni nome l'eta' corrispondente, per confermare premi il tasto INVIO\n";
	for (int i = 0; i < name.size(); i++) {
		cout << "\nInserisci eta' di " << name[i] << ": ";
		cin >> eta;
		age.push_back(eta);
	}
};

/* Print
* 
* Provide a print() operation that prints out the (name[i], age[i]) pairs 
* (one per line) in the order determined by the name vector
*/
void Name_pairs::print() {
	vector<string> name_copy = name;
	vector<double> age_copy = age;

	// std::sort(first, last, policy, comp);
	// Sort the elements in the range [first,last]
	// See for more a https://en.cppreference.com/w/cpp/algorithm/sort
	std::sort(name.begin(),name.end());
	
	// n indice per i nomi
	for (int n = 0; n < name.size(); n++) {
		// e indice per l'eta
		for (int e = 0; e < age.size(); e++) {
			if (name[n] == name_copy[e]) {
				age[n] = age_copy[e];
			}
		}
	}
	
	cout << "\n\nStampa ordinata sul campo Nome\n";
	// stampa coppie ordinate: nome - eta
	for (int i = 0; i < name.size(); i++) {
		cout << "\nNome: " << name[i] << "- Eta': " << age[i] << "\n";
	}
	cout << "\n\n";
}






//----------------------------------- MAIN------------------------------------






int main() {
	// crea vettore di interi da passare a fib (Es 3)
	vector<int> fib(10);
	fibonacci(1, 2, fib, fib.size());
	
	// stampa a schermo contenuto di fib con Es 2
	print("Fibonacci: ",fib);

	// crea vettore di interi e riempe con fib in ordine inverso (Es 5 pt 1)
	vector<int> reverse_fib = reverseUnchanged(fib);
	
	// stampa a schermo contenuto di reverse_fib 
	print("Reverse unchanged fib: ", reverse_fib);

	// chiamata a funzione reverseChanged (Es 5 pt 2)
	reverseChanged(fib);
	// stampa a schermo contenuto di fib che ora è in ordine inverso
	print("Reverse changed fib: ", fib);

	// chiamata a funzione che approssimi la serie di fibonacci a INT_MAX = 2^31 (Es 4)
	findFibonacciIntMax();

	cout << "\n";

	// istanza classe coppia (Es 6)
	Name_pairs coppia;
	coppia.read_names();
	coppia.read_ages();
	coppia.print();

	return 0;
}