#include <iostream>
#include <string>
#include <map>

#include "FakeClass.h"

void printMessage()
{
    std::cout << "This is a simple C++ program to test code analysis" << std::endl;
}

void doTheCount()
{
    std::cout << "count: ";
    int count = 1;
    for (; count <= 10; count++)
    {
        std::cout << count << ' ';
    }
    std::cout << std::endl;

    if (count == 10)
    {
        /* an empty if block */
    }
    else
    {
        std::string message = "Hello world";
        std::cout << message << '\n';
    }
}

int doPrettyMuchNothing(std::string someString)
{
    if (true)
    {
        // ...
    }
    else if (1 != 2)
    {
        // ...
    }
    else
    {

    }

    return 123;
}

void useFakeClass()
{
    FakeClass fakeObject;
    std::cout << "Fake token: " << fakeObject.getFakeToken() << std::endl;
}

void experimentWithArrays()
{
    int numbers[3] = { 1, 2, 3 };
    int index = 1;
    std::cout << "Array element: " << numbers[index++] << std::endl;
}

void workWithMap()
{
    std::map<char, int> letterToIntMap;
    letterToIntMap['a'] = 10;
    letterToIntMap['c'] = 30;
    letterToIntMap['e'] = 60;

    std::map<char, int>::iterator it;
    it = letterToIntMap.find('c');
    if (it != letterToIntMap.end())
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

int main()
{
    // To experiment with analysis finding secret tokens in code
    std::string FAKE_TOKENN = "b15067bc-8721-470b-a0df-9bc2fa9bd885";
    printMessage();

    doTheCount();
    doPrettyMuchNothing("Hey there");

    int thisIsAnUnusedVariable;
    int thisIsAnotherUnusedVariableThatIsSet = 123;

    useFakeClass();
    experimentWithArrays();
    workWithMap();

    //return 0;
}
