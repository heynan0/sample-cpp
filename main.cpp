#include <iostream>

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

int main()
{
    printMessage();

    doTheCount();
    doPrettyMuchNothing("Hey there");

    int thisIsAnUnusedVariable;
    int thisIsAnotherUnusedVariableThatIsSet = 123;

    //return 0;
}
