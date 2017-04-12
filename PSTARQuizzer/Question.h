#ifndef H__QUESTION
#define H__QUESTION


#include"QuestionUtils.h" //<string> is already included in QuestionUtils.h... so no need to re-include!

using namespace std;

class Question
{
	public:
		/*
		This is the only constructor we should be using, as it sets all fields at once
		and we know all of these values at question initialization time
		*/
		Question(int chap_num, 
			int quest_num, 
			string quest_txt, 
			string* answers, 
			ANSWER_LETTER_ENUM correct_ans);

		bool is_answer_correct(ANSWER_LETTER_ENUM given_answer);
		CHAPTER_NUMBER_ENUM getChapterNum();
		int getQuestionNumber();

	private:
		//We make this constructor private because we don't want to use it... like Java
		Question();

		/*
		 * These are obvious members of a question
		 */
		CHAPTER_NUMBER_ENUM chapter_number;
		int questionNumber;
		string question_text;
		//answers[0] is a ... -> ... answers[3] is d
		string* answers;
		ANSWER_LETTER_ENUM correct_answer;
};

#endif