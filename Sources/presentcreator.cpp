#include "Headers/presentcreator.h"
#include "ui_presentcreator.h"
#include "Headers/values.h"
#include "Headers/checksum.h"
#include <QtCore>
#include <QPushButton>
#include <QMessageBox>

PresentCreator::PresentCreator(Present_Payload* Present, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PresentCreator)
{
    ui->setupUi(this);

    m_Present = Present;
    ui->LE_ItemID->setText(QString::number(m_Present->ItemPreWA, 16));
    ui->LE_PresentID->setText(QString::number(m_Present->PresentID, 16));
    ui->BB_PageSearchControl->button(QDialogButtonBox::Retry)->setText("<- Back"); //Back
    ui->BB_PageSearchControl->button(QDialogButtonBox::Ignore)->setText("Forward ->"); //Forward
    ui->textBrowser->setStyleSheet("selection-background-color: yellow; selection-color: black;");

    QFile list(QCoreApplication::applicationDirPath() + "/Resources/Items.txt");
    list.open(QFile::ReadOnly | QFile::Text);

    if (list.isOpen()) {
        QTextStream ReadFile(&list);
        ui->textBrowser->setText(ReadFile.readAll());
        list.close();
    }

    else ui->textBrowser->setText("Couldn't open Item List!\n\nExpected FilePath:\n\n" + QCoreApplication::applicationDirPath() + "/Resources/Items.txt");
}

PresentCreator::~PresentCreator()
{
    delete ui;
}

void PresentCreator::PresentCreator::on_LE_PresentID_textEdited(const QString &arg1)
{
    if (arg1 == "FFFF") { //ID can't be 0xFFFF
        ui->LE_PresentID->setText("FFFE");
    }
}

void PresentCreator::on_buttonBox_clicked(QAbstractButton *button) {

    if(reinterpret_cast<QPushButton *>(button) == ui->buttonBox->button(QDialogButtonBox::Close)) {
        qDebug() << "Closed Present Window";
        this->close();
    }

    else if (reinterpret_cast<QPushButton *>(button) == ui->buttonBox->button(QDialogButtonBox::Save)) {
        qDebug() << "Saved Present";
        m_Present->ItemPreWA = (ui->LE_ItemID->text().toUInt(nullptr, 16))&0x0000FFFF;
        m_Present->PresentID = ui->LE_PresentID->text().toUShort(nullptr, 16);
        QMessageBox::information(nullptr, "Saved!", "Present Settings have been saved.");
    }
}

Present_Payload* PresentCreator::GetPresentData(void) {
    m_Present->Magic = 0x2;
    m_Present->Padding = 0x0;
    m_Present->Checksum = CalculateCRC32Reflected(reinterpret_cast<u8*>(m_Present)+4, PRESENT_PAYLOAD_SIZE-4);

    return m_Present;
}

void PresentCreator::on_LE_ItemID_editingFinished()
{
    u16 id = (ui->LE_ItemID->text().toUInt(nullptr, 16))&0xffff;
    qDebug() << "Item ID: " << QString::number(id, 16);
    if (id < 0x2000) {
        ui->LE_ItemID->setText("2000");
    }

    if (id > 0x31AC) {
        ui->LE_ItemID->setText("31AC");
    }
}

void PresentCreator::on_LE_PageSearch_textChanged(const QString &arg1)
{
    ui->textBrowser->find(arg1);
    m_searchtext = arg1;
}


void PresentCreator::on_BB_PageSearchControl_clicked(QAbstractButton *button)
{
    if (m_searchtext.isEmpty()) return;

    if(reinterpret_cast<QPushButton *>(button) == ui->BB_PageSearchControl->button(QDialogButtonBox::Retry)) { //Back
        ui->textBrowser->find(m_searchtext, QTextDocument::FindBackward);
    }

    if(reinterpret_cast<QPushButton *>(button) == ui->BB_PageSearchControl->button(QDialogButtonBox::Ignore)) { //Forward
        ui->textBrowser->find(m_searchtext);
    }
}
