
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

using namespace std;

struct Joke {
    string question;
    string answer;
};

vector<Joke> loadJokes(const string& filename) {
    vector<Joke> jokes;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << endl;
        return jokes;
    }

    string line;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        // Find the question mark separating question and answer.
        size_t pos = line.find('?');

        if (pos != string::npos && pos + 1 < line.length()) {
            string question = line.substr(0, pos + 1);
            string answer = line.substr(pos + 1);

            jokes.push_back({question, answer});
        }
    }

    return jokes;
}

int main() {
    vector<Joke> jokes = loadJokes("alexa.txt");

    if (jokes.empty()) {
        cout << "No jokes found. Check alexa.txt." << endl;
        return 1;
    }

    random_device rd;
    mt19937 generator(rd());

    uniform_int_distribution<int> distribution(
        0, static_cast<int>(jokes.size()) - 1
    );

    int lastJoke = -1;
    string choice;

    cout << "==============================" << endl;
    cout << "      ALEXA TELL ME A JOKE" << endl;
    cout << "==============================" << endl;

    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Tell me a joke" << endl;
        cout << "2. Show number of jokes" << endl;
        cout << "3. Exit" << endl;
        cout << "Your choice: ";

        if (!getline(cin, choice)) {
            break;
        }

        if (choice == "1") {
            int index = distribution(generator);

            // Avoid repeating the previous joke.
            if (jokes.size() > 1) {
                while (index == lastJoke) {
                    index = distribution(generator);
                }
            }

            lastJoke = index;

            cout << "\nQuestion: "
                 << jokes[index].question << endl;

            cout << "Answer: "
                 << jokes[index].answer << endl;

        } else if (choice == "2") {
            cout << "\nTotal jokes: "
                 << jokes.size() << endl;

        } else if (choice == "3") {
            cout << "\nGoodbye!" << endl;
            break;

        } else {
            cout << "\nInvalid option. Please choose 1, 2 or 3."
                 << endl;
        }
    }

    return 0;
}
