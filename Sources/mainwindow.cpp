#include "Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "Headers/rvcreator.h"
#include "Headers/presentcreator.h"
#include "Headers/aboutwindow.h"
#include "Headers/boss.h"
#include "Headers/file.h"
#include "Headers/utils.hpp"
#include <QtDebug>

static RV_Payload* g_RVData;
static Present_Payload* g_PresentData;
static const u32 TIDLowers[8] = {0x086200, 0x086300, 0x086400, 0x086500,  //Orig Game
                                 0x198D00, 0x198E00, 0x198F00, 0x199000}; //WA Preinstalled Game

static const QString GameType[8] = {"Orig_JPN", "Orig_USA", "Orig_EUR", "Orig_KOR",  //Orig Game
                                    "WA_JPN", "WA_USA", "WA_EUR", "WA_KOR"}; //WA Preinstalled Game

static const QString FilePaths[2] = {"/Boss_Decrypted.dat", "/Boss_Encrypted.dat"};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_exedir = QCoreApplication::applicationDirPath();
    m_outdir = m_exedir + "/SpotPass/";

    g_RVData = new RV_Payload;
    g_PresentData = new Present_Payload;

    /* Setup Default RV Data */
    g_RVData->Checksum = 0x95ccece9; //Valid checksum for Alfonso
    g_RVData->Magic = 0x1;
    g_RVData->Padding = 0x0;
    g_RVData->VillagerID = 0x005d; //Alfonso; First in Villager list

    /* Setup Default Present Data */
    g_PresentData->Checksum = 0x3447dcbe; //Valid checksum for Present
    g_PresentData->Magic = 0x2;
    g_PresentData->Padding = 0x0;
    g_PresentData->PresentID = 0x100;
    g_PresentData->ItemPreWA = 0x2112; //99k Bells
}

MainWindow::~MainWindow()
{
    delete g_RVData;
    delete g_PresentData;
    delete ui;
}

void MainWindow::on_actionOpen_Boot9_triggered()
{
    KeyResult res = Utils::SetupKey();

    switch (res) {
        case KeyResult::NoError:
            ui->statusBar->showMessage("Opened Boot9.bin; BOSS AES Key Has Been Loaded Successfully!", 15000);
            ui->CMB_Region->setEnabled(true);
            ui->BTN_RV->setEnabled(true);
            ui->BTN_Present->setEnabled(true);
            ui->BTN_RV_Make->setEnabled(true);
            ui->BTN_Present_Make->setEnabled(true);
            ui->actionOpen_Boot9->setEnabled(false);
            break;

        case KeyResult::FileNoExist:
            ui->statusBar->showMessage("Couldn't open Boot9.bin; Does It Exist? Is It In The Correct Location?", 15000);
            break;

        case KeyResult::ByteArrayBadSize:
            ui->statusBar->showMessage("Couldn't load BOSS AES Key; Array Size Isn't 16!", 15000);
            break;

        case KeyResult::HashMismatch:
            ui->statusBar->showMessage("BOSS AES Key Not Correct; Hash Mismatch!", 15000);
            break;
    }

    ui->actionOpen_Boot9->setEnabled(false);
}

void MainWindow::on_BTN_RV_clicked()
{
    RVCreator rvWindow(g_RVData);
    rvWindow.exec();
    g_RVData = rvWindow.GetRVData();
}

void MainWindow::on_BTN_Present_clicked()
{
    PresentCreator presWindow(g_PresentData);
    presWindow.exec();
    g_PresentData = presWindow.GetPresentData();
}

void MainWindow::on_BTN_Present_Make_clicked()
{
    int index = ui->CMB_Region->currentIndex();
    m_outdir = m_exedir + "/SpotPass/" + GameType[index] + "/Present";
    if (!Utils::SetupOutDir(m_outdir)) {
        QMessageBox::warning(nullptr, "Couldn't make Present directory", "Couldn't make the following path:\n" + m_outdir);
        return;
    }
    BOSS *PresentBoss = new BOSS;
    PresentBoss->SetTitleIDLower(TIDLowers[index]);
    PresentBoss->AddPayload(reinterpret_cast<u8*>(g_PresentData), sizeof(Present_Payload), 0x00010002);
    PresentBoss->DumpAsFile(m_outdir + FilePaths[0]);
    PresentBoss->Crypt();
    PresentBoss->DumpAsFile(m_outdir + FilePaths[1]);
    delete PresentBoss;
}

void MainWindow::on_BTN_RV_Make_clicked()
{
    int index = ui->CMB_Region->currentIndex();
    m_outdir = m_exedir + "/SpotPass/" + GameType[index] + "/RV";
    if (!Utils::SetupOutDir(m_outdir)) {
        QMessageBox::warning(nullptr, "Couldn't make RV directory", "Couldn't make the following path:\n" + m_outdir);
        return;
    }

    BOSS *RVBoss = new BOSS;
    RVBoss->SetTitleIDLower(TIDLowers[index]);
    RVBoss->AddPayload(reinterpret_cast<u8*>(g_RVData), sizeof(RV_Payload), 0x00010010);
    RVBoss->DumpAsFile(m_outdir + FilePaths[0]);
    RVBoss->Crypt();
    RVBoss->DumpAsFile(m_outdir + FilePaths[1]);
    delete RVBoss;
}

void MainWindow::on_actionAbout_triggered()
{
    qDebug() << "About Menu Pressed";
    AboutWindow aboutWindow;
    aboutWindow.setStyleSheet("background-color: white;");
    aboutWindow.exec();
}

void MainWindow::on_BTN_About_clicked()
{
    qDebug() << "About Button Pressed";
    AboutWindow aboutWindow;
    aboutWindow.setStyleSheet("background-color: white;");
    aboutWindow.exec();
}
