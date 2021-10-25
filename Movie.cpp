#include "Movie.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


Movie::Movie(){
    Id = 0;
    name = "";
    releaseDate = "";
    rating = 0.0;
    }
    
Movie::Movie(int id, string movieName, string movieReleaseDate , double moviesRating){
    Id = id;
    name= movieName;
    releaseDate= movieReleaseDate;
    rating= moviesRating;
    }

int Movie::getId(){
    return Id;

}
string Movie::getName(){
    return name;
}

string Movie::getReleaseDate(){
    return releaseDate;
}

int Movie::getRating(){
    return rating;
}

void Movie::display(){
    cout << left
         << setw(3) << Id       
         << setw(26) << name
         << setw(12) << releaseDate
         << fixed << rating
         << endl;
}
