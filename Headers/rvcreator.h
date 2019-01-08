#ifndef RVCREATOR_H
#define RVCREATOR_H

#include <QDialog>
#include <QAbstractButton>
#include "values.h"

struct RV_Payload {
    u32 Checksum;   //This is over the next 4 bytes
    u8  Magic;      //Has to be 0x1
    u8  Padding;    //Always 0
    u16 VillagerID; //No restrictions
};

namespace Ui {
class RVCreator;
}

class RVCreator : public QDialog
{
    Q_OBJECT

public:
    explicit RVCreator(RV_Payload* RV, QWidget *parent = nullptr);
    ~RVCreator();
    RV_Payload* GetRVData(void);

private slots:
    void on_CMB_Species_currentIndexChanged(int index);
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::RVCreator *ui;

    RV_Payload* m_RV;
};

#endif // RVCREATOR_H
