// John Fahringer
// README for buggysolution

/******************************
// NOTE: I'm guessing this program was created with C++17 in mind. I found it impossible to find a viable solution for working with C++17. The closest I came was using Visual Studio and enabling C++17, but the program would terminate without any information displayed.
// I also had to make changes to 
*******************************/


A)
- One seemingly bug is that the seed value is not randomly generated, and thus the result is always the same evertime the program is run.


B)
/// Addressing compiling issues....
// Added <Assert.h> in war.hpp to use assert in in war.cpp's Card War::flip function
// Added "#include <algorithm> in deck.hpp to enable sort and shuffle
// In deck.cpp, I had to change the forloop in the ostream& operator<< function because the " << ' ' " part was throwing an error.

// Now that the code can compile in c++11, I changed the random number generation method, since the old one was not being random.
