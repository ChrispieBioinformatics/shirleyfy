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
	char p[str.size()];
	str.copy(p, str.size());
	
	for (int i = 0; i < sizeof(p); i++) {
        std::cout << p[i] << std::flush;
        waitTime(delaytime);
    }

    std::cout << std::endl;
}

void slow_print(std::string str, int delaytime)
{

	char p[str.size()];
	str.copy(p, str.size());
	
	for (int i = 0; i < sizeof(p); i++) {
        std::cout << p[i] << std::flush;
        waitTime(delaytime);
    }

}

void load(int delaytime)
{
	for (int i = 0; i <= 100; ++i) {
        std::cout << "\r\tProgress: " << i << "%" << std::flush;
        waitTime(delaytime); // pause
    }

    std::cout << std::endl;
}

/*
rules for name changes...

The name game. Shirley! Shirley, Shirley
Bo-ber-ley, bo-na-na fanna
Fo-fer-ley. fee fi mo-mer-ley, Shirley!
Lincoln! Lincoln, Lincoln. bo-bin-coln
Bo-na-na fanna, fo-fin-coln
Fee fi mo-min-coln, Lincoln!
Come on ev'rybody, I say now let's play a game
I betcha I can make a rhyme out of anybody's name
The first letter of the name
I treat it like it wasn't there
But a "B" or an "F" or an "M" will appear
And then I say "Bo" add a "B" then I say the name
Then "Bo-na-na fanna" and "fo"
And then I say the name again with an ""f" very plain
Then "fee fi" and a "mo"
And then I say the name again with an "M" this time
And there isn't any name that I can't rhyme
Arnold! Arnold, Arnold bo-bar-nold
Bo-na-na, fanna fo-far-nold
Fee fi m-mar-mold. Arnold!
But if the first two letters are ever the same
Crop them both, then say the name
Like Bob, Bob, drop the "B's", Bo-ob
Or Fred, Fred, drop the "F's", Fo-red
Or Mary, Mary, drop the "M's", Mo-ary
That's the only rule that is contrary
And then I say "Bo" add a "B" then I say the name
Then "Bo-na-na fanna" and "fo"
And then I say the name again with an ""f" very plain
Then "fee fi" and a "mo"
And then I say the name again with an "M" this time
And there isn't any name that I can't rhyme
Say Tony, Tony, bo-bo-ney
Bo-na-na fanna, fo-fo-ney
Fee fi mo-mo-ney, Tony!
Let's do Billy!
Billy, Billy, bo-gil-ly, bo-na-na 
Fanna, fo-fil-ly, 
Fee fi mo-mil-ly, Billy!
Let's do Marsha!
Marsha, Marsha, bo-bar-sha
Bo-na-na fanna, fo-far-sha
Fee fi mo-ar-sha, Marsha!
Little trick with Nick!
Nick, Nick, bo-bick, bo-na-na
Fanna fo fick, fee fi mo-mick. Nick!
The name game
*/

std::string checkName(std::string name)
{

	char p[name.size()];

	name.copy(p, name.size());

	std::string returnValue = "Let's do " + name + "!\n";

	returnValue += name + ", " + name + ", ";

	if (p[0] == 'a' || p[0] == 'e' || p[0] == 'i' || p[0] == 'o' || p[0] == 'u')
	{
		returnValue += "Bo-b" + name + "\nBonana fanna fo-f" + name + "\nFee fi mo-m" + name + ", " + name;
		return returnValue;
	}

	std::string shortname = "";

	int offset = 1;
	for (int i = 1; i < sizeof(p); ++i)
	{
		if (p[i] != 'a' && p[i] != 'e' && p[i] != 'i' && p[i] != 'o' && p[i] != 'u')
		{
			continue;
		}
		offset = i;
		break;
	}

	for (int i = offset; i < sizeof(p); ++i)
	{
		shortname += p[i];
	}

	returnValue += "Bo-b" + shortname + "\nBonana fanna fo-f" + shortname + "\nFee fi mo-m" + shortname + ", " + name;
	
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
    
    load(30); // Progress x%

    slow_printl("Name is " + name, 100);

    std::string output = checkName(name);

    slow_printl(output, 100);

    return 0;
}