#ifndef CREATE_ACCOUNT_H
#define CREATE_ACCOUNT_H

#include <QDialog>
#include <main_game.h>
#include <score_page.h>
#include <pass_file.h>
namespace Ui {
class create_account;
}

class create_account : public QDialog
{
    Q_OBJECT

public:
    explicit create_account(QWidget *parent = nullptr);
    ~create_account();

private slots:
    void on_pushButton_clicked();

private:
    Ui::create_account *ui;
    main_game * maingame;
};

#endif // CREATE_ACCOUNT_H
