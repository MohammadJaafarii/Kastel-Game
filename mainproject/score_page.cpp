#include "score_page.h"
#include <iostream>
#include "ui_score_page.h"
#include <QString>
#include <QFile>
#include <string>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include <fstream>
using namespace std;
FILE *info1;
FILE *info2;
class username{
public:
    string name;
    int score;
 };

int sort_function(int number_of_playes , username players[]){
    username temp;
    for (int i = 0; i < number_of_playes - 1; i++) {

            for (int j = 0; j < number_of_playes - 1 - i; j++) {

                if (players[j].score < players[j + 1].score) {
                    temp = players[j];
                    players[j] = players[j + 1];
                    players[j + 1] = temp;

                }
            }

        }

    return 0;

};
score_page::score_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::score_page)
{
    ui->setupUi(this);

    username information;
    int number_of_players = 0;
    fopen_s(&info1, "shomaresh.txt", "r");

    if (!info1) {
        exit(0);

    }

     fread(&number_of_players, sizeof(int), 1, info1);

   while (!feof(info1)) {

      fread(&number_of_players, sizeof(int), 1, info1);


  }
  fclose(info1);


    username *players = new username [number_of_players];
    int i =0 ;
    fstream file("file.txt" , ios ::in | ios :: app ) ;
    if ( file.is_open())
    {   string name;
        while (getline(file,name))
        {
            players[i].name = name;
            i++;
        }
    }
    file.close();
    i = 0;
    fstream file10("score.txt" , ios ::in | ios :: app ) ;
    if ( file10.is_open())
    {   int score;
        while (file10 >> score)
        {
            players[i].score = score;
            i++;
        }
    }
    file.close();



   sort_function(number_of_players,players);

   ofstream file3("file1.txt" , ios :: out  ) ;
   if ( file3.is_open())
   {
       for (int i = 0 ; i <number_of_players;i++){

           file3 << players[i].name<<endl;
           file3 <<players[i].score<<endl;
       }
   }
   file.close();
    QFile file2 ("file1.txt");

    if (!file2.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return ;
    }
    QTextStream in (&file2);

    ui->textBrowser->setText(in.readAll());
    file.close();

}

score_page::~score_page()
{
    delete ui;
}

void score_page::on_pushButton_clicked()
{
    exit(0);
}
