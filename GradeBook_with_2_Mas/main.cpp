/*
 * Создать объект GradeBook_Mass
 */

/* 
 * File:   main.cpp
 * Author: ruslan
 *
 * Created on 22 февраля 2017 г., 2:19
 */

#include "GradeBook_2Mass.h"

using namespace std;

int main(int argc, char** argv) {
 int gradesArray[GradeBook_Mass::students] [GradeBook_Mass::tests] =
 { { 87, 96, 70 },
   { 68, 87, 90 },  
   { 94, 100, 90 },
   { 100, 81, 82 },
   { 83, 65, 85 },
   { 78, 87, 65 },
   { 85, 75, 83 },
   { 91, 94, 100 },
   { 76, 72, 84 },
   { 87, 93, 73 } };
 
 GradeBook_Mass myGradeBook_Mass("Curs 2202 for my Lessons Prog", gradesArray); 
 
 myGradeBook_Mass.displayMessage();
 myGradeBook_Mass.processGrades();
    return 0;
}

