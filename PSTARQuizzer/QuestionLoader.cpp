#include "QuestionLoader.h"

QuestionLoader::QuestionLoader()
{
	pAllQuestions = NULL;
	pSelectedQuestions = NULL;
	numAllQuestions = 0;
	numSelectedQuestions = 0;
	selectedQuestionIterator = 0;
	isAllQuestionsRandomOrder = false;
	isQuestionsRandomOrderByChapter = false;
}

QuestionLoader::~QuestionLoader()
{
	delete[] pSelectedQuestions;
	delete[] pAllQuestions;
	delete this;
}

QuestionLoader& QuestionLoader::operator=(const QuestionLoader&)
{
	return getInstance();
}

QuestionLoader& QuestionLoader::getInstance()
{
	static QuestionLoader questionLoaderInstance;
	if (questionLoaderInstance.pAllQuestions == NULL)
	{
		questionLoaderInstance.pAllQuestions = QuestionUtils::generateQuestions();
	}
	return questionLoaderInstance;
}

void QuestionLoader::selectQuestions(quiz_parameter* parameters)
{
	srand(unsigned int(time(NULL)));

	isAllQuestionsRandomOrder = parameters->isAllQuestionsRandomOrder;
	isQuestionsRandomOrderByChapter = parameters->isQuestionsRandomOrderInChapter;

	if (NULL == pSelectedQuestions)
	{
		pSelectedQuestions = new Question*[numAllQuestions];
	}

	for (int chapterIndex = chapter_1; chapterIndex < NUMBER_OF_CHAPTERS; chapterIndex++)
	{
		if (parameters->useQuestionsFromChapter[chapterIndex])
		{
			numSelectedQuestions += QuestionUtils::getNumQuestionsInChapter((CHAPTER_NUMBER_ENUM)chapterIndex);
		}
	}

	int selectedQuestionIndex = 0;
	int chapterOffset = 0;

	for (unsigned int questionIndex = 0; questionIndex < numAllQuestions; questionIndex++)
	{
		Question* currentQuestion = &pAllQuestions[questionIndex];

		if (true == parameters->useQuestionsFromChapter[currentQuestion->getChapterNum()])
		{
			if (isAllQuestionsRandomOrder)
			{
				int randomNum = rand();
				for (unsigned int numProbes = 0; numProbes < numSelectedQuestions; numProbes++)
				{
					int randomQuestionPlaceIndex = (randomNum + numProbes) % numSelectedQuestions;

					if (NULL == pSelectedQuestions[randomQuestionPlaceIndex])
					{
						pSelectedQuestions[randomQuestionPlaceIndex] = currentQuestion;
						break;
					}
				}
			}
			else if (isQuestionsRandomOrderByChapter)
			{
				int lowerBounds = selectedQuestionIndex - currentQuestion->getQuestionNumber() + 1;
				int questionsInChapter = QuestionUtils::getNumQuestionsInChapter(currentQuestion->getChapterNum());
				int upperBounds = lowerBounds + questionsInChapter - 1;

				int randomNum = rand();
				//linear probe
				for (int numProbes = 0; numProbes < questionsInChapter; numProbes++)
				{
					int randomQuestionPlaceIndex = ((randomNum + numProbes) % questionsInChapter) + lowerBounds;
					
					if (NULL == pSelectedQuestions[randomQuestionPlaceIndex])
					{
						pSelectedQuestions[randomQuestionPlaceIndex] = currentQuestion;
						break;
					}
				}
			}
			else
			{
				pSelectedQuestions[selectedQuestionIndex] = currentQuestion;
			}

			selectedQuestionIndex++;
			
		}
	}
}

Question* QuestionLoader::nextQuestion()
{
	Question* nextQuestion = NULL;

	nextQuestion = pSelectedQuestions[selectedQuestionIterator];
	selectedQuestionIterator++;

	return nextQuestion;
}
