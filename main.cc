#include <iostream>

#include "2038.Remove_Colored_Pieces_if_Both_Neighbors_are_the_Same_Color.hpp"

int main() {
    using namespace std;

    lc::Solution sol{};

    if (sol("AAABABB"))
        cout << "Alice wins" << endl;
    else
        cout << "Bob wins" << endl;
    cout << endl;
}