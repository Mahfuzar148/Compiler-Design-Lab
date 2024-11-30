#include <bits/stdc++.h>
using namespace std;

map<string, string> rules; // Grammar rules: RHS -> LHS
string stk = "", input;

// Function to perform reductions
void reduce() {
    for (const auto& rule : rules) {
        size_t position = stk.find(rule.first);
        if (position != string::npos) {
            string before = stk; // Store stack before reduction
            stk.erase(position, rule.first.length()); // Remove RHS
            stk += rule.second;                      // Add LHS
            cout << left << setw(15) << "$" + before // Print stack before reduction
                 << setw(20) << input + "$"
                 << "Reduce: " << rule.second << " -> " << rule.first << "\n";
            reduce(); // Continue reducing
            return;
        }
    }
}

int main() {
    freopen("input_10.txt", "r", stdin);
    int n; // Number of production rules
    cin >> n;
    cin.ignore();
    for (int k = 0; k < n; k++) {
        string production;
        getline(cin, production);
        rules[production.substr(3)] = production[0]; // Map RHS to LHS
    }

    cin >> input;

    // Print header
    cout << left << setw(15) << "Stack"
         << setw(20) << "Input"
         << "Action\n";

    // Parsing loop
    while (!input.empty()) {
        // Shift operation
        string before = stk; // Store stack before shift
        stk += input[0];

        cout << left << setw(15) << "$" + before // Print stack before shift
             << setw(20) << input + "$"
             << "Shift: " << stk.back() << "\n";

        // Attempt reductions
        input.erase(0, 1);
        reduce();

    }

    // Final result
    if (stk == "E") {
        cout << left << setw(15) << "$" + stk
             << setw(20) << input + "$"
             << "Accepted\n";
    } else {
        cout << "Rejected\n";
    }

    return 0;
}
