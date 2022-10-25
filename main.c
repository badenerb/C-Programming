/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<string.h>
#include <stdbool.h>

//Struct for student
#ifndef STUDENT_H_
#define STUDENT_H_

typedef struct Student_struct
{
  char Name[50];
  int MT1;
  int MT2;
  int Finals;
} Student;

Student InitStudent ();
Student SetName (char *name, Student s);
Student SetMT1 (int MT1, Student s);
Student SetMT2 (int MT2, Student s);
Student SetFinal (int Finals, Student s);
#endif

//Function that returns the letter grade of the given point grade
char
LetterGrade (double x)
{
  char grade;
  if (x >= 90.0)
    {
      grade = 'A';
    }
  else if (x >= 80.0)
    {
      grade = 'B';
    }
  else if (x >= 70.0)
    {
      grade = 'C';
    }
  else if (x >= 60.0)
    {
      grade = 'D';
    }
  else
    {
      grade = 'F';
    }
  return grade;
}

//Initializes Student struct
Student
InitStudent ()
{
  Student stu;
  return stu;
}

//Sets name of student 
Student
SetName (char *name, Student s)
{
  strcpy (s.Name, name);
  return s;
}

Student
SetMT1 (int MT1, Student s)
{
  s.MT1 = MT1;
  return s;
}

Student
SetMT2 (int MT2, Student s)
{
  s.MT2 = MT2;
  return s;
}

Student
SetFinal (int Finals, Student s)
{
  s.Finals = Finals;
  return s;
}

//returns the average of the students three grades stored in the student 
double
GetStuAverage (Student s)
{
  return (double) (s.MT1 + s.MT2 + s.Finals) / 3;
}

//prints the header of the output
void
PrintStart ()
{
  printf
    ("===============================================================\n");
  printf ("|\tName\t|\tMT-1\t|\tMT-2\t|\tFinals\t|\tAverage\t|\tGrade\t|\n");
  printf
    ("===============================================================\n");
}

//Prints the footer of the output
void
PrintEnd ()
{
  printf
    ("===============================================================\n");
}

//Prints the students data out and if the student is not the first to be printed, adds a divider line between the student above
void
PrintStu (Student s, int check)
{
  if (check == 1)
    printf
      ("--------------------------------------------------------------------------------------------------\n");
  printf ("|%s\t|\t%d\t|\t%d\t|\t%d\t|\t%.2lf\t|\t%c\t|\n", s.Name, s.MT1,
	  s.MT2, s.Finals, GetStuAverage (s),
	  LetterGrade (GetStuAverage (s)));

}


int
main ()
{
  //Variable declerations
  int check = 0;
  int i;
  char input[100];
  char fname[50];
  char lname[50];

  int MT1;
  int MT2;
  int final;

  PrintStart ();

  //Loops through the entire stdinput the user gives
  while (fgets (input, 100, stdin) && strcmp (input, "-1\n") != 0)
    {
      //Creates an empty student struct
      Student student = InitStudent ();
      char fullName[50] = "";
      sscanf (input, "%s %s %d %d %d", fname, lname, &MT1, &MT2, &final);
      strcat (fullName, fname);
      strcat (fullName, " ");
      strcat (fullName, lname);

      student = SetName (fullName, student);
      student = SetMT1 (MT1, student);
      student = SetMT2 (MT2, student);
      student = SetFinal (final, student);

      PrintStu (student, check);
      check = 1;
    }

  PrintEnd ();
  return 0;
}
