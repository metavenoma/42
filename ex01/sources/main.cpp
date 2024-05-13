#include "Data.hpp"
#include "Serializer.hpp"
#include <unistd.h>

void sleepMs(unsigned long milliseconds) 
{
    usleep(milliseconds * 1000); 
}

const char *intToS(int number)
{
	static char buffer[3];
	std::sprintf(buffer, "%d", number);
	return (buffer);
}

int	main(void)
{
	Data *data = new Data();
	uintptr_t	raw = 0;
	Serializer	*serial = new Serializer();

	Data::AsciiArt::printWithBorder("This is \"data\", a structure that stores data (durr)!", WIDTH, PINK, YELLOW);
	sleepMs(4000);
	Data::AsciiArt::printWithBorder("These are the strings stored in data before serialization:", WIDTH, PINK, YELLOW);
	sleepMs(4000);
	for (int i = 0; i < 4; i++)
	{
		Data::AsciiArt::printWithBorder(data->getString(i).c_str(), WIDTH, HOT_PINK, BLUE);
		sleepMs(1500);
	}
	Data::AsciiArt::printWithBorder("And this is the meaningless number stored inside of data: ", WIDTH, PINK, YELLOW);
	sleepMs(2500);
	Data::AsciiArt::printWithBorder(intToS(data->getInt()), WIDTH, ORANGE, GREEN);
	sleepMs(2500);
	Data::AsciiArt::printWithBorder("We have an uintptr_t called \"raw\" ", WIDTH, PINK, YELLOW);
	sleepMs(2000);
	Data::AsciiArt::printWithBorder("And now we gon serialize data to raw! ", WIDTH, PINK, YELLOW);
	sleepMs(2000);
	Data::AsciiArt::printWithBorder("Calling serialize...", WIDTH, PINK, YELLOW);
	sleepMs(1000);
	Data::AsciiArt::printWithBorder("             ...", WIDTH, PINK, YELLOW);
	sleepMs(1000);
	Data::AsciiArt::printWithBorder("                 ...", WIDTH, PINK, YELLOW);
	sleepMs(1000);
	raw = serial->serialize(data);
	Data::AsciiArt::printWithBorder("Now we gonna desserialize:", WIDTH, PINK, YELLOW);
	sleepMs(1500);
	Data::AsciiArt::printWithBorder("                       ...calling deserialize ", WIDTH, PINK, YELLOW);
	sleepMs(1000);
	Data::AsciiArt::printWithBorder("            ....", WIDTH, PINK, YELLOW);
	sleepMs(1000);
	Data::AsciiArt::printWithBorder("                     ...", WIDTH, PINK, YELLOW);
	sleepMs(1000);
	Data::AsciiArt::printWithBorder("             ...", WIDTH, PINK, YELLOW);
	sleepMs(1000);
	Data::AsciiArt::printWithBorder("                  (\"-_-)", WIDTH, PINK, YELLOW);
	Data *newData = serial->deserialize(raw);
	sleepMs(2500);
	Data::AsciiArt::printWithBorder("OK, Done", WIDTH, PINK, YELLOW);
	sleepMs(1500);
	Data::AsciiArt::printWithBorder("Lets check the content of the new data pointer: ", WIDTH, PINK, YELLOW);
	sleepMs(2500);
	for (int i = 0; i < 4; i++)
	{
		Data::AsciiArt::printWithBorder(newData->getString(i).c_str(), WIDTH, HOT_PINK, BLUE);
		sleepMs(1500);
	}
	Data::AsciiArt::printWithBorder("And the int:", WIDTH, PINK, YELLOW);
	sleepMs(1500);
	Data::AsciiArt::printWithBorder(intToS(data->getInt()), WIDTH, ORANGE, GREEN);
	sleepMs(2500);
	Data::AsciiArt::printWithBorder("Thank you for your precious time! ", WIDTH, PINK, YELLOW);
	sleepMs(3000);
	return (0);
}
