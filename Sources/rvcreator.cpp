#include "Headers/rvcreator.h"
#include "ui_rvcreator.h"
#include "Headers/values.h"
#include "Headers/checksum.h"
#include <QtDebug>
#include <QMessageBox>

RVCreator::RVCreator(RV_Payload* RV, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RVCreator)
{
    ui->setupUi(this);
    m_RV = RV;

    // Populate species
    for (const Species &specie : g_species)
        ui->CMB_Species->addItem(specie.Name);

    int SpeciesID = -1;
    int VillagerIndex = -1;

    for (int i = 0; i < 430; i++) { //Get where in list Vilager ID is
        if (g_villagers[i].VID == m_RV->VillagerID) {
               VillagerIndex = i;
               break;
        }
    }

    for (int i = 0; i < 36; i++) { //Get where in list Species is
        if (VillagerIndex >= static_cast<int>(g_species[i].Start) && VillagerIndex <= static_cast<int>(g_species[i].End)) {
            SpeciesID = i;
            break;
        }
    }

    if (SpeciesID >= 0) {
        ui->CMB_Species->setCurrentIndex(SpeciesID);
        const Species &selected = g_species[SpeciesID]; //Populate with villagers corresponding to species

        ui->CMB_VillagerName->clear();
        for (quint32 i = selected.Start; i <= selected.End; i++)
            ui->CMB_VillagerName->addItem(g_villagers[i].Name);

        VillagerIndex -= selected.Start;
        if (VillagerIndex >= 0) {
            ui->CMB_VillagerName->setCurrentIndex(VillagerIndex);
        }
    }
}

RVCreator::~RVCreator()
{
    delete ui;
}

void RVCreator::on_CMB_Species_currentIndexChanged(int index)
{
    if (index > 36 || index < 0) return;
    const Species &selected = g_species[index]; //Populate with villagers corresponding to user choice

    ui->CMB_VillagerName->clear();
    for (quint32 i = selected.Start; i <= selected.End; i++)
        ui->CMB_VillagerName->addItem(g_villagers[i].Name);

}

void RVCreator::on_buttonBox_clicked(QAbstractButton *button)
{
    if(reinterpret_cast<QPushButton *>(button) == ui->buttonBox->button(QDialogButtonBox::Close)) {
        qDebug() << "Closed Rv Window";
        this->close();
    }

    else if (reinterpret_cast<QPushButton *>(button) == ui->buttonBox->button(QDialogButtonBox::Save)) {
        qDebug() << "Saved RV";
        int SpeciesIndex = ui->CMB_Species->currentIndex();
        int VillagerIndex = ui->CMB_VillagerName->currentIndex();
        const Species &selected = g_species[SpeciesIndex];
        VillagerIndex += selected.Start;

        if (VillagerIndex <= 430 && VillagerIndex >= 0) {
            m_RV->VillagerID = g_villagers[VillagerIndex].VID;
            QMessageBox::information(nullptr, "Saved!", "RV Settings have been saved.");
        }

        else {
            QString error = "An error has occured saving RV Settings\nVillagerIndex: " + QString::number(VillagerIndex);
            QMessageBox::warning(nullptr, "Error!", error);
        }
    }
}

RV_Payload* RVCreator::GetRVData(void) {
    m_RV->Magic = 0x1;
    m_RV->Padding = 0x0;
    m_RV->Checksum = CalculateCRC32Reflected(reinterpret_cast<u8*>(m_RV)+4, RV_PAYLOAD_SIZE-4);

    return m_RV;
}
