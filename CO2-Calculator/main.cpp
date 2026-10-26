
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Function to get travel information
void getTravelData(double &distance, int &transport) {
    cout << "Enter distance travelled in kilometres: ";

    while (!(cin >> distance) || distance < 0) {
        cout << "Invalid distance. Enter a number greater than or equal to 0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nChoose your transport:\n";
    cout << "1. Car\n";
    cout << "2. Bus\n";
    cout << "3. Train\n";
    cout << "Enter your choice (1-3): ";

    while (!(cin >> transport) || transport < 1 || transport > 3) {
        cout << "Invalid choice. Enter 1, 2 or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Function to calculate estimated CO2 emissions
double calculateCO2(double distance, int transport) {
    double emissionFactor;

    switch (transport) {
        case 1:
            emissionFactor = 0.170;
            break;
        case 2:
            emissionFactor = 0.105;
            break;
        case 3:
            emissionFactor = 0.035;
            break;
        default:
            return -1;
    }

    return distance * emissionFactor;
}

// Function to display the result
void displayResult(double emissions) {
    cout << fixed << setprecision(2);
    cout << "\nEstimated CO2 emissions: "
         << emissions << " kg CO2\n";
}

int main() {
    double distance;
    int transport;

    cout << "===== CO2 CALCULATOR =====\n";

    getTravelData(distance, transport);

    double emissions = calculateCO2(distance, transport);

    if (emissions >= 0) {
        displayResult(emissions);
    } else {
        cout << "Unable to calculate emissions.\n";
    }

    return 0;
}
