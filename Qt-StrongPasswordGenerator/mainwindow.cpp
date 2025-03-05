#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <QClipboard>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QVector>

#include "adapter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lb_password_copied->setVisible(false);

    connect(ui->btn_generate, &QPushButton::clicked, this, &MainWindow::onGenerateClick);
    connect(ui->btn_copy, &QPushButton::clicked, this, &MainWindow::onCopyClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGenerateClick()
{
    const int pwdLen = ui->cbox_pslength->currentText().toInt();
    const bool lowerCase = ui->cb_pslowercase->isChecked();
    const bool upperCase = ui->cb_psuppercase->isChecked();
    const bool symbols = ui->cb_pssymbols->isChecked();
    const bool numbers = ui->cb_psnumbers->isChecked();

    //at least ONE option is required!
    if (!lowerCase && !upperCase && !symbols && !numbers)
    {
        QMessageBox::critical(this, "Error", "At least one password option is required", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    QString availableCharTypes;
    if (lowerCase) availableCharTypes.append("abcdefghijklmnopqrstuvwxyz");
    if (upperCase) availableCharTypes.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (symbols) availableCharTypes.append("!@#$%&*()-=+~");
    if (numbers) availableCharTypes.append("0123456789");

    std::string str = availableCharTypes.toStdString();


    char *cstr = str.data();

    auto test = get_shuffle(pwdLen,cstr);

    ui->pet_password->clear();
    ui->pet_password->appendPlainText(test);
}


void MainWindow::onCopyClick()
{
    //copy to system clipboard only if there is a password set
    const QString pwd = ui->pet_password->toPlainText();
    if (pwd.length() >= 8)
    {
        QGuiApplication::clipboard()->setText(pwd);
        //show the label "copied to clipboard" for 2 seconds
        if (!ui->lb_password_copied->isVisible())
        {
            ui->lb_password_copied->setVisible(true);
            QTimer::singleShot(2000, this, [this](){ ui->lb_password_copied->setVisible(false); });
        }
    }
}

