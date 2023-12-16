#include<iostream>
#include<iomanip>
using namespace std;

double FindInterest(double lone, double rate) {
    return ((lone * rate) / 100);
}

int main() {
    double lone, rate, pay;
    cout << "Enter initial loan: ";
    cin >> lone;
    cin.ignore();
    cout << "Enter interest rate per year (%): ";
    cin >> rate;
    cin.ignore();
    cout << "Enter amount you can pay per year: ";
    cin >> pay;

    cout << setw(13) << left << "EndOfYear#";
    cout << setw(13) << left << "PrevBalance";
    cout << setw(13) << left << "Interest";
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";

    int i = 1;
    while (true) {
        cout << fixed << setprecision(2);
        cout << setw(13) << left << i;
        cout << setw(13) << left << lone;
        double interest = FindInterest(lone, rate);
        cout << setw(13) << left << interest;
        cout << setw(13) << left << (lone + interest);

        if ((lone + interest) - pay < 0) {
            cout << setw(13) << left << (lone + interest);
            cout << setw(13) << left << "0.00";
            break;
        }
        
        cout << setw(13) << left << pay;
        cout << setw(13) << left << (lone + interest) - pay;
        lone = (lone + interest) - pay;
        cout << "\n";
        i++;
    }
    return 0;
}