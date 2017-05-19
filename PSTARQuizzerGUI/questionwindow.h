#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_questionwindow.h"

class QuestionWindow : public QMainWindow
{
	Q_OBJECT

public:
	QuestionWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::QuestionWindow ui;
	void closeEvent(QCloseEvent * event);
};
