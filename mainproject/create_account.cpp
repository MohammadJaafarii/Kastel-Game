#include "create_account.h"
#include "ui_create_account.h"
#include <QMessageBox>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <fstream>

FILE *shomaresh_d;

using namespace std ;
create_account::create_account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::create_account)
{
    ui->setupUi(this);
}

create_account::~create_account()
{
    delete ui;
}

class userpass{
public:
    QString name;
    QString username;
    QString password;
};
void create_account::on_pushButton_clicked()
{userpass information;
    information.name = ui->lineEdit->text();
    information.username =ui->lineEdit_2->text();
    information.password = ui ->lineEdit_3->text();
    QString nameplayer;
    nameplayer = information.name;
	ofstream file("file.txt" , ios :: out | ios :: app ) ;
    if ( file.is_open())
    {
        string name = information.name.toStdString();
        file << name <<endl;
    }
    file.close();
    int number_of_players = 0;
    fopen_s(&shomaresh_d, "shomaresh.txt", "ab");
    fclose(shomaresh_d);
    fopen_s(&shomaresh_d, "shomaresh.txt", "rb");
    if (!shomaresh_d)exit(0);
    fread(&number_of_players,sizeof(int),1,shomaresh_d);
    fclose(shomaresh_d);
    number_of_players++;
    fopen_s(&shomaresh_d, "shomaresh.txt", "r+b");

        if (!shomaresh_d) {

            exit(0);
        }

        fwrite(&number_of_players, sizeof(int), 1, shomaresh_d);

        fclose(shomaresh_d);
    //write new members in file
//    fopen_s(&Information, "Information.txt", "a");

//    fwrite(&information.name, sizeof(QString), 1, Information);

//    fclose(Information);

    QMessageBox::information(this,"SIGN UP STATUS","<FONT COLOR='#00da69'> You Logged in Successfully :)</FONT>");
    maingame = new main_game();
    hide();
    maingame->show();



}
