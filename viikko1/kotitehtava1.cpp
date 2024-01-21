#include <iostream>
#include <cstdlib>

using namespace std;

int game (int maxnum) {

    std::srand(100);
    int randomiluku = (std::rand() % maxnum) + 1;
    int arvaus;
    int arvausten_maara = 0;


    while (arvaus != randomiluku) {

        cout << "Arvaa luku 1-" << maxnum << ": " << endl;
        cin >> arvaus;

        if (arvaus > randomiluku){
            cout << "Liian Suuri" << endl << endl;
        }
        else if (arvaus < randomiluku) {
            cout << "Liian pieni" << endl << endl;
        }
        else {
            cout << "Arvasit oikein!" << endl;
        }

        arvausten_maara += 1;

    }

    return arvausten_maara;
}

int main() {

    int arvausten_maara = game(30);
    cout << "Arvasit " << arvausten_maara << " kertaa." << endl;
}