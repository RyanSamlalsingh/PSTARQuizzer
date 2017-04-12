#include"QuestionUtils.h"

const string QuestionUtils::CHAPTER_NAMES[NUMBER_OF_CHAPTERS] =
{
	"Collision Avoidance"
	"Visual Signals",
	"Communications",
	"Aerodromes",
	"Equipment",
	"Pilot Responsibilities",
	"Wake Turbulence",
	"Aeromedical",
	"Flight Plans and Itineraries",
	"Clearances and Instructions",
	"Aircraft Operations",
	"Regulations - General Airspace",
	"Controlled Airspace",
	"Aviation Occurences"
};

const int QuestionUtils::NUM_QUESTIONS_IN_CHAPTER[NUMBER_OF_CHAPTERS] =
{
	10,
	8,
	29,
	10,
	11,
	23,
	15,
	13,
	11,
	6,
	17,
	21,
	12,
	6
};

string QuestionUtils::getChapterName(int chapter_number)
{
	string chapter_name = NULL;
	//TODO: Michael.
	return chapter_name;
}

int QuestionUtils::getMaxNumberOfQuestions()
{
	static int numberOfQuestions = 0;

	if (0 == numberOfQuestions)
	{
		for (char chapterIndex = 0; chapterIndex < NUMBER_OF_CHAPTERS; chapterIndex++)
		{
			numberOfQuestions += NUM_QUESTIONS_IN_CHAPTER[chapterIndex];
		}
	}

	return numberOfQuestions;
}

Question* QuestionUtils::generateQuestions()
{
	Question* question_list = NULL;
	//TODO: Michael.
	return question_list;
}

int QuestionUtils::getNumQuestionsInChapter(CHAPTER_NUMBER_ENUM chapter)
{
	return NUM_QUESTIONS_IN_CHAPTER[chapter];
}
