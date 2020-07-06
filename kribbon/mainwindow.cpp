#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "kparserui.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	KParserUI parser(NULL);
}

MainWindow::~MainWindow()
{
	delete ui;
}

