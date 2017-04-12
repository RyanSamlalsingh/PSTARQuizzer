#ifndef H__QUESTIONUTILS
#define H__QUESTIONUTILS
//Helper functions and structures that don't quite fit anywhere else can go here

#include<string>

using namespace std;

enum
{
	NUMBER_OF_CHAPTERS = 14
};

typedef enum ANSWER_LETTER_ENUM
{
	a,
	b,
	c,
	d,
} ANSWER_LETTER_ENUM;

typedef enum CHAPTER_NUMBER_ENUM
{
	chapter_1 = 0,
	chapter_2,
	chapter_3,
	chapter_4,
	chapter_5,
	chapter_6,
	chapter_7,
	chapter_8,
	chapter_9,
	chapter_10,
	chapter_11,
	chapter_12,
	chapter_13,
	chapter_14,
} CHAPTER_NUMBER_ENUM;

//Prevent circular includes
class Question;

class QuestionUtils
{		
	public:
		static string getChapterName(int chapter_number);
		static int getMaxNumberOfQuestions();
		static Question* generateQuestions();
		static int getNumQuestionsInChapter(CHAPTER_NUMBER_ENUM chapter);
	private:
		static const string CHAPTER_NAMES[NUMBER_OF_CHAPTERS];
		static int const NUM_QUESTIONS_IN_CHAPTER[NUMBER_OF_CHAPTERS];
};

#endif