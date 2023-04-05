#include "second_page.h"
#include "ui_second_page.h"
second_page::second_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::second_page)
{
    ui->setupUi(this);
}

second_page::~second_page()
{
    delete ui;
}

void second_page::on_pushButton_clicked()
{
    creataccount = new create_account();
    hide();
    creataccount->show();
}

void second_page::on_pushButton_2_clicked()
{
  score = new score_page();
  hide();
  score->show();
}

void second_page::on_pushButton_3_clicked()
{
   exit(0);

}
