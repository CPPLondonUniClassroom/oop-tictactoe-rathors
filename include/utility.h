#pragma once
#include "BoardPosition.h"

#include <iostream>
#include <limits>

// This function will read a number from the console (the command prompt) for you.
// You can optionally tell it the minimum and maximum values you want to consider acceptable.
// If the user enters garbage or they violate the Min/Max you set, it will not return and will
// make them re-enter something valid. The Min/Max is *inclusive* - so (1,3) would permit 1,2 or 3
//
// E.G.: int playerChoice = ReadNumber(1, 10);
inline int ReadNumber(int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max()) {
    std::cout << "\n > ";
    int pos = 0;
    std::cin >> pos;
    if (std::cin.fail() || pos < min || pos > max) {
        std::cout << "ERROR: Enter a valid number\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ReadNumber(min, max);
    }
    return pos;
}

// This function lets you print data to the console. You can give it as many
// arguments as you like,
//
// E.G.: PrintMessage("Hello to ", 5, "People");
template <typename... Args>
inline void PrintMessage(Args&&... args) {
    (std::cout << ... << args);
}

// This function converts a BoardPosition enum value into a char.
// Useful if you want to index an array after getting a BoardPosition.
//
// E.G.: char cPos = BoardPositionToChar(BoardPosition::CENTER);
inline char BoardPositionToChar(const BoardPosition& pos) {
    return static_cast<char>(pos);
}

// This function is similar to the above, but returns an int instead of a char.
// Useful if you want to print the value to the console since using char won't get
// rendered as a normal number and instead will just look like unreadable garbage.
//
// E.G.: char cPos = BoardPositionToInt(BoardPosition::TOP_RIGHT);
inline int BoardPositionToInt(const BoardPosition& pos) {
    return BoardPositionToChar(pos);
}

// This function will convert a number to a BoardPosition. You need to take care
// to ensure that whatever you pass is in the range 0-9 or you might end up with
// unpleasant bugs.
//
// E.G.: auto pos = NumberToBoardPosition(5);
template <typename T>
inline BoardPosition NumberToBoardPosition(const T& num) {
    return static_cast<BoardPosition>(num);
}
