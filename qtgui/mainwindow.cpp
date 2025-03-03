#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adapter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow())
{
    m_ui->setupUi(this);
    connect(m_ui->pushButton, SIGNAL(clicked()), SLOT(copyPassword()));
}

MainWindow::~MainWindow() = default;

void MainWindow::copyPassword(){
    auto test=get_random(5);
    m_ui->lineEdit->setText(test);
}
