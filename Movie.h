
#include <string>
using namespace std;

class Movie                                             // Declaration of class Movie 
{
private:                                                // Declaration of th four class members of class Movie 
    string name;
    string releaseDate;
    int Id;
    double rating;

public:                                                 // Declaration of public members of class Movie 
    Movie();
    Movie(int, string, string, double);
    int getId();
    string getName();
    string getReleaseDate();
    int getRating();
    void display();
};
