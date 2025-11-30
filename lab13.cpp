/* Answers to questions:

1. Is there a fault in the program? If so, locate it and explain.
  There is a fault in the program, in the for loop in fail_lecture it starts the initial value of i as 1.
  This is a fault because the starting index for a vector is 0, so if you were to input a vector with 10 entries to represent the
  students attendance, the function skips over the first entry in that vector and will only read the other 9 inputs, causing possible
  incorrect answers

2. Define a test case that does not execute the fault. If impossible, explain the reason
  It is impossible to not execute the fault, as with any vector you input, even if it is not the expected attendance record with 10 
  values, it will always skip over the first entry. The skipping over the first entry is the fault, so it is impossible to not activate
  it with a test case that is an attendance record with 10 values.
  
3. Define a test case that executes the fault but does not result in an error state.
  attendance record: {1,1,1,1,1,1,1,1,1,1}
  expected output: 0 (False)
  actual output: 0 (False)

4. Define a test case that results in an error state but not a failure.
  attendance record: {0,1,0,0,0,1,1,1,1,1}
  expected output: 1 (True)
  actual output: 1 (True)
  
5. Define a test case that results in failure.
  attendance record: {0,1,0,0,1,1,1,1,1,1}
  expected output: 1 (True)
  actual output: 0 (False)
*/

#include <iostream>
#include <vector>

using namespace std;

bool fail_lecture(const vector<int>& attendance_records) {
  int absent_count = 0;
  for (int i = 1; i < attendance_records.size(); ++i) {
    absent_count += attendance_records[i] == 0;
  }
  return absent_count >= 3;
}

// This is the corrected version of fail_lecture
bool corrected_fail_lecture(const vector<int>& attendance_records) {
  int absent_count = 0;
  for (int i = 0; i < attendance_records.size(); ++i) {
    absent_count += attendance_records[i] == 0;
  }
  return absent_count >= 3;
}

int main() {
  vector<int> question3 = {1,1,1,1,1,1,1,1,1,1};
  cout << "Test case that executes fault but does not enter error state: " << "{1,1,1,1,1,1,1,1,1,1}" << endl;
  cout << "Expected Result: " << corrected_fail_lecture(question3) << endl;
  cout << "Actual Result: " << fail_lecture(question3) << "\n" << endl;
  
  vector<int> question4 = {0,1,0,0,0,1,1,1,1,1};
  cout << "Test case that results in error state but not a failure: {0,1,0,0,0,1,1,1,1,1}" << endl;
  cout << "Expected Result: " << corrected_fail_lecture(question4) << endl;
  cout << "Actual Result: " << fail_lecture(question4) << "\n" << endl;
  
  vector<int> question5 = {0,1,0,0,1,1,1,1,1,1};
  cout << "Test case that results in failure: {0,1,0,0,1,1,1,1,1,1}" << endl;
  cout << "Expected Result: " << corrected_fail_lecture(question5) << endl;
  cout << "Actual Result: " << fail_lecture(question5) << "\n" << endl;
}
