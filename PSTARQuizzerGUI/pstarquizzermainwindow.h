#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pstarquizzermainwindow.h"
#include "questionwindow.h"
#include <qdebug.h>

class PSTARQuizzerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    PSTARQuizzerMainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::PSTARQuizzerMainWindowClass ui;

	QuestionWindow* m_pQuestionWindow;

	//Pointers to internal members
	QAbstractButton* m_pStartQuizButton;
	QButtonGroup* m_pChapterSelectButtonGroup;

private slots:
	void StartQuiz(bool checked);
	void EnableWindow();
};
