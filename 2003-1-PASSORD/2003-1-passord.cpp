#include <iostream>
#include <map>
#include <string>
#include <sys/types.h>
#include <cmath>

using namespace std;

map<char, int> SearchSpace1;
map<char, int> SearchSpace2;

int64_t worstcase(int x) {
    if(x == 1) {
        return SearchSpace1.size();
    } else {
        return (SearchSpace1.size() * pow(SearchSpace2.size(), x-1)) + worstcase(x-1); 
    }
}


int main(void) {

    int64_t answer = 0;

    const string abc = "abcdefghijklmnopqrstuvwxyz";
    const string num = "0123456789";
    const string passSpace = num + abc;

    /*
     * Assign the different vaules for each of the letters in the search space.
     */
    {
        int i = 0;
        for(string::const_iterator it=abc.begin(); it != abc.end(); ++it) {
            SearchSpace1[*it] = i;
            ++i;
        }

        // Filling the second workspace
        i = 0;
        for(string::const_iterator it=passSpace.begin(); it != passSpace.end(); ++it) {
            SearchSpace2[*it] = i;
            ++i;
        }
    }

    // Retriving password
    string password;
    cin >> password;

    // If the answer is 1 long, we can just return the value it has in SearchSpace1
    if(password.length() == 1) {
        cout << SearchSpace1[password[0]] << endl;
        return 0;
    }
    
    // The answer must contain the worstcase results of passwords 1 shorter.
    answer += worstcase(password.length() - 1);

    // Here we calculate the rest of the possibilites.

    answer += SearchSpace1[password[0]] * pow(SearchSpace2.size(),password.length() - 1);

    // Now we just have to loop trough to the last possibilites.
    for(unsigned long i = 1; i < password.length(); ++i) {
        answer += SearchSpace2[password[i]] * pow(SearchSpace2.size(), password.length() - 1 - i);
    }

    cout << answer << endl;
    return 0;
}
