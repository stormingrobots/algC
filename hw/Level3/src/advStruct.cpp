
#include <common.h>
//#include <varargs.h>
#include<stdarg.h>
#include<time.h>


#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


//--------------------------------------------------------------

// digital display for time format HH:MM:SS
//

void digitalDisplayTime(char* tm) {

	const int tmLen = 8;  // hh:mm:ss

	char digits[10][7] = {
	{ 1,1,0,1,1,1,1 },{ 0,0,0,1,0,0,1 },{ 1,0,1,1,1,1,0 },
	{ 1,0,1,1,0,1,1 },{ 0,1,1,1,0,0,1 },{ 1,1,1,0,0,1,1 },
	{ 1,1,1,0,1,1,1 },{ 1,0,0,1,0,0,1 },{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,0,0,1 }
	};
	char led[] = "_|_||_|";

	for (int r = 0; r < 3; r++)
	{
		printf("\n");
		for (int tmIdx = 0, digit; tmIdx < tmLen; tmIdx++)  // digit
		{
			if (tm[tmIdx] == ':')
			{
				(r != 0 ? printf("*") : printf(" "));
				continue;
			}
			digit = tm[tmIdx] - '0';
			if (r == 0)
			{
				(digits[digit][0] == 1 ? printf(" %c ", led[0]) : printf("   "));
				continue;
			}
			// 2nd & 3rd row
			for (int ledSlot = (r - 1) * 3 + 1; ledSlot <= r * 3; ledSlot++)
				(digits[digit][ledSlot] == 1 ? printf("%c", led[ledSlot]) : printf(" "));
		}
	}
	printf("\n");
}


void displayClock() {
	int i = 0, k = 0;
	char tmStr[9] = { 0 }; // hold hh:mm:ss
	time_t now;
	struct tm* timeinfo;
	time(&now);
	timeinfo = localtime(&now);

	printf("Press Enter 'k' to stop the clock...\n\n");

	while (true) {
		system("CLS");
		time(&now);
		timeinfo = localtime(&now);

		if (kbhit()) { // this exists only in window - if keyboard is hit
			if (getch() == 'k')
				break;
		}
		sprintf(tmStr, "%02d:%02d:%02d", timeinfo->tm_hour,
			timeinfo->tm_min, timeinfo->tm_sec);

		digitalDisplayTime(tmStr);
		sleep(.5);

	}

}

//==================================================
// Permission Bits :

void displayPermissions(int code)
{
	char readBit = 1 << 2;
	char writeBit = 1 << 1;
	char executeBit = 1 << 0;
	union permissions
	{
		unsigned char code; //one byte
		struct
		{
			unsigned char executeBit : 1;
			unsigned char writeBit : 1;
			unsigned char readBit : 1;

			unsigned char filler : 5;
		} parts;
	} givenPermissionCode;


	givenPermissionCode.parts.executeBit = code & executeBit;
	givenPermissionCode.parts.writeBit = (code & writeBit) >> 1;
	givenPermissionCode.parts.readBit = (code & readBit) >> 2;


	char messages[][10] = { "cannot", "can" };
	printf("%s read | %s write | %s execute",
		messages[givenPermissionCode.parts.readBit],
		messages[givenPermissionCode.parts.writeBit],
		messages[givenPermissionCode.parts.executeBit]);

}

//===============================
RGBcolor make_color(int red, int green, int blue)
{
	if (red < 0)
	{
		red = 0;
	}
	if (green < 0)
	{
		green = 0;
	}
	if (blue < 0)
	{
		blue = 0;
	}

	if (red > 255)
	{
		red = 255;
	}
	if (green > 255)
	{
		green = 255;
	}
	if (blue > 255)
	{
		blue = 255;
	}
	RGBcolor result;
	result.red = red;
	result.green = green;
	result.blue = blue;

	return result;

}

int getRed(RGBcolor color)
{
	return color.red;
}

bool equal_color(RGBcolor color1, RGBcolor color2)
{
	if ((color1.red == color2.red) && (color1.green == color2.green) && (color1.blue == color2.blue))
	{
		return true;
	}
	return false;
}

RGBcolor brighter(RGBcolor color)
{
	RGBcolor brighterColor;
	if ((color.red == 0) && (color.green == 0) && (color.blue == 0))
	{
		brighterColor.red = 3;
		brighterColor.green = 3;
		brighterColor.blue = 3;
		return brighterColor;
	}

	if ((color.red > 0) && (color.red < 3))
	{
		color.red = 3;
	}
	if ((color.green > 0) && (color.green < 3))
	{
		color.green = 3;
	}
	if ((color.blue > 0) && (color.blue < 3))
	{
		color.blue = 3;
	}

	color.red /= 0.7;
	color.green /= 0.7;
	color.blue /= 0.7;

	if (color.red > 255)
	{
		color.red = 255;
	}
	if (color.green > 255)
	{
		color.green = 255;
	}
	if (color.blue > 255)
	{
		color.blue = 255;
	}

	return color;
}



//EM: use pointer to func
double rectangleArea(myShape rect)
{
	return rect.u.rectangle.height * (double)rect.u.rectangle.width;
}
double circleArea(myShape circle)
{
	return circle.u.circle.radius * (double)circle.u.circle.radius * 3.1415926;
}
double areaShape(myShape s)
{
	double (*areas[])(myShape) = { circleArea, rectangleArea };

	return areas[s.myShape_kind](s);
}

myShape transform(myShape s, int x, int y)
{
	s.center.x += x;
	s.center.y += y;
	return s;
}
myShape scale(myShape s, double factor)
{
	if (s.myShape_kind == RECTANGLE)
	{
		s.u.rectangle.height *= factor;
		s.u.rectangle.width *= factor;
	}
	else
	{
		s.u.circle.radius *= factor;
	}
	return s;
}


Tokens code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

struct field
{
	int nth_word;
	char* loc;
};
int compare(const void* a, const void* b)
{
	field* p1 = (field*)a;
	field* p2 = (field*)b;

	int compared = strcmp(p1->loc, p2->loc);

	if (compared > 0)
	{
		return 1;
	}
	if (compared < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}

}
int* orderTokens() {
	//didn't know how to pass array of pointers into functoins, is it fine for now?
	const int max_char = 500;

	field mainSentenceFields[max_char] = { 0 };
	int locations[max_char] = { 0 };

	char* tokens[max_char] = { 0 };
	char sentence[max_char];
	char tokenSentence[max_char];

	getchar(); //clear a newline
	printf("enter a sentence: ");
	fgets(sentence, max_char, stdin);
	sentence[strlen(sentence) - 1] = '\0'; //gets rid of \n
	int num_word_sentence = 0;
	char* oldLocation;
	for (char* p = sentence; p != NULL;)
	{
		mainSentenceFields[num_word_sentence].loc = p;
		oldLocation = p;
		mainSentenceFields[num_word_sentence].nth_word = num_word_sentence + 1;

		p = strchr(p, ',');

		if (p != NULL)
		{
			mainSentenceFields[num_word_sentence].loc[p - oldLocation] = '\0';
			++p;

		}
		++num_word_sentence;

	}
	printf("Enter a list of tokens: ");
	fgets(tokenSentence, max_char, stdin);
	tokenSentence[strlen(tokenSentence) - 1] = '\0'; //get rid of \n

	int num_word_tokens = 0;
	for (char* p = tokenSentence; p; )
	{
		tokens[num_word_tokens] = p;
		oldLocation = p;
		p = strchr(p, ',');

		if (p != NULL)
		{
			tokens[num_word_tokens][p - oldLocation] = '\0';
			++p;
		}
		++num_word_tokens;
	}

	qsort(mainSentenceFields, num_word_sentence, sizeof(field), compare);

	field* found;
	field modelToFind;

	for (int i = 0; i < num_word_tokens; ++i)
	{
		modelToFind.loc = tokens[i];
		modelToFind.nth_word = 0; //just good to initialize to something **not needed though**
		found = (field*)bsearch(&modelToFind, mainSentenceFields, num_word_sentence, sizeof(field), compare);
		if (found == NULL)
		{
			locations[i] = -1;
		}
		else
		{
			locations[i] = found->nth_word;
		}


	}

	return locations;

}

