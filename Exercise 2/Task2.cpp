//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//// Function to reverse a string in place
//void reverseString(string& str) {
//    int n = str.length();
//    for (int i = 0; i < n / 2; ++i) {
//        swap(str[i], str[n - i - 1]); 
//    }
//}
//
//int main() {
//    string inputFileName = "input.txt";  
//    string outputFileName = "output.txt"; 
//
//    ifstream inputFile(inputFileName);
//    ofstream outputFile(outputFileName);
//
//    if (!inputFile) {
//        cerr << "\nError opening input file." << endl;
//        return 1;
//    }
//
//    string inputString;
//
//    // Read the entire content of the file into inputString
//    getline(inputFile, inputString, '\0'); 
//
//    inputFile.close(); 
//
//    // Reverse the string using the defined function
//    reverseString(inputString);
//
//    // Write the reversed string to the output file
//    outputFile << inputString;
//
//    outputFile.close(); 
//
//    cout << "\nThe reversed string has been written to " << outputFileName << endl;
//
//    return 0;
//}