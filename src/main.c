/********************************************************************************
  * @copyright Copyright HTL-HOLLABRUNN  2009-2024 All rights reserved. AUSTRIA
  * @file    main.c
  * @author  Christopher Muellner
  * @version V1.0
  * @date    18.09.2024
  * @brief   Program for writing/reading Students to/from a specific file
  * @note
  *   -
  *
  * History:  18.09.2024 MUEL V1.1.0 added dynamic array size
  *           20.09.2024 MUEL V1.1.1 added documentation
  *
  */


#include <stdio.h>
#include <stdlib.h>


/* --------- Basic Type to represent a student ----- */

typedef struct Student
{
    unsigned int id;      /* Student Number */
    char firstname[25];   /* Student first name */
    char lastname[25];    /* Student last name */
} Student;


/* --------------------------- Function Prototypes ---------------------*/

Student* addStudents(Student* students, size_t* size);  // Adds students to the array
void printStudents(const Student* students, size_t size);  // Prints the arrayF of students
Student* readStudents(size_t* size);  // Reads students from a file
void writeStudents(const Student* students, size_t size);  // Writes students to a file

void printMenu();  // Displays the menu


/**
 * @brief Main function
 * @retval 0
 *         1
 *
 */
int main(void)
{
    Student* students = NULL;  // Dynamic array for students (starts empty)
    size_t size = 0;  // Number of students (initially 0)
    int option = 0;  // Variable for menu option

    do {
        printMenu();

        printf(">> Option: ");

        //check if input is a number
        if (scanf("%d", &option) != 1)
        {
            printf("\r\nUngueltige Eingabe. Bitte geben Sie eine Zahl ein.\n");
            while (getchar() != '\n'); //clear puffer (reject chars until \n)
        }

        else
        {
            switch (option)
            {
                case 0:  // Exit program
                    free(students);
                return EXIT_SUCCESS;

                case 1:  // Add students
                    students = addStudents(students, &size);
                break;

                case 2:  // Print student array
                    printStudents(students, size);
                break;

                case 3:  // Read students from a file
                    students = readStudents(&size);
                break;

                case 4:  // Write students to a file
                    writeStudents(students, size);
                break;

                default:  // Invalid option
                    printf("\n\rUnerwartete Option.\n");
                break;
            }
        }   // Infinite loop until user exits
    } while(true);
}


/**
 * @brief Function to print the main menu
 * @retval none
 */
void printMenu()
{
    printf
    (
        "\n0. Beenden\n"
        "1. Eingabe von Schueler\n"
        "2. Ausgabe aller Schueler\n"
        "3. Lesen der Schueler von einem File\n"
        "4. Schreiben der Schueler auf ein File\n"
    );
}


/**
 * @brief Adds students to the array
 * @param[in,out] students Pointer to the array of students
 * @param[in,out] size Pointer to the size of the array
 * @retval Pointer to the updated array of students
 *         NULL
 */
Student* addStudents(Student* students, size_t* size)
{
    int amount = 0;  // Number of students to add

    while (true)
    {
        printf("\n\r>> Wie viele Schueler moechten Sie hinzufuegen? ");

        // Check if the input is a valid number
        if (scanf("%d", &amount) != 1)
        {
            printf("\r\nUngueltige Eingabe. Bitte geben Sie eine Zahl ein.\n");
            while (getchar() != '\n'); //clear puffer
        }

        else
        {
            break;  // Valid input, exit loop
        }
    }

    // Resize the array to accommodate the new students
    students = (Student*)realloc(students, (*size + amount) * sizeof(struct Student));

    // Check if memory allocation was successful
    if (students == NULL)
    {
        printf("\n\rSpeicherzuweisung fehlgeschlagen!\n");
        return NULL;
    }

    // Enter new student data
    for (size_t i = *size; i < *size + amount; i++)
    {
        printf("\n\r>> Nr (Schueler %llu):", i + 1);
        scanf(" %u", &students[i].id);

        printf("\n\r>> Vorname (Schueler %llu): ", i + 1);
        scanf(" %s", students[i].firstname);

        printf("\n\r>> Nachname (Schueler %llu): ", i + 1);
        scanf(" %s", students[i].lastname);

        printf("\n\r");
    }

    // Update the size of the array to include the new students
    *size += amount;
    return students;  // Return the updated array
}


/**
 * @brief Prints the array of students
 * @param[in] students Pointer to the array of students
 * @param[in] size Size of the array
 * @retval none
 */
void printStudents(const Student* students, size_t size)
{
    if (students == NULL)
    {
        printf("\n\rKeine Schueler vorhanden, bitte zuerst einlesen/laden.\n");
        return;  // Exit if no students are available
    }

    // Print the data for each student
    for (int i = 0; i < size; i++)
    {
        printf("\n\rNr: %u, Vorname: %s, Nachname: %s", students[i].id, students[i].firstname, students[i].lastname);
    }

    printf("\n");
}


/**
 * @brief Reads students from a file
 * @param[out] size Pointer to the size of the array
 * @retval Pointer to the array of students
 *         NULL
 */
Student* readStudents(size_t* size)
{
    char filename[100];
    printf("\n\r>> Dateiname (max. Laenge 100): ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");  // Open the file in read mode

    if (file == NULL)
    {
        printf("\n\rDatei konnte nicht geoeffnet werden!\n");
        return NULL;
    }

    Student* students = NULL;  // Memory for students (initially NULL)
    *size = 0;  // Number of students (initially 0)

    // Read students from the file until the end of the file is reached
    while (true)
    {
        Student temp;  // Temporary student object for reading

        // Read student information from the file
        if (fscanf(file, "%u %s %s", &temp.id, &temp.firstname, &temp.lastname) == EOF)
        {
            break;  // Exit loop if end of file is reached
        }

        // Resize the array to include the new student
        students = (Student*)realloc(students, (*size + 1) * sizeof(Student));

        // Check if memory allocation was successful
        if (students == NULL)
        {
            printf("Speicherzuweisungsfehler!\n");
            fclose(file);
            return NULL;  // Return NULL on failure
        }

        // Add the newly read student to the array
        students[*size] = temp;
        (*size)++;  // Increment the size of the student array
    }

    // Check if any students were read from the file
    if (*size == 0)
    {
        printf("\n\rKeine Schueler in dieser Datei gefunden.\n");
        return NULL;  // Return NULL if no students were read
    }

    fclose(file);  // Close file after reading
    return students;  // Return the array of students
}


/**
 * @brief Writes students to a file
 * @param[in] students Pointer to the array of students
 * @param[in] size Size of the array
 * @retval none
 */
void writeStudents(const Student* students, size_t size)
{
    // Check if the student array is empty
    if (students == NULL)
    {
        printf("\n\rKeine Schueler vorhanden, bitte zuerst einlesen/laden.\n");
        return;  // Exit if there are no students to write
    }

    char filename[100];
    printf("\n\r>> Dateiname (max. Laenge 100): ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "a");  // Open the file in append mode

    // Check if the file opened successfully
    if (file == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden!\n");
        return;  // Exit if the file cannot be opened
    }

    // Write each student's data to the file
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%u %s %s\n", students[i].id, students[i].firstname, students[i].lastname);
    }

    fclose(file);
    printf("\n\rSchueler erfolgreich gespeichert!\n");
}
