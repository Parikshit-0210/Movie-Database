#include <stdio.h>
#include <string.h>

struct Movie {
    char name[100];
    char director[100];
    int year;
    char genre[100];
    char review[100];
};

void ClearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void AddToString(int* count, struct Movie Movie[]) {
    FILE* movie = fopen("movie_db.txt", "r");
    if (movie == NULL) {
        printf("File cannot be opened\n");
        return;
    }

    int i = 0;
    while (fscanf(movie, "%99[^,],%99[^,],%d,%99[^,],%99[^\n]\n", Movie[i].name, Movie[i].director, &Movie[i].year, Movie[i].genre, Movie[i].review) != EOF) {
        i++;
    }
    if(ferror(movie)){
        printf("Error: Reading file failed\n");
    }
    fclose(movie);
    *count = i;
}
void logo(){

    printf("***WELCOME TO TENTKOTTA DATABASE***\n\n");
    printf("            *******  *   *\n");
    printf("               *     *  *\n");
    printf("               *     * *\n");
    printf("               *     **\n");
    printf("               *     * *\n");
    printf("               *     *  *\n");
    printf("               *     *   *\n\n");
    printf("''WHERE EVERY MOVIE FINDS ITS SPOTLIGHT: YOUR ULTIMATE MOVIE DATABASE''\n\n");
}
void DisplayAllMovies(int count, struct Movie Movie[]) {
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("NAME\t\t\tDIRECTOR\t\tYEAR\tGENRE\t\t\t\tREVIEW\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int s = 0; s < count; s++) {
        printf("%-18s\t%-23s\t%-6d\t%-25s\t%-30s\n\n", Movie[s].name, Movie[s].director, Movie[s].year, Movie[s].genre, Movie[s].review);
    }
}

void SearchMovieByTitle(int count, struct Movie Movie[]) {
    int moviefound = 0;
    char search[100];
    printf("Enter the Movie name to search: ");
    fgets(search, sizeof(search), stdin);
    search[strlen(search) - 1] = '\0';
    for(int k=0;k< count;k++)
    {
        search[k]=toupper(search[k]);
    }
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("NAME\t\t\tDIRECTOR\t\tYEAR\tGENRE\t\t\t\tREVIEW\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int j = 0; j < count; j++) {
        if (strcmp(Movie[j].name, search) == 0) {
        printf("%-18s\t%-23s\t%-6d\t%-25s\t%-30s\n\n", Movie[j].name, Movie[j].director, Movie[j].year, Movie[j].genre, Movie[j].review);
            moviefound++;
            break;
        }
    }

    if (!moviefound) {
        printf("\nCAN YOU CHECK THE SPELLING ONCE AGAIN (OR) THE ABOVE MOVIE IS NOT UPLOADED YET...\n\n");
    }
}

void SearchMovieByDirector(int count, struct Movie Movie[]) {
    int moviefound = 0;
    char search[100];
    printf("Enter the director name to search: ");
    fgets(search, sizeof(search), stdin);
    search[strlen(search) - 1] = '\0';
    for(int k=0;k< count;k++)
    {
        search[k]=toupper(search[k]);
    }
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("NAME\t\t\tDIRECTOR\t\tYEAR\tGENRE\t\t\t\tREVIEW\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int j = 0; j < count; j++) {
        if (strcasecmp(Movie[j].director, search) == 0) {
        printf("%-18s\t%-23s\t%-6d\t%-25s\t%-30s\n\n", Movie[j].name, Movie[j].director, Movie[j].year, Movie[j].genre, Movie[j].review);
            moviefound++;
        }
    }

    if (!moviefound) {
        printf("\nCAN YOU CHECK THE SPELLING ONCE AGAIN (OR) THE ABOVE DIRECTOR'S MOVIE IS NOT UPLOADED YET...\n\n");
    }
}

void SearchMovieByYear(int count, struct Movie Movie[]) {
    int moviefound = 0;
    int searchnum;
    printf("Enter the year to search: ");
    scanf("%d", &searchnum);
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("NAME\t\t\tDIRECTOR\t\tYEAR\tGENRE\t\t\t\tREVIEW\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int j = 0; j < count; j++) {
        if (Movie[j].year == searchnum) {
        printf("%-18s\t%-23s\t%-6d\t%-25s\t%-30s\n\n", Movie[j].name, Movie[j].director, Movie[j].year, Movie[j].genre, Movie[j].review);
            moviefound++;
        }
    }

    if (!moviefound) {
        printf("\nNO MOVIE FOUND FOR THE YEAR %d\n\n", searchnum);
    }
}

void AddAMovie(int* count, struct Movie Movie[]) {

        int moviefound = 0;
        int i = 0;
        int found=0;
        while (1) {
            printf("\nEnter the Movie name ('end' to end): ");
            fflush(stdin);
            fgets(Movie[*count + i].name, sizeof(Movie[*count + i].name), stdin);
            Movie[*count + i].name[strcspn(Movie[*count + i].name, "\n")] = '\0';
            for(int k=0;k< *count;k++)
            {
                Movie[*count + i].name[k]=toupper(Movie[*count + i].name[k]);
            }
            for(int s=0;s< *count;s++){
                if(strcmp(Movie[s].name,Movie[*count + i].name)==0){
                    found=1;
                    break;
                }
                found=0;
            }
            if(found){
                printf("Movie is already in the Database\n");

            }
            else if (strcmp(Movie[*count + i].name, "END") == 0) {
                break;
            }
            else {
                printf("\nEnter the Director name: ");
                fgets(Movie[*count + i].director, sizeof(Movie[*count + i].director), stdin);
                Movie[*count + i].director[strcspn(Movie[*count + i].director, "\n")] = '\0';
                for(int k=0;k< *count;k++)
                {
                    Movie[*count + i].director[k]=toupper(Movie[*count + i].director[k]);
                }
                printf("\nEnter the Movie Genre: ");
                fgets(Movie[*count + i].genre, sizeof(Movie[*count + i].genre), stdin);
                Movie[*count + i].genre[strcspn(Movie[*count + i].genre, "\n")] = '\0';
                for(int k=0;k< *count;k++)
                {
                    Movie[*count + i].genre[k]=toupper(Movie[*count + i].genre[k]);
                }
                printf("\nEnter the Movie Review: ");
                fgets(Movie[*count + i].review, sizeof(Movie[*count + i].review), stdin);
                Movie[*count + i].review[strcspn(Movie[*count + i].review, "\n")] = '\0';
                for(int k=0;k< *count;k++)
                {
                    Movie[*count + i].review[k]=toupper(Movie[*count + i].review[k]);
                }
                printf("\nEnter the Year released: ");
                scanf("%d", &Movie[*count + i].year);

                i++;
        FILE*movie=fopen("movie_db.txt","a");
        fprintf(movie, "%s,%s,%d,%s,%s\n", Movie[*count].name, Movie[*count].director, Movie[*count].year, Movie[*count].genre, Movie[*count].review);
        fclose(movie);
        *count = *count + i;
            }
        }
}

void UpdateMovie(int count, struct Movie Movie[]) {
    int moviefound = 0;
    int found = 0;
    char search[100];
    char newreview[100];
    char newdirector[100];
    char newgenre[100];
    char review[100];
    int newyear;

    printf("\nEnter the Movie name to update('end' to end): ");
    fgets(search, sizeof(search), stdin);
    search[strlen(search) - 1] = '\0';
    for(int k=0;k< count;k++)
    {
        search[k]=toupper(search[k]);
    }
    for (int i = 0; i < count; i++) {
        if (strcmp(Movie[i].name,search) ==0) {
        printf("Enter the director to update: ");
        fgets(newdirector, sizeof(newdirector), stdin);
        newdirector[strlen(newdirector) - 1] = '\0';
        for(int k=0;k< count;k++)
        {
            newdirector[k]=toupper(newdirector[k]);
        }

            strcpy(Movie[i].director, newdirector);
        printf("Enter the genre to update: ");
        fgets(newgenre, sizeof(newgenre), stdin);
        newgenre[strlen(newgenre) - 1] = '\0';
        for(int k=0;k< count;k++)
        {
            newgenre[k]=toupper(newgenre[k]);
        }

            strcpy(Movie[i].genre, newgenre);
        printf("Enter the review to update: ");
        fgets(newreview, sizeof(newreview), stdin);
        newreview[strlen(newreview) - 1] = '\0';
        for(int k=0;k< count;k++)
        {
            newreview[k]=toupper(newreview[k]);
        }

        strcpy(Movie[i].review, newreview);
        printf("Enter the year to update: ");
        scanf("%d",&newyear);
        Movie[i].year=newyear;
            found = 1; // Movie found and updated
            break;
        }
        found=0;
    }

    if (found) {
        FILE* movie = fopen("movie_db.txt", "w");
        if (movie == NULL) {
            printf("File cannot be opened\n");
        } else {
            // Write the updated data to the file
            for (int i = 0; i < count; i++) {
                fprintf(movie, "%s,%s,%d,%s,%s\n", Movie[i].name, Movie[i].director, Movie[i].year, Movie[i].genre, Movie[i].review);
            }
            fclose(movie);
        }
        printf("Movie updated in the database.\n");
    }
    else if(strcmp(search,"END")==0){
        printf("Update cacelled.\n");
    }
    else {
        printf("Movie not found in the database.\n");
    }

}
void DeleteMovie(int* count, struct Movie Movie[]) {
    int moviefound = 0;
    int found = 0;
    char search[100];
    int i=0;
    while(1){
    printf("\nEnter the Movie name to delete('end' to end): ");
    fgets(search, sizeof(search), stdin);
    search[strlen(search) - 1] = '\0';
    for(int k=0;k< *count;k++)
    {
        search[k]=toupper(search[k]);
    }
    for (int i = 0; i < *count; i++) {
        if (strcmp(Movie[i].name, search) == 0) {
            // Shift elements to fill the gap left by the deleted movie
            for (int j = i; j < (*count - 1); j++) {
                strcpy(Movie[j].name, Movie[j + 1].name);
                strcpy(Movie[j].director, Movie[j + 1].director);
                Movie[j].year = Movie[j + 1].year;
                strcpy(Movie[j].genre, Movie[j + 1].genre);
                strcpy(Movie[j].review, Movie[j + 1].review);
            }
            (*count)--;
            found = 1;
            break;
        }
        found=0;
    }

    if (found) {
        FILE* movie = fopen("movie_db.txt", "w");
        if (movie == NULL) {
            printf("File cannot be opened\n");
        } else {
            // Write the updated data to the file
            for (int i = 0; i < *count; i++) {
                fprintf(movie, "%s,%s,%d,%s,%s\n", Movie[i].name, Movie[i].director, Movie[i].year, Movie[i].genre, Movie[i].review);
            }
            fclose(movie);
        }
        printf("Movie deleted from the database.\n");
    }
    else if(strcmp(search,"END")==0){
        printf("Deletion canceled.\n");
        break;
    }
    else {
        printf("Movie not found in the database.\n");
    }
    i++;
    }
}


// Function to check admin login
int AdminLogin() {
    char username[100];
    char password[100];
    char ch;
    int i=0;
    printf("Admin Login\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    while (1) {
        ch = getch();
        if (ch == 13) {
            password[i] = '\0';
            break;
        } else if (ch == 8) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            password[i] = ch;
            i++;
            printf("*");
        }
    }
    if (strcmp(username, "ADMIN") == 0 && strcmp(password, "tkdb") == 0) {
        return 1; // Admin login successful
    } else {
        return 0; // Admin login failed
    }
}

int main() {
    struct Movie Movie[1000];
    int count = 0;
    AddToString(&count,Movie);
    int choice;
    int isAdmin = 0;
    int isUser = 0;
    logo();
    printf("Choose your login type:\n");
    printf("1. Admin\n");
    printf("2. User\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    ClearInputBuffer();

    if (choice == 1) {
        isAdmin = AdminLogin();
        if (isAdmin) {
            printf("\nAdmin login successful.\n");
        } else {
            printf("\nAdmin login failed. Exiting...\n");
            exit(1);
        }
    } else if (choice == 2) {
        isUser = 1;
        printf("User login successful.\n");
    } else {
        printf("Invalid choice. Exiting...\n");
        exit(1);
    }

    while (1) {
        if (isAdmin) {
            printf("Admin Menu:\n");
            printf("1. Display all movies\n");
            printf("2. Search for a movie by title\n");
            printf("3. Search for a movie by director\n");
            printf("4. Search for a movie by year\n");
            printf("5. Add a movie\n");
            printf("6. Update a movie\n");
            printf("7. Delete a movie\n");
            printf("8. Exit (Admin)\n");
        } else if (isUser) {
            printf("User Menu:\n");
            printf("1. Display all movies\n");
            printf("2. Search for a movie by title\n");
            printf("3. Search for a movie by director\n");
            printf("4. Search for a movie by year\n");
            printf("5. Exit (User)\n");
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
        ClearInputBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                DisplayAllMovies(count, Movie);
                break;
            case 2:
                SearchMovieByTitle(count, Movie);
                break;
            case 3:
                SearchMovieByDirector(count, Movie);
                break;
            case 4:
                SearchMovieByYear(count, Movie);
                break;
            case 5:
                if (isAdmin) {
                    AddAMovie(&count, Movie);
                } else if(isUser) {
                    printf("\n***THANK YOU FOR VISITING OUR DATABASE***\n\n");
                    printf("Exiting.....\n\n");
                    exit(0);
                }
                break;
            case 6:
                if (isAdmin) {
                    UpdateMovie(count, Movie);
                } else {
                  printf("Invalid choice. Please try again.\n");
                }
                break;
            case 7:
                if (isAdmin) {
                    DeleteMovie(&count, Movie);
                } else {
                   printf("Invalid choice. Please try again.\n");
                }
                break;
            case 8:
                if (isAdmin) {
                printf("\n***THANK YOU FOR VISITING OUR DATABASE***\n\n");
                printf("Exiting.....\n\n");
                exit(0);
                } else{
                   printf("Invalid choice. Please try again.\n");
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
