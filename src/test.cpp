#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string filename = "example.txt";

    // Write to a text file
    std::ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        outputFile << "Hello, World!" << std::endl;
        outputFile << "This is a sample text file." << std::endl;
        outputFile.close();
        std::cout << "File write complete." << std::endl;
    }
    else
    {
        std::cout << "Unable to open the file for writing." << std::endl;
        return 1;
    }

    // Read from a text file
    std::ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        std::string line;
        int size;
        int arr[size];
        std::cout << "File content:" << std::endl;
        while (std::getline(inputFile, line))
        {
            size = line.length();
            for (int i = 0; i < size; i++)
            {
                arr[i] = line[i];
            }
            std::cout << line[1] << std::endl;
        }
        inputFile.close();
    }
    else
    {
        std::cout << "Unable to open the file for reading." << std::endl;
        return 1;
    }

    return 0;
}