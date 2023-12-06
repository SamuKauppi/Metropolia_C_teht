#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static string getContent(const string& fileName)
{
    string value;
    try
    {
        ifstream input(fileName, ios::ate);  // Open the file at the end with ios::ate

        // Check if a file was opened
        if (input.is_open())
        {
            cout << "File was found! \nContent:\n";

            // Since the pointer is at end, we can tell the filesize with tellg
            size_t fileSize = input.tellg();

            // Resize the string to contain entire file
            value.resize(fileSize);

            // Move pointer back to the start
            input.seekg(0, ios::beg);

            // Read the file for filesize ínto value
            input.read(&value[0], fileSize);

            input.close(); // Close the file after reading
        }
        else
        {
            throw runtime_error("Unable to locate file called: " + fileName);
        }
    }
    catch (const exception& e)
    {
        cout << "Error in reading file: " << e.what() << "\n";
    }

    // return string read from file
    return value;
}

int main()
{
    while (true)
    {
        cout << "Give filename: ";
        string value;
        cin >> value;

        if (value == "stop")
            break;

        string content = getContent(value);
        cout << content << "\n";

        cout << "Type stop to stop\n";
    }
    return 0;
}
