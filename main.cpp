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

# define BUFFERSIZE 4
void readChars()
{
    char buffer[BUFFERSIZE];
    std::cout << "Type something: ";
    // type more than BUFFERSIZE chars and program will crash:
    gets(buffer);
    std::cout << "You typed: " << buffer << std::endl;

    char buffer2[BUFFERSIZE];
    std::cout << "Type something (Cin): ";
    // use of cin w/o specifying input length
    std::cin >> buffer2;
    buffer2[BUFFERSIZE - 1] = '\0';
    std::cout << "You typed: " << buffer2 << std::endl;
}

void localVarHidesParamVar(int paramVar)
{
    // error: declaration of 'int paramVar' shadows a parameter
    // (already caught by compiler)
    // int paramVar = 123;
    std::cout << "The local var hides the param var: " << paramVar << std::endl;
}

void unusedLocalVar()
{
    int x = 0;
    int y = 1;
    std::cout << "Not gonna use any defined local var :)\n";
}

void mistakenUseOfEqualForDoubleEquals()
{
    int a;
    a == 2;
    std::cout << "a is " << a << std::endl;
}

void missingPrintfArgs()
{
    printf("decimal: %d / string: %s\n", 123);
}

void loopingUsingTypesOfDifferentSize()
{
    std::cout << "sizeof(long): " << sizeof(long) << std::endl;
    std::cout << "sizeof(short): " << sizeof(short) << std::endl;
    // make this larger than size of short so i will overflow... e.g. 32768
    // you'll get an infinite loop
    long total = 32767;
    for (short i = 0; i < total; i++)
    {
        if (i + 1 == total) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
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
    readChars();

    localVarHidesParamVar(987);
    mistakenUseOfEqualForDoubleEquals();
    missingPrintfArgs();

    unusedLocalVar();
    loopingUsingTypesOfDifferentSize();

    //return 0;
}
