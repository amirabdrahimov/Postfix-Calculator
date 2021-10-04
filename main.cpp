#include <iostream>
#include "Postfix.h"
using T = char;

int main(int argc, char* argv[]) {
    string expression;
    vector<string> v;
    cout << "Enter expression in a postfix format: ";
    while ((cin.peek() != '\n') && (cin.peek() != EOF)) {
        cin >> expression;
        v.push_back(expression);
    }
    try {
        auto* rpn = new Postfix<T>(v);
        BinaryNumber<T> result = rpn->evaluate();

        cout << "Result in binary format: "; result.printBinArray(result.mainArray);
        cout << "Result in decimal format: " << +result.binToDec(result.mainArray);

    }
    catch (const char* exception) {
        cout << "There is a mistake in expression: " << exception << endl;
    }
}