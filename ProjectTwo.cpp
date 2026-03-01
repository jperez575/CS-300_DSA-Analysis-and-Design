#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
 * Course structure
 * Store course number, title and prerequisites
 */
struct Course {
	string courseNumber;
	string courseTitle;
	vector<string> prerequisites;
};

/*
 * Convert string to uppercase
 */
string toUpperCase(string str) {
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

/*
 * Load course data into map
 * Automatically keeps keys sorted alphanumerically
 */
void loadCourses(map<string, Course>& courseMap) {
	//Manually point to csv file
	string fileName = "CS 300 ABCU_Advising_Program_Input.csv";

	ifstream file(fileName);



	if (!file.is_open()) {
		cout << "Error: Could not open file." << endl;
		return;
	}

	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string token;

		Course course;

		// Get course number
		getline(ss, token, ',');
		course.courseNumber = toUpperCase(token);

		// Get course title
		getline(ss, token, ',');
		course.courseTitle = token;

		// Get prerequisites (if any)
		while (getline(ss, token, ',')) {
			course.prerequisites.push_back(toUpperCase(token));
		}

		// Insert into map
		courseMap[course.courseNumber] = course;
	}

	file.close();
	cout << "Courses loaded successfully." << endl;
}

	/*
	 * Print all courses in alphanumeric order
	 */
	void printCourseList(map<string, Course>&courseMap) {
		cout << "\nHere is a sample schedule:\n" << endl;

		for (auto const& pair : courseMap) {
			cout << pair.second.courseNumber << ", "
				<< pair.second.courseTitle << endl;
		}

		cout << endl;
	}

	/*
	 * Print detailed course information
	 */
	void printCourse(map<string, Course>& courseMap) {
		string courseNumber;

		cout << "What course do you want to know about? ";
		cin >> courseNumber;

		courseNumber = toUpperCase(courseNumber);

		auto it = courseMap.find(courseNumber);

		if (it == courseMap.end()) {
			cout << "Course not found." << endl;
			return;
		}

		Course course = it->second;

		cout << "\n" << course.courseNumber << ", "
			<< course.courseTitle << endl;

		if (course.prerequisites.empty()) {
			cout << "Prerequisites: None" << endl;
		} else {
			cout << "Prerequisites: ";
			for (size_t i = 0; i < course.prerequisites.size(); ++i) {
				cout << course.prerequisites[i];
				if (i < course.prerequisites.size() - 1) {
					cout << ", ";
				}
			}
			cout << endl;
		}

		cout << endl;
	}

	/*
	 * Display menu
	 */
	void displayMenu() {
		cout << "1. Load Data Structure." << endl;
		cout << "2. Print Course List." << endl;
		cout << "3. Print Course." << endl;
		cout << "9. Exit" << endl;
		cout << endl;
	}

	/*
	 * Main
	 */
	int main() {

		map<string, Course> courseMap;
		string fileName;
		int choice = 0;

		cout << "Welcome to the course planner." << endl;

		while (choice != 9) {
			displayMenu();
			cout << "What you would like to do? ";
			cin >> choice;

			switch (choice) {

			case 1:
				loadCourses(courseMap);
				break;

			case 2:
				if (courseMap.empty()) {
					cout << "Please load data first." << endl;
				} else {
					printCourseList(courseMap);
				}
				break;

			case 3:
				if (courseMap.empty()) {
					cout << "Please load data first." << endl;
				}
				else {
					printCourse(courseMap);
				}
				break;

			case 9:
				cout << "Thank you for using the course planner!" << endl;
				break;

			default:
				cout << choice << " is not a valid option." << endl;
			}
		}

		return 0;
	}