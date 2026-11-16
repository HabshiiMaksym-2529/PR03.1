#include "Pair.h"
#include "RightAngled.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

Pair CopyPair(const Pair& value)
{
    return value;
}

namespace
{
    std::string ReadLine(const char* prompt)
    {
        std::cout << prompt;

        std::string line;
        if (!std::getline(std::cin, line))
        {
            throw std::runtime_error("Input ended.");
        }

        return line;
    }

    std::string ReadNumberLine(const char* prompt)
    {
        const std::string line = ReadLine(prompt);
        std::istringstream input(line);

        double value{};
        char extra{};

        if (!(input >> value) || (input >> extra))
        {
            throw std::invalid_argument("Enter one valid number.");
        }

        return line;
    }

    void EnterPair(Pair& value, const char* firstPrompt,
        const char* secondPrompt)
    {
        const std::string first = ReadNumberLine(firstPrompt);
        const std::string second = ReadNumberLine(secondPrompt);

        std::istringstream input(first + ' ' + second);
        if (!(input >> value))
        {
            throw std::invalid_argument("Could not read the two numbers.");
        }

        std::cout << "Saved: " << value << '\n';
    }

    void DemonstrateClasses(const Pair& pair, const RightAngled& triangle)
    {
        Pair edited(pair);
        edited.SetFirst(3.0);
        edited.SetSecond(4.0);

        Pair pairs[] = { Pair(), Pair(2.0, 5.0), edited };
        RightAngled triangles[] = {
            RightAngled(), RightAngled(3.0, 4.0), triangle
        };

        pairs[0] = pairs[1];
        triangles[0] = triangles[1];

        std::cout << "\nArray of pairs:\n";
        for (const Pair& item : pairs)
        {
            std::cout << static_cast<std::string>(item) << '\n';
        }

        std::cout << "\nArray of triangles:\n";
        for (const RightAngled& item : triangles)
        {
            std::cout << static_cast<std::string>(item)
                << ", hypotenuse: " << item.Hypotenuse()
                << ", area: " << item.Area() << '\n';
        }
    }
}

int main()
{
    try
    {
        Pair pair;
        RightAngled triangle;

        while (true)
        {
            std::cout << "\n1. Enter a pair of numbers\n"
                << "2. Enter triangle legs\n"
                << "3. Show current values and calculations\n"
                << "4. Demonstrate substitution\n"
                << "5. Demonstrate constructors and arrays\n"
                << "0. Exit\n";

            const std::string choice = ReadLine("Choose an option: ");

            if (choice == "0")
            {
                return EXIT_SUCCESS;
            }
            else if (choice == "1")
            {
                EnterPair(pair, "First number: ", "Second number: ");
            }
            else if (choice == "2")
            {
                EnterPair(triangle, "First leg: ", "Second leg: ");
            }
            else if (choice == "3")
            {
                std::cout << "\nPair: " << pair
                    << "\nProduct: " << pair.Product()
                    << "\nTriangle legs: " << triangle
                    << "\nHypotenuse: " << triangle.Hypotenuse()
                    << "\nArea: " << triangle.Area() << '\n';
            }
            else if (choice == "4")
            {
                const Pair fromPair = CopyPair(pair);
                const Pair fromTriangle = CopyPair(triangle);

                std::cout << "\nCopyPair(pair): " << fromPair
                    << "\nCopyPair(triangle): " << fromTriangle
                    << "\nProduct of the copied legs: "
                    << fromTriangle.Product() << '\n';
            }
            else if (choice == "5")
            {
                DemonstrateClasses(pair, triangle);
            }
            else
            {
                throw std::invalid_argument("Choose a number from 0 to 5.");
            }
        }
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error: " << error.what() << '\n';
        return EXIT_FAILURE;
    }
}