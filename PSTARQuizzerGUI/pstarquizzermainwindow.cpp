#include "PSTARQuizzerMainWindow.h"

PSTARQuizzerMainWindow::PSTARQuizzerMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_pQuestionWindow = NULL;
	m_pStartQuizButton = findChild<QAbstractButton*>("startQuizButton");

	connect(m_pStartQuizButton, SIGNAL(clicked(bool)), this, SLOT(StartQuiz(bool)));
	m_pChapterSelectButtonGroup = findChild<QButtonGroup*>("chapterSelectButtonGroup");

	qDebug() << m_pChapterSelectButtonGroup->buttons();

}

void PSTARQuizzerMainWindow::StartQuiz(bool checked)
{
	setDisabled(true);

	m_pQuestionWindow = new QuestionWindow();

	connect(m_pQuestionWindow, SIGNAL(destroyed()), this, SLOT(EnableWindow()));
	m_pQuestionWindow->show();

}

void PSTARQuizzerMainWindow::EnableWindow()
{
	m_pQuestionWindow = NULL;
	setDisabled(false);
}