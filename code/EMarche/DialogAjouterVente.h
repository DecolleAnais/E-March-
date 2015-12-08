#ifndef DIALOGAJOUTERVENTE_H
#define DIALOGAJOUTERVENTE_H

#include <QDialog>

namespace Ui {
class DialogAjouterVente;
}

class DialogAjouterVente : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjouterVente(QWidget *parent = 0);
    ~DialogAjouterVente();

private:
    Ui::DialogAjouterVente *ui;
};

#endif // DIALOGAJOUTERVENTE_H
