#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Rajapintaluokka Writable
class Writable 
{
public:
    virtual void writeState(const string& filename) const = 0;
    virtual ~Writable() {}
};

// Rajapintaluokka Readable
class Readable 
{
public:
    virtual void readState(const string& filename) = 0;
    virtual ~Readable() {}
};

// Oma luokka, joka perii Writable ja Readable 
class MyData : public Writable, public Readable 
{
private:
    int _intValue;
    double _doubleValue;
    string _stringValue;

public:
    // Konstruktori
    MyData(int i, double d, const string& s) : _intValue(i), _doubleValue(d), _stringValue(s) {}

    // Writable rajapinnan toteutus
    void writeState(const string& filename) const override 
    {
        ofstream outputFile(filename);
        if (outputFile.is_open()) {
            outputFile << _intValue << " " << _doubleValue << " " << _stringValue << "\n";
            cout << "Tila kirjoitettu tiedostoon: " << filename << "\n";
        }
        else {
            cerr << "Virhe tiedoston avaamisessa!" << "\n";
        }
    }

    // Readable rajapinnan toteutus
    void readState(const string& filename) override 
    {
        ifstream inputFile(filename);
        if (inputFile.is_open()) {
            inputFile >> _intValue >> _doubleValue >> _stringValue;
            cout << "Tila luettu tiedostosta: " << filename << "\n";
        }
        else {
            cerr << "Virhe tiedoston avaamisessa!" << "\n";
        }
    }

    // Metodi tulostamaan luokan tila
    void printState() const 
    {
        cout << "intValue: " << _intValue << ", doubleValue: " << _doubleValue << ", stringValue: " << _stringValue << "\n";
    }
};

int main() 
{
    // Luo olio MyData-luokasta
    MyData myObject(42, 3.14, "Hello, World!");

    // Tallenna olion tila tiedostoon
    myObject.writeState("mydata.txt");

    // Luo uusi olio MyData-luokasta
    MyData anotherObject(0, 0.0, "");

    // Lue olion tila tiedostosta
    anotherObject.readState("mydata.txt");

    // Tulosta luettu tila
    anotherObject.printState();

    return 0;
}
