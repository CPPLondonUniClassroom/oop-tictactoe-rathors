# Noughts And Crosses

This project is designed to exercise your ability to both understand and implement OOP.

If you're currently reading this from the "Pro" branch, then you're basically starting from scratch
implementing the specification. None of the "Pre-provided assistance" is available if you're attempting
this at "Pro" difficulty.

## Pre-Provided Assistance

There is a header called `utility.h` in the `include` folder. This contains some bits and pieces
to make your life easier if you're not terribly comfortable interacting with the console functionality
in C++ or with converting enum classes between their innate type and numbers.

Depending on the difficulty level you choose, some of the classes described below may be either
empty files, partially complete or entirely done.

## General Terms

All class data should be `private`. You are free to define your own functions as you see fit. If you
want to generify the implementation further by interfacing away any concrete functions, feel free.

In this implementation, we can consider the board as a flat sequence of 9 elements going from left to right
and "wrapping" down to the left-most element of the next column. For the avoidance of doubt:

* Element 0 represents the top left.
* Element 2 represents the top right.
* Element 4 represents the center.
* Element 6 represents the bottom left.

This should be enough for you to figure out the logic. If not, draw the grid and number them from the above
and it should quickly become obvious what the order is.

Please ensure you use capital letters for the `X` and `O`, do not use the number zero for O.

You do not have to separate the class member function definitions from the declarations, but it is
encouraged.

## IPlayer

This pertains to `include/interface/IPlayer.h`

It should be a `class` with two `public` member functions:

### `Symbol()`

This should be a `const` accessible, _pure virtual_ function.

It should not take any arguments.

It should return a `char`.

### `TakeTurn()`

This should be a _pure virtual_ function.

It should take one argument: a `const` **reference** to an `std::vector` of `BoardPosition`

The `BoardPosition` enum is defined in `include/BoardPosition.h`

### HumanPlayer

this pertains to `include/HumanPlayer.h` and `src/HumanPlayer.cpp`

It should be a `class` that publicly inherits from `IPlayer`.

### `HumanPlayer()`

The constructor should take a `char` which it will need to store in its instance. You can generally
expect that you will be given either an `X`/`O` for this value, but you don't need to check.

### `Symbol()`

This function is of course the `override` for the interface. It should simply return the `char` that
you stored when your constructor was called.

### `TakeTurn()`

This function is again, an `override` for the interface. See the parameters and return type described in
the interface above.

The argument it takes should be used to tell the user which spaces are available and then their input should
be read. The `utility.h` headerprovides convenience functions to help you with doing this.

After you have read a valid choice from the user, you need to return it. It should not allow a player to select
an already-occupied space.

## Board

This pertains to `include/Board.h` and `src/Board.cpp`

It should be a `class` and all functions should be `public`.

The job of this class is to track the state of every cell in the 3x3 grid.

There are essentially 3 possible cases:
* Unoccupied
* Occupied by Player 1
* Occupied by Player 2

You are encouraged to use a standard library container (like `std::array` or `std::vector`) to track this,
but you do not have to.

### `FreePositions()`

This function should be `const` accessible. It should return a `std::vector` of `BoardPosition` elements.

It should return **only** the elements that are currently unoccupied. This function **must not**
result in any change to class data members (making it `const` accessible will prevent accidentally doing this)

### `OccupyPosition()`

This function is used to tell the Board that a player wishes to occupy a square.

It should take two arguments: 
* a `const` _reference_ to a `BoardPosition`
* a `const` _reference_ to an `IPlayer`

It should not return anything.

It should first check that the requested `BoardPosition` is already unoccupied. If it is occupied, you should
throw an exception, or if you don't know what that is, print an error out so you can read it. Strictly speaking,
you don't need to implement this safety check, but you will have a better chance to catch any bugs you write
later on.

Assuming it is unoccupied, it should mark the requested position as owned by the player. You are free to do
this however you wish. It is suggested that you may wish to store a pointer to the `IPlayer`, but you don't
have to; the point is that you need to reliably track who owns the spot.

## `CurrentState()`

This function is used to "dump" the current state of the board. We will use it to render the board.

It should be `const` accessible. It should not take any arguments.

It should return an `std::vector` of `char` elements. Each element should contain either the player's character
(namely, an `X` or an `O`) or, if unoccupied, that particular position should be set to zero.

## Controller

This pertains to `include/Controller.h` and `src/Controller.cpp`

The controller orchestrates the game and is aware of a few different classes in order to achieve that goal.

### `Controller()`

The constructor will need a few arguments. All of these should be stored in its instance.

* 2x `IPlayer` - You must use either references or pointers since these are an interface. They represent
Player1 and Player2.

* `IRenderer` - This will again need to be a reference or pointer. This will be used to render the state of the
board onto the screen.

* `Board` - The controller will take care of dumping the board to the screen via the `Renderer` and informing
the board of players wishing to occupy a particular space as part of gameplay.

Again, all of the above needs to be stored in the Controller instance.

### `PlayGame()`

This kicks off gameplay. The basic game loop is as follows:

* Ask Player1 to make a move by calling their `IPlayer` instance.
* Update the board with Player1's move.
* Use the Renderer to print the new state of the board to the screen.
* Check if Player1 has won the game. If they have, let them know and return.
* Ask Player2 to make a move in the same manner as for Player1.
* Again use the Renderer to print the new state of the board.
* Check if Player2 has won the game. If they have, let them know and return.

Bear in mind, there are 9 squares, so Player 2 gets one less square to place than Player 1.

You **must not** optimise away the call to Player1 for the final turn. If you wish to optimise it, you
should do that in the `HumanPlayer` class.

#### `main()`

This pertains to `src/main.cpp`

This should be simple:

* Construct a `HumanPlayer` for Player1
* Construct a `HumanPlayer` for Player2
* Construct a `Renderer`
* Construct a `Controller` and give it the above 3 things.
* Call `PlayGame()` on the Controller you constructed.

### Renderer

If you're on Pro difficulty. No help for you on this one, you should know what you're doing.
