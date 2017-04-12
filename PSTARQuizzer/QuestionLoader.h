#ifndef H__QUESTIONLOADER
#define H__QUESTIONLOADER

#include"Question.h"
#include"QuestionUtils.h"
#include<cstdlib>
#include<ctime>

typedef struct quiz_parameter
{
	bool isAllQuestionsRandomOrder;
	bool isQuestionsRandomOrderInChapter;
	bool useQuestionsFromChapter[14];
} quiz_parameter;

//We will be enforcing singleton design with QuestionLoader
//as we only want one of them in the program.
class QuestionLoader
{
	public:
		static QuestionLoader& getInstance();
		void selectQuestions(quiz_parameter* parameters);
		Question* nextQuestion();

	private:
		QuestionLoader();
		~QuestionLoader();
		QuestionLoader(const QuestionLoader&);
		QuestionLoader& operator=(const QuestionLoader&);
		
		//Array of all questions generated
		Question* pAllQuestions;
		//Count of all questions generated
		unsigned int numAllQuestions;

		//Array of pointer to questions selected by user
		Question** pSelectedQuestions;
		//Count of all questions selected by user
		unsigned int numSelectedQuestions;

		unsigned int selectedQuestionIterator;

		bool isAllQuestionsRandomOrder;
		bool isQuestionsRandomOrderByChapter;



};

#endif
