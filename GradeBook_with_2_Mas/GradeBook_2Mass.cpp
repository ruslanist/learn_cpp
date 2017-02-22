/* Determination GradeBook_Mass class methods using two-dimensional array 
 * of storage assessments
 */
/* 
 * File:   GradeBook_2Mass.cpp
 * Author: ruslan
 *
 * Created on 22 февраля 2017 г., 2:45
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision; // Sets the precision output numbers
using std::setw; // Sets the width of the field


#include "GradeBook_2Mass.h"

// Constructor
GradeBook_Mass ::GradeBook_Mass (string name, const int gradesArrey[] [tests])

{
    setCourseName(name); // initialization courseName
    
    // Copy of assessment gradeArrey to grades
    for( int student = 0; student  < students; student++ )
        
        for( int test = 0; test < tests; test++ )
        {
            grades[student] [test] = gradesArray[student] [test];
        
        } // End of for       
} // End of  constructor with arguments dvmya

/***************************************************************************/

// The method for setting the course title
void GradeBook_Mass::setCourseName(string name)
    {
    courseName = name; // Save name of Course
    }
string GradeBook_Mass::getCourseName()
    {
    return courseName;
    }

/****************************************************************************/

// Greeting message and cout name of Course
void GradeBook_Mass::displayMessage()
    {
    cout << "Welcome to the our programm GradeBook_Mass for\n" 
            << getCourseName() << "!" << endl;
    }

/****************************************************************************/

// Perform various operations on the data
void GradeBook_Mass::processGrades()
    {
        // Print Masiv ratings
        outputGrades();
        
        // Coll method  getMimimum and getMaximum
        cout << "\nLowest grade in thegrade book is " << getMinimum()
                << "\nHighest grade in the grade book is " getMaximum() << endl;
        
    // Print diagram Diagram distribution of scores on all ekzaminam
        outputBarChart();
    }

/****************************************************************************/

// To find Min
int GradeBook_Mass::getMinimum()
    {
        int lowGrade = 100; 
        
        // Loop through the rows of the array grades
        for( int student = 0; student  < students; student++ )
            {
            // The columns of the current row cycle
            for( int test = 0; test < tests; test++ )
                {
                if(grades[student] [test] < lowGrade)
                    {
                    lowGrade = grades[student] [test]; // New Low
                    }
                } // The outer end for    
            } // The End of for
        return lowGrade();
    } // End of getMinimum

/**************************************************************************/

// To find Max
int GradeBook_Mass::getMaximum()
{
  int highGrade = 0;
    
     // Loop through the rows of the array grades
    for( int student = 0; student  < students; student++ )
    
        {
        // The columns of the current row cycle
         for( int test = 0; test < tests; test++ )
            {
             if(grades[student] [test] > highGrade)
                {
                 highGrade = grades[student] [test];
                } // The end of if
            } // The outer end for    
        } // The end of for
  
  return = highGrade;
  
} // The end of getMaximum


/****************************************************************************/

// Determine the average for a particular set of estimates
double GradeBook_Mass::getAverage(const int setOfGrades[], const int grades)
{
    int total = 0; // Initialize sum

    // Summation Array ratings
    for( int grade = 0; grade < grades; grade++ )
        {
        total += setOfGrades[grade];
        }

// Return the average for the evaluation
    return static_cast< double >( total ) / grades;
    
    
} // The end of getAverage

/****************************************************************************/

// Conclusion bar chart - the distribution of ratings
void GradeBook_Mass::outputBarChart()

{
    cout << "\nOverall grade distribution:" << endl;
    
    // Store the frequency range of 10 ratings
    const int frequencySize = 11;
    int frequency [frequencySize] = { 0 };
    
     // For each assessment, increase the frequency of
     for( int student = 0; student  < students; student++ )
        {
         for( int test = 0; test < tests; test++ )
            {
             ++frequency[grades[ student ] [ test ] / 10 ];
            }  
        }
    
    // For each frequency diagram display column
    for ( int count = 0; count < frequencySize; count++  )
        {
         // Print column labels on (0-9 ....., ..... 90-99, 100)
        if( count == 0 )
            {
            cout << " 0-9: " << endl;
            }
            else if( count == 10 )
                {
                cout << " 100: " << endl; 
                cout << count * 10 << "-" << (count * 10) + 9 << endl;  
                }
        
        // Napechat column of asterisks (*)
        for( int stars = 0; stars  < frequency[ count ]; stars++)
            {
            cout << '*' << endl;
            cout << endl;
            }            
        } // The end of for



} // The end of  outputBarChart()

/***************************************************************************/

// Display the contents of the array count
void GradeBook_Mass::outputGrades()
{
    cout << "\nThe grades are:\n\n";
    cout << "                " << endl; // Align the column headings
            
    // Create column headings for each of the control
    for(int test = 0; test < tests; test++)
        {
        cout << "Test" << test + 1 << " ";
        }        
    
    cout << "Average" << endl;
    
    for( int student = 0; student  < students; student++ )
        {
        cout << " Student " << setw( 2 ) << student + 1;
        
        for( int test = 0; test < tests; test++ )
            {
            cout << setw( 8 ) << grades[student] [test];
            }
        
        // Вызвать getAvarage() для получения средней оценки
        // Передать в аргументах строку и число контрольных
        double average = getAverage(grades[student], tests);
        cout << setw(9) << setprecision(2) << fixed << average << endl; 
         } // The end of for

} The end of outputGrades