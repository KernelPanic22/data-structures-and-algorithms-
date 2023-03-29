/*
Code a C++ program, named processes.cpp that receives one argument, (i.e., argv[1]) upon its
invocation and searches how many processes whose name is given in argv[1] are running on
the system where your program has been invoked. To be specific, your program should
demonstrate the same behavior as:
$ ps -A | grep argv[1] | wc -l
Implement processes using the following system calls:
1. pid_t fork( void ); creates a child process that differs from the parent process only in
terms of their process IDs.
2. int execlp( const char *file, const char *arg, ..., (char *)0 ); replaces the current
process image with a new process image that will be loaded from file. The first
argument arg must be the same as file. The last argument is a NULL pointer of type
“char *”.
3. int pipe( int filedes[2] ); creates a pair of file descriptors (which point to a pipe
structure), and places them in the array pointed to by filedes. filedes[0] is for reading
data from the pipe, filedes[1] is for writing data to the pipe.
4. int dup2( int oldfd, int newfd ); creates in newfd a copy of the file descriptor oldfd.
5. pid_t wait( int *status ); waits for process termination
6. int close( int fd ); closes a file descriptor.
*/
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    int filedes[2];
    pipe(filedes);
    int pid = fork();
    if (pid == 0)
    {
        dup2(filedes[1], 1);
        close(filedes[0]);
        close(filedes[1]);
        execlp("ps", "ps", "-A", NULL);
    }
    else
    {
        close(filedes[1]);
        char buffer[100];
        int n = read(filedes[0], buffer, 100);
        buffer[n] = '\0';
        string line = string(buffer);
        istringstream iss(line);
        vector<string> tokens;
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(tokens));
        int count = 0;
        for (auto i : tokens)
        {
            if (i == argv[1])
                count++;
        }
        cout << count << endl;
    }
    return 0;
}

// Path: excercism/rna-transcription.cpp
// Code a C++ program, named rna-transcription.cpp that receives a DNA strand
// as input and returns its RNA complement (per RNA transcription). The program
// should be invoked as:
// $ ./rna-transcription <dna-strand>
// For example, if the input is:
// $ ./rna-transcription AAAACCCGGT
// The output should be:
// $ UUUUGGGCCCA
// The following table summarizes the rules of the transcription:
// DNA RNA
// G C
// C G
// T A
// A U
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    string input = argv[1];
    map<char, char> dna_rna;
    dna_rna['G'] = 'C';
    dna_rna['C'] = 'G';
    dna_rna['T'] = 'A';
    dna_rna['A'] = 'U';
    for (auto i : input)
    {
        cout << dna_rna[i];
    }
    return 0;
}

// Path: excercism/robot-simulator.cpp
// Code a C++ program, named robot-simulator.cpp that receives a list of
// instructions as input and returns the
