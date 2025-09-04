//Forgot to add this to my last challenge, last edited 9/1/25, assigment challenge 1 and 2, 
#include <iostream> 
#include <limits> // for input validation

using namespace std;

// Function to input grades using reference parameters
void inputGrades(double& g1, double& g2, double& g3) {
    cout << "Enter grade 1: ";
    while (!(cin >> g1) || g1 < 0 || g1 > 100) { // validate input
        cout << "Invalid input. Enter a number between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter grade 2: ";
    while (!(cin >> g2) || g2 < 0 || g2 > 100) {
        cout << "Invalid input. Enter a number between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter grade 3: ";
    while (!(cin >> g3) || g3 < 0 || g3 > 100) {
        cout << "Invalid input. Enter a number between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Grades successfully recorded!" << endl;
}

// Function to calculate average
double calculateAverage(const double g1, const double g2, const double g3) {
    return (g1 + g2 + g3) / 3.0;
}

// Function to get letter grade based on average
char getLetterGrade(const double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

int main() {
    double grade1 = 0.0, grade2 = 0.0, grade3 = 0.0;
    int choice;

    do {
        // Menu
        cout << "\n--- Student Grade Management ---\n";
        cout << "1. Input Grades\n";
        cout << "2. Calculate and Display Average\n";
        cout << "3. Assign and Display Letter Grade\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 4) { // validate menu input
            cout << "Invalid choice! Enter a number between 1 and 4 please: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //make sure to have this so it doesn't fail the next cin immediately
        }
        // have mutiple cases for each different input from the user
        switch (choice) {
        // Input the grades
        case 1:
            inputGrades(grade1, grade2, grade3);
            break;
        // The average of the grade
        case 2: {
            double avg = calculateAverage(grade1, grade2, grade3);
            cout << "Average grade: " << avg << endl;
            break;
        }
        // Displaying the letter grade
        case 3: {
            double avg = calculateAverage(grade1, grade2, grade3);
            char letter = getLetterGrade(avg);
            cout << "Average grade: " << avg << " -> Letter grade: " << letter << endl;
            break;
        }
              //Exciting the program
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}
