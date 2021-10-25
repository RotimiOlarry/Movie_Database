#include <iostream>
#include <fstream>
#include <iomanip>
#include "Movie.h"

using namespace std;

void readMovies(ifstream &min, Movie movies[], int &size);           // Function to read movies
void displayMovies(Movie movies[], int SIZE);                        // This function display members of the movie array
void sortByDateRating(Movie movies[], int SIZE);                     // Sorting class members by Date and later by rating
void sortById(Movie movies[], int SIZE);                             // Function that initiates sort by ID
int linearSearchByName(Movie movies[], int SIZE, string targetName); // Function implementing a linear search of class members
int binarySearchById(Movie movies[], int SIZE, int targetId);
void displayMenu();
void displayHeader();
int searchById(Movie movies[], int SIZE, int targetId);

void displayMovies(Movie movies[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        movies[i].display();
    }
}
void sortByDateRating(Movie movies[], int SIZE) // Double search function that first sorts by Date and next by rating
{
    int i;
    int j;
    int indexSmallest;
    Movie temp; // Use as a temporal store measure

    for (i = 0; i < SIZE - 1; ++i)
    {
        indexSmallest = i;
        for (j = i + 1; j < SIZE; ++j)
        {

            if (movies[j].getReleaseDate() ==
                    movies[indexSmallest].getReleaseDate() &&
                movies[j].getRating() > movies[indexSmallest].getRating())
            {
                indexSmallest = j;
            }

            if (movies[j].getReleaseDate() <
                movies[indexSmallest].getReleaseDate())
            {
                indexSmallest = j;
            }
        }
        //Swap movies[i] and movies[indexSmallest]
        //swapping their positions in the array
        temp = movies[i];
        movies[i] = movies[indexSmallest];
        movies[indexSmallest] = temp;
    }
}

int binarySearchById(Movie movies[], int SIZE, int targetId) // Implementation of a binary search on members of class Movie
{

    int mid;
    int low;
    int high;

    low = 0;
    high = SIZE - 1;

    while (high >= low)
    {
        mid = (high + low) / 2;
        if (movies[mid].getId() < targetId)
        {
            low = mid + 1;
        }
        else if (movies[mid].getId() > targetId)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1; // if item targeted not found
}
int searchById(Movie movies[], int SIZE, int targetId)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (movies[i].getId() == targetId)
        {
            return i;
        }
    }
    return -1; // not found
}

void sortById(Movie movies[], int SIZE) //Implementation of a sort function making use of
                                        //insertion sort to sort id's of movies
{
    int i;
    int j;
    Movie temp;

    for (i = 1; i < SIZE; ++i)
    {
        j = i;
        while (j > 0 && movies[j].getId() < movies[j - 1].getId())
        {
            temp = movies[j];
            movies[j] = movies[j - 1];
            movies[j - 1] = temp;
            --j;
        }
    }
}

int linearSearchByName(Movie movies[], int SIZE, string targetName) // Searching movie names using linear sort
{
    for (int i = 0; i < SIZE; i++)
    {
        if (movies[i].getName() == targetName)
        {
            return i;
        }
    }
    return -1;
}

void readMovies(ifstream &min, Movie movies[], int &size) // Function reads movie from txt file into an instance of movie class
{
    int id;
    string name;
    string realeaseDate;
    double rating;
    int counter = 0;

    while (min >> id)
    {
        min >> ws; //skips whitespace (newline) in file after the id
        getline(min, name);
        min >> realeaseDate;
        min >> rating;
        //cout << id << " " << name << " " << realeaseDate << " " << rating << endl;
        movies[counter] = Movie(id, name, realeaseDate, rating);
        ++counter;
    }
    size = counter;
}
void displayMenu() // Function that displays the menu of our program
{
    cout << "\nMenu\n"
         << "1. Display movies sorted by id\n"
         << "2. Display movies sorted by release date, then rating\n"
         << "3. Lookup a release date given a name\n"
         << "4. Lookup a movie by id\n"
         << "5. Quit the Program\n"
         << "Enter your choice:\n";
}
void displayHeader() // Given code that displays header for return search
{
    cout << left
         << setw(3) << "ID"
         << setw(26) << "Name"
         << setw(12) << "Date"
         << "Rating"
         << endl;
}

int main()
{
    int SIZE = 100;

    int choice;
    int index;

    bool loop_end = false;

    string sInput;

    Movie movie[SIZE];

    ifstream min;

    min.open("movies.txt");

    readMovies(min, movie, SIZE);

    do
    {
        displayMenu();
        cin >> choice;

        while (choice < 1 || choice > 5 )
        {
            cout << "Please enter 1, 2, 3, 4, or 5:" << endl;

            cin >> choice;
        }

        switch (choice)
            while (loop_end != true)
            {
            case 1:
                cout << fixed << setprecision(1);

                sortById(movie, SIZE);
                displayHeader();
                displayMovies(movie, SIZE);
                loop_end = false;
                cout << endl;
                break;

            case 2:
                cout << fixed << setprecision(1);

                sortByDateRating(movie, SIZE);
                displayHeader();
                displayMovies(movie, SIZE);
                loop_end = false;
                cout << endl;
                break;

            case 3:
                cout << "Please enter a movie name:" << endl;

                cin >> ws;
                getline(cin, sInput);

                index = linearSearchByName(movie, SIZE, sInput);

                if (index == -1)
                    cout << "No movie found with name: " << sInput << endl <<endl;

                else
                {
                    cout << "Release date of '" << sInput << "' is "
                         << movie[index].getReleaseDate() << endl;
                }
                cout << endl;
                loop_end = false;

                break;

            case 4:
                cout << fixed << setprecision(1);

                cout << "Please enter a movie id:" << endl;

                cin >> choice;

                index = searchById(movie, SIZE, choice);

                if (index == -1)
                {
                    cout << "No movie found with id: " << choice << endl;
                }

                else
                {
                    displayHeader();
                    movie[index].display();
                }
                cout << endl;
                loop_end = false;

                break;

            case 5:
                cout << "Exiting the program..." << endl;
                loop_end = true;
            }
        min.close();
    } while (choice >= 1 && choice <= 4 );
}