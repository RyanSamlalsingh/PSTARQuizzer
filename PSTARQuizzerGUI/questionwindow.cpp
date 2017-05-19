#include "QuestionWindow.h"

QuestionWindow::QuestionWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void QuestionWindow::closeEvent(QCloseEvent* event)
{
	emit(destroyed());
	delete this;
}
