#include <iostream>
#include <string>
using namespace std;

int main() {
    string fever, cough, soreThroat;

    cout << "Welcome to the Medical Expert System\n";
    cout << "Please answer with yes or no.\n";

    cout << "Do you have a fever? ";
    cin >> fever;

    cout << "Do you have a cough? ";
    cin >> cough;

    cout << "Do you have a sore throat? ";
    cin >> soreThroat;

    if (fever == "yes" && cough == "yes" && soreThroat == "yes") {
        cout << "You might have FLU. Please consult a doctor.\n";
    } 
    else if (fever == "yes" && cough == "yes") {
        cout << "You might have a viral infection.\n";
    } 
    else if (cough == "yes" && soreThroat == "yes") {
        cout << "You might have a throat infection.\n";
    } 
    else {
        cout << "Symptoms not conclusive. Stay hydrated and rest.\n";
    }

    return 0;
}
