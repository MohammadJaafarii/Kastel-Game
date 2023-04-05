#include "main_game.h"
#include "ui_main_game.h"
#include <iostream>
#include <QMessageBox>
#include <QString>
#include <QtDebug>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <string>
#include <QMessageBox>


FILE *info ;
using namespace std ;
class userpass{
public:
    char name [100];
    QString username;
    QString password;

};

QString cells[9][9];
class Check{
public:
    int score (){
        int score1 = 0;
        for (int i = 0;i<9;i++){
            for (int j =0 ; j<9 ; j++){
                if (cells[i][j] != "-1"){
                    if (cells[i][j] == "1" || cells[i][j] == "2" ||cells[i][j] == "3" || cells[i][j] == "4" || cells[i][j] == "5" ||cells[i][j] == "6" || cells[i][j] == "7" || cells[i][j] == "8" ||cells[i][j] == "9")
                    score1 ++;
                }
            }
        }
        return score1 - 30;
    }
    // return false if find repeatation, if not return true
    bool check_row(int row,int column)
    {
        for (int j = 0; j<9 ;j++){
            if (cells[row][j] != "-1"){
                if (j != column ){
                    if (cells[row][column] == cells[row][j] )return true;
                }
            }
        }
        return false;

    }
    // return false if find repeatation, if not return true
    bool check_column(int row, int column){

        for (int i = 0; i<9 ;i++){
            if (cells[i][column] != "-1"){
                if (i != row ){
                    if (cells[row][column] == cells[i][column] )return true;
                }
            }
        }
        return false;


    }
    bool check_square (int row, int column){


        if (column>=0 && column<3){
            if (row >=0 && row <3){

                for (int i = 0; i<3 ; i++){

                    for(int j=0; j<3; j++){
                        if (cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells [i][j])return true;
                    }
                }
                return false;
            }

            if (row >=3 && row <6){
                for (int i=3 ;i <6;i++){
                    for (int j =0;j<3;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }

            if (row >=6 && row <9){
                for (int i =6 ;i<9;i++){
                    for (int j=0 ;j<3;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }

        }


        if (column>=3 && column<6){

            if (row >=0 && row <3){

                for (int i = 0; i<3 ; i++){

                    for(int j=3; j<6; j++){
                        if (cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells [i][j])return true;
                    }
                }
                return false;

            }

            if (row >=3 && row <6){
                for (int i=3 ;i <6;i++){
                    for (int j =3;j<6;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }

            if (row >=6 && row <9){
                for (int i =6 ;i<9;i++){
                    for (int j=3 ;j<6;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }

        }

        if (column >= 6 && column <9){

            if (row >=0 && row <3){

                for (int i = 0; i<3 ; i++){

                    for(int j=6; j<9; j++){
                        if (cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells [i][j])return true;
                    }
                }
                return false;

            }

            if (row >=3 && row <6){
                for (int i=3 ;i <6;i++){
                    for (int j =6;j<9;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }

            if (row >=6 && row <9){
                for (int i =6 ;i<9;i++){
                    for (int j=6 ;j<9;j++){
                        if(cells[i][j]== "-1" || (i == row && j == column))continue;
                        if (cells[row][column] == cells[i][j])return true;
                    }
                }
                return false;

            }


        }
    }
};
Check check;

/**class random_num{
public:
    int n1 = 0, n2 = 0 , row = 0,column = 0;

    int rand1(){
        srand(time(0));
        int number = rand()%5 + 1;
        return number;
    }

    void rand2(){
        for (int abz = 0; abz<3 ; abz ++){
            int howmany = 0 ;
            bool random_check;
            bool square_33 = true;
            srand(time(0));

            howmany = rand1();

            int *check_repeat_row = new int [howmany];
            int *check_repeat_column = new int [howmany];
            for (int j =0 ;j<howmany;j++){
                check_repeat_row[j]=-1;
                check_repeat_column[j]=-1;
            }
            for (int i=0;i<howmany;i++){
                do {
                    square_33 = true;
                    while (square_33){
                        srand(time(0));
                        row = rand()% (((n1*3)+3) +(n1*3));
                        column = rand1()% ((n2*3)+3) +(n2*3);
                        if (row /3 == n1 && column / 3 == n2){
                            square_33 = false;
                            if (n2 == 3){
                                n1 ++;
                                n2 = 0;
                            }
                        }
                    }
                    random_check = false;
                    for (int j =0 ; j<howmany ; j++){

                        if (row == check_repeat_row[j] && column == check_repeat_column[j] ){

                            random_check = true;
                            break;
                        }
                    }

                }
                while (random_check);
                for (int z = 0 ; z<howmany; z++){
                    if(check_repeat_row[z] == -1){
                        check_repeat_row [z]= row;
                        break;
                    }

                }
                for (int z = 0 ; z<howmany; z++){
                    if(check_repeat_column[z] == -1){
                        check_repeat_column [z]= column;
                        break;
                    }

                }
                rand3 ();

            }
            delete []check_repeat_row;
            delete []check_repeat_column;
            n2++;

        }
    }

    int rand3 (){
        srand(time(0));
        int number_of_cells;
        bool ch_row = true;
        bool ch_column  = true;
        bool ch_square33 = true;
        while (ch_row == true || ch_column == true || ch_square33 == true){

            number_of_cells= rand1()% 9 +1;
            QString s = QString::number(number_of_cells);
            cells[row][column] = s;
            ch_row =check.check_row(row , column);
            ch_column = check.check_column(row , column);
            ch_square33 = check.check_square(row , column);
        }
        return -1 ;
    }

};**/
main_game::main_game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_game)
{


    ui->setupUi(this);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cells [i][j]="-1" ;
        }

    }
    cells[0][0] ="5";
    cells[1][0] ="6";
    cells[3][0] ="8";
    cells[4][0] ="4";
    cells[5][0] ="7";
    cells[0][1] ="3";
    cells[2][1] ="9";
    cells[6][1] ="6";
    cells[2][2] ="8";
    cells[1][3] ="1";
    cells[4][3] ="8";
    cells[7][3] ="4";
    cells[0][4] ="7";
    cells[1][4] ="9";
    cells[3][4] ="6";
    cells[5][4] ="2";
    cells[7][4] ="1";
    cells[8][4] ="8";
    cells[1][5] ="5";
    cells[4][5] ="3";
    cells[7][5] ="9";
    cells[6][6] ="2";
    cells[2][7] ="6";
    cells[6][7] ="8";
    cells[8][7] ="7";
    cells[3][8] ="3";
    cells[4][8] ="1";
    cells[5][8] ="6";
    cells[7][8] ="5";
    cells[8][8] ="9";

    ui->lineEdit->setText(" GUIDE");
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000);
    userpass information;
    int number_of_players = 0;



}



main_game::~main_game()
{
    delete ui;
}


void main_game::on_tableWidget_cellChanged(int row, int column)

{

    bool ckeck_row_t = true;
    bool check_column_t = true;
    bool check_square = true;
    cells[row][column] =  ui->tableWidget->item(row,column)->text();
    ckeck_row_t = check.check_row(row,column);
    check_column_t = check.check_column(row , column);
    check_square =check.check_square(row,column);
    if (ckeck_row_t == true || check_column_t == true || check_square == true){
        cells[row][column] =  ui->tableWidget->item(row,column)->text();
        ui->lineEdit->setText(" GUIDE : You Can't Choose This Number :(");
        ui->tableWidget->item(row,column)->setBackgroundColor(QColor(225,26,0));
        ckeck_row_t = check.check_row(row,column);
        check_column_t = check.check_column(row , column);
        check_square =check.check_square(row,column);


    }
    else
    {
        ui->tableWidget->item(row,column)->setBackgroundColor(QColor(85,255,0));
        ui->lineEdit->setText(" GUIDE");

    }
}

void main_game::myfunction()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");

    ui->Datetime->setText("                                                                                       "+time_text);

}



void main_game::on_pushButton_clicked()
{
    ofstream file("score.txt" , ios ::out | ios :: app ) ;
	int score12;
    score12 = check.score();
	if ( file.is_open())
    {
//        QString s = QString::number(score12);
//        string score_string = s.toStdString();
        file << score12<<endl;
	}
    file.close();
//    fopen_s(&info, "Information.txt", "a");

//    fwrite(&score12, sizeof(int), 1, info);

//    fclose(info);
    hide();
    score1 = new score_page();
    score1->show();

}




