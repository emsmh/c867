/*Class:c867
* Name: Emily Joseph
* Date: 10/6/24
*/
#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <array>
using namespace std;

int main()
{
    /* part f.1 */

    cout << "Course Title: Scripting and Programming- Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 012319604" << endl;
    cout << "Student Name: Emily Joseph" << endl;
    cout << "   " << endl;

    /* tables */

    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        /* part a */
        "A5,Emily,Joseph,ejosep13@wgu.edu,26,10,15,30,SOFTWARE"
    };

    /* part f.1 + f.2 + f.3 */

    Roster* classRoster = new Roster(5);

    for (int i = 0; i < 5; i++) {
        classRoster->parse(studentData[i]);
    };

    /* part f.4 */
    /* functions */

    classRoster->printAll();
    cout << endl;

    classRoster->printInvalidEmails();

    for (int i = 0; i < 5; i++) {

        classRoster->printAverageDaysInCourse(classRoster->GetStudentID(i));
    }
    cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;

    classRoster->remove("A3");
    cout << endl;
    
    classRoster->printAll();
    cout << endl;
   
    classRoster->remove("A3");
    cout << endl;


    /* destructor */

    classRoster->~Roster();
    delete classRoster;

}