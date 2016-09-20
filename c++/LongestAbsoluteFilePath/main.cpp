#include <string>
#include <map>
#include <iostream>
using namespace std;

int lengthLongestPath(string input){

}

int main(int argc, char const *argv[])
{
	string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	cout << input << endl;
	cout << lengthLongestPath(input) << endl;
	return 0;
}