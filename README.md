# Movie Database Management System

## Overview

The **Movie Database Management System** is a C-based application designed to manage a collection of movies. Users can view, search, add, update, and delete movie entries from a text-based database. This system differentiates between admin and user functionalities, providing different access levels for each.

## Features

- **Admin Functions**:
  - Display all movies
  - Search movies by title, director, or year
  - Add new movies
  - Update existing movie details
  - Delete movies

- **User Functions**:
  - Display all movies
  - Search movies by title, director, or year
  - Exit the system

## Getting Started

### Prerequisites

- C Compiler (GCC)
- IDE (Code::Blocks)

### Installation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/moviedb.git
   cd moviedb
   ```

2. **Compile the Code**

   ```bash
   gcc -o movie_db movie_db.c
   ```

3. **Run the Application**

   ```bash
   ./movie_db
   ```

### Usage

1. **Start the Application**

   Upon starting, you will be prompted to choose your login type:
   - **Admin**: For administrative tasks like adding, updating, or deleting movies.
   - **User**: For viewing and searching movies.

2. **Admin Functions**

   Once logged in as an admin, you can:
   - Display all movies
   - Search for movies by title, director, or year
   - Add a new movie
   - Update an existing movie
   - Delete a movie

3. **User Functions**

   As a user, you can:
   - Display all movies
   - Search for movies by title, director, or year
   - Exit the system

### File Format

- The `movie_db.txt` file should contain movie entries in the following format:
  
  ```
  Movie Name,Director Name,Year,Genre,Review
  ```

### License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### Acknowledgements

- **Inspiration**: This project is inspired by various database management systems and movie catalog applications.
- **Support**: Thanks to the open-source community for the resources and tools used in this project.
