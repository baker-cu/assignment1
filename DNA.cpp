#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream file ("test.txt"); //opens file for reading
    string line;

    while(getline(file, line)){ //iterates through each line of the file
        cout << "printed becuase of a line" <<endl;

    }

    file.close(); //close file when done

    ofstream outfile ("jacobbaker.out"); //creates new file yourname.out

    outfile << "test text" << endl; //prints "test text"
    outfile << "test text 2" << endl;

    return 0;

}
