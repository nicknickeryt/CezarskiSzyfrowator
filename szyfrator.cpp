#include <iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

int main() {
	string tryb;
	string tekst;
	cout << "Chcesz szyfrować czy odszyfrować? Wpisz \"zaszyfruj\" lub \"odszyfruj\"." << endl;
	getline(cin, tryb);
	string nazwa;
	        
	if (tryb == "zaszyfruj"){
	        cout << "Podaj nazwę pliku" << endl;
        	getline(cin, nazwa);
        	ifstream plik(nazwa);
        	
        	ifstream check;
        	check.open(nazwa);
        	if(!check){
        		cout << "Nie znaleziono pliku!" << endl;
        		return 0;
        	}
        	
		string tekst((istreambuf_iterator<char>(plik)),
             	istreambuf_iterator<char>());
        	string &ciphertext = tekst;
        		
   		for (int i=0; i<ciphertext.size(); i++) {
	                if (isupper(ciphertext[i])){
                	        ciphertext[i] = (ciphertext[i] - 'A' + 3) % 26 + 'A';
        	        }
	                else{
                        	if (isalnum(ciphertext[i])){
                                	ciphertext[i] = (ciphertext[i] - 'a' + 3) % 26 + 'a';
                        	}
                	}
        	}
   		cout <<"Zaszyfrowano i zapisano jako " << nazwa << "_encrypted" << endl;
       		ofstream output(nazwa + "_encrypted");
            	output << ciphertext << endl;
        	output.close();
        	return 0;
	}
	else if (tryb == "odszyfruj"){
	        cout << "Podaj nazwę pliku" << endl;
	        string nazwa;
        	getline(cin, nazwa);
        	ifstream plik(nazwa);
        	
        	ifstream check;
        	check.open(nazwa);
        	if(!check){
        		cout << "Nie znaleziono pliku!" << endl;
        		return 0;
        	}
        	
		string tekst((istreambuf_iterator<char>(plik)),
             	istreambuf_iterator<char>());
        	string &ciphertext = tekst;
        		
   		for (int i=0; i<ciphertext.size(); i++) {
	                if (isupper(ciphertext[i])){
                	        ciphertext[i] = (ciphertext[i] - 'A' - 3) % 26 + 'A';
        	        }
	                else{
                        	if (isalnum(ciphertext[i])){
                                	ciphertext[i] = (ciphertext[i] - 'a' - 3) % 26 + 'a';
                        	}
                	}
        	}
   		cout <<"Odszyfrowano i zapisano jako " << nazwa << "_decrypted" << endl;
       		ofstream output(nazwa + "_decrypted");
            	output << ciphertext << endl;
        	output.close();
        	return 0;
	}
	else{
		cout << "Błąd: Oczekiwano \"zaszyfruj\" lub \"odszyfruj\"." << endl;
		return 0;
	}
}
