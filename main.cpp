#include <iostream>
#include <vector>
#include <limits>
#include <list>
#include <deque>
#include <queue>
#include <string>
#include <cctype>
#include <forward_list>

using namespace std;

void printList(const forward_list<int>& flist) {
    for (int value : flist) {
        cout << value << " ";
    }
    cout << endl;
}





int removeAndCount(vector<int>& nums, int val) {
    int count = 0;
    for (int& num : nums) {
        if (num == val) {
            num = -1; // Replace occurrences of val with -1
        } else {
            count++; // Count elements that are not equal to val
        }
    }
    return count;
}





void cleanNumbers(vector<string>& vec) {
    vector<string>::iterator it = vec.begin();
    while (it != vec.end()) {
        bool containsDigit = false;
        for (char c : *it) {
            if (isdigit(c)) {
                containsDigit = true;
                break;
            }
        }
        if (containsDigit) {
            it = vec.erase(it); // Remove the word containing digits
        } else {
            ++it;
        }
    }
}
int main() {
    cout << "Problem 1: \n" << endl;
    vector<double> vec = {1.1, 2.2, 3.3, 4.4, 5.5};

    for (vector<double>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Problem 2: \n" << endl;

    vector<double> vec2;
    double input;
    cout << "Enter elements (end with a non-numeric input): ";

    while (cin >> input) {
        vec2.push_back(input);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (!vec2.empty()) {
        cout << "First element: " << vec2.front() << endl;
        cout << "Last element: " << vec2.back() << endl;
    } else {
        cout << "No elements entered." << endl;
    }

    cout << "Problem 3: \n" << endl;
    vector<int> vec3;
    int value;
    cout << "Enter 8 values to assign to the vector: ";
    for (int i = 0; i < 8; ++i) {
        cin >> value;
        vec3.push_back(value);
    }

    cout << "Initial vector: ";
    for (int num : vec3) {
        cout << num << " ";
    }
    cout << endl;

    if (!vec3.empty()) {
        if (vec3.size() > 4) {
            vec3.erase(vec3.begin() + 4);
        } else {
            cout << "The vector does not have enough elements to remove the 5th element." << endl;
        }

        cout << "After removing element at position 4: ";
        for (int num : vec3) {
            cout << num << " ";
        }
        cout << endl;

        if (vec3.size() > 2) {
            vec3.erase(vec3.begin() + 1, vec3.begin() + 3);
        } else {
            cout << "The vector does not have enough elements to remove the range from position 1 to 2." << endl;
        }

        cout << "After removing range of elements from position 1 to 2: ";
        for (int num : vec3) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "The vector is empty." << endl;
    }
    cout<<"Problem 4: \n"<<endl;
    int n4;
    cout << "Enter the size of the matrix (n): ";
    cin >> n4;


    vector<vector<double>> matrix(n4, vector<double>(n4, 0.0));


    cout << "Enter " << n4 * n4 << " elements: ";
    vector<vector<double>>::iterator row;
    vector<double>::iterator col;
    for (row = matrix.begin(); row != matrix.end(); ++row) {
        for (col = row->begin(); col != row->end(); ++col) {
            cin >> *col;
        }
    }

    cout << "Matrix output:" << endl;
    for (row = matrix.begin(); row != matrix.end(); ++row) {
        for (col = row->begin(); col != row->end(); ++col) {
            cout << *col << " ";
        }
        cout << endl;
    }
    cout<<"Problem 5: \n"<<endl;
    list<double> list1 = {3.3, 4.5, 6.7};
    list<double> list2 = {1, 2, 3};
    list<double> list3 = {8, 9.5, 10.3};

    list<double> resultList;

    resultList.insert(resultList.end(), list3.begin(), list3.end());

    resultList.insert(resultList.end(), list1.begin(), list1.end());

    resultList.insert(resultList.end(), list2.begin(), list2.end());

    cout << "Merged list: ";
    for (double value : resultList) {
        cout << value << " ";
    }
    cout << endl;

    cout<<"Problem 6: \n"<<endl;
    forward_list<int> flist = {1, 2, 3, 4, 5};

    cout << "Initial list: ";
    printList(flist);

    auto it = flist.begin();
    if (it != flist.end() && next(it) != flist.end()) {
        flist.erase_after(it);
    }
    cout << "After deleting the second element: ";
    printList(flist);

    flist.push_front(10);
    cout << "After push_front(10): ";
    printList(flist);

    flist.emplace_front(20);
    cout << "After emplace_front(20): ";
    printList(flist);

    flist.pop_front();
    cout << "After pop_front(): ";
    printList(flist);

    it = flist.begin();
    if (it != flist.end()) {
        flist.insert_after(it, 30);
    }
    cout << "After insert_after(30): ";
    printList(flist);

    it = flist.begin();
    if (it != flist.end()) {
        flist.emplace_after(it, 40);
    }
    cout << "After emplace_after(40): ";
    printList(flist);

    cout<<"Problem 7: \n"<<endl;
    deque<int> dq;

    dq.push_back(5);

    dq.push_front(7);

    dq.push_back(10);

    dq.push_front(20);

    cout << "Elements in deque: ";
    for (int value : dq) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Size of deque: " << dq.size() << endl;

    // Step 8: Display the third element of the deque
    if (dq.size() >= 3) {
        cout << "Third element of deque: " << dq[2] << endl;
    } else {
        cout << "Deque does not have a third element." << endl;
    }

    if (!dq.empty()) {
        cout << "First element of deque: " << dq.front() << endl;
        cout << "Last element of deque: " << dq.back() << endl;
    } else {
        cout << "Deque is empty." << endl;
    }

    if (!dq.empty()) {
        dq.pop_front();
    }
    if (!dq.empty()) {
        dq.pop_back();
    }

    cout << "Elements in deque after deleting first and last elements: ";
    for (int value : dq) {
        cout << value << " ";
    }
    cout << endl;

    cout<<"Problem 8: \n"<<endl;
    queue<int> students;
    deque<int> sandwiches;



    int studentArr[] = {1, 1, 1, 0, 0, 1};
    int sandwichArr[] = {1, 0, 0, 0, 1, 1};

    for (int student : studentArr) {
        students.push(student);
    }

    for (int sandwich : sandwichArr) {
        sandwiches.push_back(sandwich);
    }

    int unableToEat = 0;

    while (!students.empty() && !sandwiches.empty()) {
        if (students.front() == sandwiches.front()) {

            students.pop();
            sandwiches.pop_front();
            unableToEat = 0;
        } else {
            students.push(students.front());
            students.pop();
            unableToEat++;
        }

        if (unableToEat == students.size()) {
            break;
        }
    }

    cout << students.size() << endl;

    cout<<"Problem 9: \n"<<endl;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int val;
    cout << "Enter the value to remove: ";
    cin >> val;

    int count = removeAndCount(nums, val);

    cout << "Number of elements not equal to " << val << ": " << count << endl;
    cout << "Resulting vector: ";
    for (int num : nums) {
        if (num != -1) {
            cout << num << " ";
        }
    }
    cout << endl;

    cout<<"Problem 10: \n"<<endl;
    vector<string> words;
    string word;

    cout << "Enter words (end input with a non-alphanumeric character): ";
    while (cin >> word) {
        words.push_back(word);
    }

    cleanNumbers(words);

    cout << "Output:" << endl;
    for (const string& w : words) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
