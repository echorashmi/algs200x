/*
Practice file for Working with Vectors in C++

Vectors are variable length. They automatically manage storage. 
We use vectors when we don't know how big the data is beforehand since there is no need to set the maximum size of the container. It's possible to resize vectors. 
*/

#include <iostream>
#include <string>
#include <vector>

int main()
{
    //Vector of Integers:
    std::cout << "Vector of Integers:\n";
    std::vector <int> vectorOfIntegers(5);
    for (int x: vectorOfIntegers)
    {
        std::cout << x << std::endl; //Will print out 5 integers, all zero. 
    }

    std::cout << "\n\n-------------------------\n\n";

    //Vector of String:
    std::cout << "Vector of Strings:\n";
    std::string arr[] = { "first", "second", "third", "fourth" };

    std::vector <std::string> vectorOfStrings(arr, arr+ sizeof(arr) / sizeof(std::string)); //type can be <int> or <double> or <string>. Number of elements is optional. 
    for (std::string x: vectorOfStrings)
    {
        std::cout << x << std::endl; //Will print out 5 integers, all zero. 
    }

    //Adding to a Vector:
    vectorOfStrings.push_back("fifth");
    vectorOfStrings.push_back("sixth");

    //Copying to Another Vector
    std::vector <std::string> vectorOfStrings2(vectorOfStrings);

    std::cout << "\n\n-------------------------\n\n";
    std::cout << "Copying to another Vector:\n";
    for (std::string x: vectorOfStrings2)
    {
        std::cout << x << std::endl; //Will print out 5 integers, all zero. 
    }

    std::cout << "\n\n-------------------------\n\n";
    std::cout << "Print the size of a Vector:\n";
    std::cout << vectorOfStrings2.size() << std::endl;

    std::cout << "\n\n-------------------------\n\n";
    std::cout << "Print the Max size of a Vector:\n";
    std::cout << vectorOfStrings2.max_size() << std::endl; //Prints out: 768614336404564650
    std::cout << vectorOfStrings.max_size() << std::endl; //Prints out: 768614336404564650
    std::cout << vectorOfIntegers.max_size() << std::endl; //Prints out: 4611686018427387903

    std::cout << "\n\n-------------------------\n\n";
    std::cout << "Access an element of a vector:\n";
    for (int i = 0; i < vectorOfStrings.size(); i++)
    {
        std::cout << vectorOfStrings.operator[](i) << " ";
    }

    std::cout << "\n\n-------------------------\n\n";
    std::cout << "Replacing an element of a vector:\n";

    vectorOfIntegers.operator[](1) = 10;
    for (int i = 0; i < vectorOfIntegers.size(); i++)
    {
        std::cout << vectorOfIntegers.operator[](i) << " ";
    }

    std::cout << "\n\n-------------------------\n\n";
    std::cout << "Inserting multiple elements into a Vector: \n";
    
    int arrayOfIntegers[] = {10, 20, 30, 40, 50};
    vectorOfIntegers.insert(vectorOfIntegers.end(), 
                            arrayOfIntegers, 
                            arrayOfIntegers + 
                                (sizeof(arrayOfIntegers) 
                                    / sizeof(arrayOfIntegers[0])));
    for (int i = 0; i < vectorOfIntegers.size(); i++)
    {
        std::cout << vectorOfIntegers.operator[](i) << " ";
    }


}