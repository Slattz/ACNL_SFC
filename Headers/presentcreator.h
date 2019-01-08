#ifndef PRESENTCREATOR_H
#define PRESENTCREATOR_H

#include <QDialog>
#include <QAbstractButton>
#include <QUrl>
#include "values.h"

//Present
struct Present_Payload { //Content Datatype in Payload Content Header must be 0x00010002; Size of payload: 0xC
    u32 Checksum;  //This is over the next 8 bytes
    u8  Magic;     //Has to be 0x2
    u8  Padding;   //Always 0
    u16 PresentID; //Written to the player struct, used to ensure the player can't get the gift more than once
    u32 ItemPreWA; //Pre-WA Item ID; Game does (Item & ~0xE000) && < 0x11AD. uses value to get WA Item ID from buffer
};


namespace Ui {
class PresentCreator;
}

class PresentCreator : public QDialog
{
    Q_OBJECT

public:
    explicit PresentCreator(Present_Payload* Present, QWidget *parent = nullptr);
    ~PresentCreator();
    Present_Payload* GetPresentData(void);

private slots:
    void on_LE_PresentID_textEdited(const QString &arg1);
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_LE_ItemID_editingFinished();

    void on_LE_PageSearch_textChanged(const QString &arg1);

    void on_BB_PageSearchControl_clicked(QAbstractButton *button);

private:
    Ui::PresentCreator *ui;
    Present_Payload* m_Present = nullptr;
    QString m_searchtext;
};

#endif // PRESENTCREATOR_H
