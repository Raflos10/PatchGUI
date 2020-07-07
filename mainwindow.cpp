#include "mainwindow.h"
#include "include/bsdifflib/bsdifflib.h"
#include "include/bsdifflib/bspatchlib.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QMessageBox>

static QString *create_sourceFilePath = new QString();
static QString *create_newFilePath = new QString();
static QString *create_patchFilePath = new QString();

static QString *apply_oldFilePath = new QString();
static QString *apply_patchFilePath = new QString();
static QString *apply_newFilePath = new QString();

static Page_Elements *createElements = new Page_Elements();
static Page_Elements *applyElements = new Page_Elements();

void clickFileDialogButton(MainWindow *w, bool existingFile, QLabel *label,
                           QString *path) {
  QFileDialog dialog(w);
  if (existingFile)
    dialog.setFileMode(QFileDialog::ExistingFile);
  else
    dialog.setFileMode(QFileDialog::AnyFile);
  if (dialog.exec())
    *path = dialog.selectedFiles()[0];

  label->setText(*path);
}

void initCreatePatch(QString *oldPath, QString *newPath, QString *patchPath) {
  QMessageBox res;
  char *errs =
      bsdiff(oldPath->toUtf8(), newPath->toUtf8(), patchPath->toUtf8());
  if (errs)
    res.setText(errs);
  else
    res.setText(patchPath->toUtf8() + " created successfully!");
  res.exec();
}

void initApplyPatch(QString *oldPath, QString *newPath, QString *patchPath) {
  QMessageBox res;
  char *errs =
      bspatch(oldPath->toUtf8(), newPath->toUtf8(), patchPath->toUtf8());
  if (errs)
    res.setText(errs);
  else
    res.setText(newPath->toUtf8() + " created successfully!");
  res.exec();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // set about page label
  QLabel *aboutLabel = this->findChild<QLabel *>("aboutLabel");
  aboutLabel->setOpenExternalLinks(true);
  aboutLabel->setText(
      "<a href=\"https://github.com/Raflos10/PatchGUI \">PatchGUI Utility</a>");

  // assign pointer elements (create)
  createElements->oldFileButton =
      findChild<QPushButton *>("create_sourceFileButton");
  createElements->newFileButton =
      findChild<QPushButton *>("create_newFileButton");
  createElements->patchFileButton =
      findChild<QPushButton *>("create_patchFileButton");
  createElements->initButton = findChild<QPushButton *>("create_initButton");
  createElements->oldFileLabel = findChild<QLabel *>("create_sourceFileLabel");
  createElements->newFileLabel = findChild<QLabel *>("create_newFileLabel");
  createElements->patchFileLabel = findChild<QLabel *>("create_patchFileLabel");

  // assign pointer elements (apply)
  applyElements->oldFileButton =
      findChild<QPushButton *>("apply_oldFileButton");
  applyElements->patchFileButton =
      findChild<QPushButton *>("apply_patchFileButton");
  applyElements->newFileButton =
      findChild<QPushButton *>("apply_newFileButton");
  applyElements->initButton = findChild<QPushButton *>("apply_initButton");
  applyElements->oldFileLabel = findChild<QLabel *>("apply_oldFileLabel");
  applyElements->patchFileLabel = findChild<QLabel *>("apply_patchFileLabel");
  applyElements->newFileLabel = findChild<QLabel *>("apply_newFileLabel");

  // connect functions to buttons (create)
  connect(createElements->oldFileButton, &QPushButton::clicked, [&] {
    clickFileDialogButton(this, true, createElements->oldFileLabel,
                          create_sourceFilePath);
  });
  connect(createElements->newFileButton, &QPushButton::clicked, [&] {
    clickFileDialogButton(this, true, createElements->newFileLabel,
                          create_newFilePath);
  });
  connect(createElements->patchFileButton, &QPushButton::clicked, [&] {
    clickFileDialogButton(this, false, createElements->patchFileLabel,
                          create_patchFilePath);
  });
  connect(createElements->initButton, &QPushButton::clicked, [&] {
    initCreatePatch(create_sourceFilePath, create_newFilePath,
                    create_patchFilePath);
  });

  // connect functions to buttons (apply)
  connect(applyElements->oldFileButton, &QPushButton::clicked, [&] {
    clickFileDialogButton(this, true, applyElements->oldFileLabel,
                          apply_oldFilePath);
  });
  connect(applyElements->patchFileButton, &QPushButton::clicked, [&] {
    clickFileDialogButton(this, true, applyElements->patchFileLabel,
                          apply_patchFilePath);
  });
  connect(applyElements->newFileButton, &QPushButton::clicked, [&] {
    clickFileDialogButton(this, false, applyElements->newFileLabel,
                          apply_newFilePath);
  });
  connect(applyElements->initButton, &QPushButton::clicked, [&] {
    initApplyPatch(apply_oldFilePath, apply_newFilePath, apply_patchFilePath);
  });
}

MainWindow::~MainWindow() {
  delete ui;
  delete create_newFilePath;
  delete create_sourceFilePath;
  delete create_patchFilePath;
  delete apply_newFilePath;
  delete apply_oldFilePath;
  delete apply_patchFilePath;
  delete createElements;
  delete applyElements;
}
