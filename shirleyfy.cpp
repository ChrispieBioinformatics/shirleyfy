#include <iostream>       // std::cout, std::endl output
#include <thread>         // std::this_thread::sleep_for pause program
#include <chrono>         // std::chrono::seconds measure seconds
#include <string.h>
#include <algorithm>

void waitTime(int some)
{
	unsigned int usome = some;
	std::this_thread::sleep_for (std::chrono::milliseconds(usome));
}

void slow_printl(std::string str, int delaytime)
{
	char char_array[str.size()];
	str.copy(char_array, str.size());

	for (int i = 0; i < sizeof(char_array); i++) {
        std::cout << char_array[i] << std::flush;
        waitTime(delaytime);
    }

    std::cout << std::endl;
}

void slow_print(std::string str, int delaytime)
{

	char char_array[str.size()];
	str.copy(char_array, str.size());

	for (int i = 0; i < sizeof(char_array); i++) {
        std::cout << char_array[i] << std::flush;
        waitTime(delaytime);
    }

}

bool isVowel(char letter)
{
	if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
		return true;
	else
		return false;
}

std::string getHeadline(std::string name)
{
	// Prepare constant headline
	std::string headline = "Let's do " + name + "!\n";

	headline += name + ", " + name + ", \n";

	return headline;
}

std::string getBodyline(std::string shortname, std::string name)
{
	// Prepare the not constant body line, depending on the name
	std::string bodyline = "Bo-b" + shortname + "\nBonana fanna fo-f" + shortname + "\nFee fi mo-m" + shortname + ", " + name; // finish/append the lyrics

	return bodyline;
}

int getShortnameOffset(char *char_array, int length)
{
	// Start with the second char because the first is already done.
	int offset = 1;

	// Check all other chars until a vowel is found.
	for (int i = 1; i <= length; ++i)
	{
		if ( !isVowel( char_array[i] ) )
			continue; // Check the next char

		offset = i;
		break;
	}

	return offset;
}

std::string getShortname(char *char_array, int offset, int length)
{
	std::string shortname = "";

	// Use this shortened version of the name to build the lyrics string
	for (int i = offset; i <= length; ++i)
	{
		shortname += char_array[i];
	}

	// Everything past the first vowel
	return  shortname;
}

std::string getLyrics(std::string name)
{

	// Create a char array with the size of letters contained in the name.
	char char_array[name.size()];

	// Convert name to a char array
	name.copy(char_array, name.size());

	// Get the constant headline
	std::string returnValue = getHeadline(name);

	// Check if the first char is a vowel
	if ( isVowel(char_array[0]) )
	{
		returnValue += getBodyline(name, name); // Finish the lyrics
		return returnValue;
	}

	// Find the first vowel (important to hand over the size of the char array)
	int offset = getShortnameOffset(char_array, name.size());
	
	// Cut everything off to the first vowel
	std::string shortname = getShortname(char_array, offset, (name.size()-offset) );

	// Finish the Lyrics
	returnValue += getBodyline(shortname, name);
	
	return returnValue;
}

int main(int argc, char const *argv[])
{
	
	if (argc < 2)
	{
		slow_printl("Where is the name?", 10);
		return 0;
	}

	std::string name = argv[1];

    slow_printl("Okay...", 100);

    waitTime(1000);

    slow_printl("Let's begin the name game...", 100);

    slow_printl("Name is " + name, 100);

    std::string output = getLyrics(name);

    slow_printl(output, 100);

    return 0;
}