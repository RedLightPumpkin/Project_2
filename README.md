# Final project of the 2nd semester of my IT university work

## This project involves creating a structure named STUDENT with the following fields:
```
    * Name (single field for both first and last name)
    * Grades – a 6-element array (grades represented as points from 50 to 100, but can also be 0)
    * Average Grade (in points)
    * Final Grade (very good, good, sufficient, insufficient)
```
The final grade can be calculated based on the following scale:

   * 51 - 60: Sufficient
   * 61 - 70: Sufficient plus
   * 71 - 80: Good
   * 81 - 90: Good plus
   * 91 - 100: Very good

The data in the input file can be formatted as:
```
Test Name
80 91 51 0 74 92
Name Test
70 85 90 50 61 80
```
... and so on.

## Program Requirements

The program should consist of the following functions:
```
    * Read data from the dane.txt file, which contains student names and their grades.
    * Calculate the average grade for all students.
    * Determine how many students have an average grade higher than the overall average. Display this value.
    * Display the student(s) with the highest average grade and save their data to a file.
    * Search and display the data of a specific student.
```
Optional Features

The program was extended with additional features, such as:

    Adding new students,
    Searching for a certain student using his average grade or full name,
    
Note: Object-oriented programming could not be used during the creation of the program.
