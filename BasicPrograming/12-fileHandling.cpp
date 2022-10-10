/*

Files are used to store data permanently. 
A stream is an abstraction that represents a device on which input and output operations are performed. 
A stream can basically be represented as a source or destination of characters of indefinite length.

Three file handling data types : 
ofstream : This data type represents the output file stream and is used to create files and to write information to files.
ifstream : This data type represents the input file stream and is used to read information from files.
fstream : This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream which means it can create files, write information to files, and read information from files.


*/

#include <fstream>
#include <iostream>
using namespace std;
 
int main () {
    
   char data[100];

   // open a file in write mode.
   ofstream outfile;
   outfile.open("afile.dat");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);

   // write inputted data into the file.
   outfile << data << endl;

   // close the opened file.
   outfile.close();

   // open a file in read mode.
   ifstream infile; 
   infile.open("afile.dat"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 

   // write the data at the screen.
   cout << data << endl;
   
   // close the opened file.
   infile.close();

   return 0;
}
