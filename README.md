# Movie-Database
C Project Report: Tentkotta Movie Database

Author:   1.PARIKSHIT.V   (23PD24)
	        2.MOHAN DRAVID.R(23PD20)
Date:     20/10/2023

Introduction

The "Tentkotta Movie Database" project is a C program that serves as a movie database application. The application allows users to perform various operations, including displaying all movies, searching for movies by title or director, and adding new movies to the database (admin access only). The program uses a menu-based interface to provide these functionalities.

Project Structure

The project consists of the following components:
1. Data Structure: The core data structure used in this program is a struct named `Movie`, which stores information about movies, including the name, director, year, genre, and review. The program maintains an array of `Movie` structures.

2. File I/O: The program reads movie information from external text files and populates the `Movie` structure with data. It uses the following text files: "name.txt," "director.txt," "year.txt," "genre.txt," and "review.txt."

3. User Interface: The program provides a text-based menu interface for users to interact with the database. Users can choose from the following options:

   - Display all movies
   - Search for a movie by title
   - Search for a movie by director
   - Add a new movie (admin access only)
   - Exit the program

Program Execution

The program begins by reading data from external text files into the `Movie` structure. This allows it to initialize the movie database. The program then displays a welcome message and the main menu.

Display All Movies (Option 1)

This option allows users to view a list of all movies stored in the database. It displays movie information in a tabular format, including the name, director, year, genre, and review.

Search for a Movie by Title (Option 2)

Users can search for a movie by its title. The program prompts the user to enter the movie's name, and it performs a case-insensitive search. If a matching movie is found, its details are displayed.

Search for a Movie by Director (Option 3)

Similar to the title search, users can search for a movie by its director. The program prompts the user to enter the director's name and displays all movies directed by that individual.

Add a New Movie (Option 4, Admin Access)

To add a new movie, the program first prompts the user for a password. If the correct password is entered ("tkdb" in this case), the user is allowed to enter details for a new movie, including name, director, genre, year, and review. The data is appended to the respective text files, and the database is updated.

Exit the Program (Option 5)

This option allows users to exit the program gracefully with a thank-you message.

Conclusion

The "Tentkotta Movie Database" project is a simple yet functional C program that demonstrates the use of file I/O and data structures to manage a movie database. Users can interact with the database through a menu-based interface, making it easy to access movie information, search for specific movies, and even add new entries to the database with admin access.
