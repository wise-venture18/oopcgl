// write a program in C++ to use map associative container. The keys will be the 
// names of states and the values will be the populations of the states. When the 
// program runs, the user is prompted to type the name of a state. The program 
// then looks in the map, using the state name as an index and returns the 
// population of the state.

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Create a map to store state names and their populations
    map<string, int> statePopulation;

    // Insert some states and their populations into the map
    statePopulation["California"] = 39538223;
    statePopulation["Texas"] = 29145505;
    statePopulation["Florida"] = 21538187;
    statePopulation["New York"] = 20201249;
    statePopulation["Pennsylvania"] = 13002700;

    string state;
    cout << "Enter the name of a state: ";
    cin >> state;

    // Search for the state in the map
    auto it = statePopulation.find(state);
    if (it != statePopulation.end()) {
        cout << "The population of " << state << " is " << it->second << "." << endl;
    } else {
        cout << "State not found in the database." << endl;
    }

    return 0;
}
