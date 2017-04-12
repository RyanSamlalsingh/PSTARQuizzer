#include"question.h"


Question::Question(int chap_num,
	int quest_num,
	string quest_txt,
	string* answers,
	ANSWER_LETTER_ENUM correct_ans) 
{
	//TODO: Michael. Should be super easy. Try using an initializer list.
	// See http://www.cprogramming.com/tutorial/initialization-lists-c++.html -> "Using Initialization Lists to Initialize Fields"
}

bool Question::is_answer_correct(ANSWER_LETTER_ENUM given_answer)
{
	bool is_correct = false;
	//TODO: Michael.
	return is_correct;
}

CHAPTER_NUMBER_ENUM Question::getChapterNum()
{
	//TODO: Michael
	return chapter_1;
}

int Question::getQuestionNumber()
{
	return questionNumber;
}
