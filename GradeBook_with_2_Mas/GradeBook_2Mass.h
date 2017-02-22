/*
 * Class GradeBook using two-dimensional ranges cover
 * 
 * Defining Class GradeBook using Basker dimensional array of assessments.
 * Methods defined in GradeBook.cpp.
 */

/* 
 * File:   GradeBook_2Mass.h
 * Author: ruslan
 *
 * Created on 22 февраля 2017 г., 2:21
 */

#ifndef GRADEBOOK_2MASS_H
#define GRADEBOOK_2MASS_H



#endif /* GRADEBOOK_2MASS_H */


#include <string>
using std:string;

// Сlass Definition
class GradeBook_Mass 

{
public:
    
// Constants.
    const static int students = 10;
    const static int tests = 3;
    
// Designer i* To change this license header, choose License Headers in Project Properties.
 // To change this template file, choose Tools | Templates
  //and open the template in the editor.ntsializiruet course title and array of ratings
GradeBook_Mass(string, const int[] [tests ]);
 
      void setCourseName(string);  // The method for setting the course title
      string getCourseName(); // The method for extracting the name of the course
      void displayMessage(); // Method of Outputting greeting customer
      void processGrades(); // Various Actions on estimates
      int getMinimum(); //Find the minimum assessment for GradeBook 
      int getMaximum(); // Find the maximum assessment for gradeBook
      double getAverage (const int[], const int); // Find the mean
      void outputBarChart(); // It displays a chart of the distribution of ratings
      void outputGrades(); // It displays the contents of the assessment
      
private:
    
    string courseName; // Chrono course title
    int grades[students] [tests]; // Chrono data masivi
    
};