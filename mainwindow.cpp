#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>

static QString create_sourceFilePath;
static QString create_newFilePath;
static QString create_patchFilePath;

static QString apply_oldFilePath;
static QString apply_patchFilePath;
static QString apply_newFilePath;

void clickFileDialogButton(MainWindow *w, bool existingFile, QLabel *label,
                           QString *path) {
  QFileDialog dialog(w);
  if (existingFile)
    dialog.setFileMode(QFileDialog::ExistingFile);
  else
    dialog.setFileMode(QFileDialog::AnyFile);
  if (dialog.exec()) {
    path->clear();
    path = new QString(dialog.selectedFiles()[0]);
  }
  label->setText(*path);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // assign pointer elements (create)
  QPushButton *create_sourceFileButton;
  QPushButton *create_newFileButton;
  QPushButton *create_patchFileButton;
  QPushButton *create_initButton;
  QLabel *create_sourceFileLabel;
  QLabel *create_newFileLabel;
  QLabel *create_patchFileLabel;
  create_sourceFileButton = findChild<QPushButton *>("create_sourceFileButton");
  create_newFileButton = findChild<QPushButton *>("create_newFileButton");
  create_patchFileButton = findChild<QPushButton *>("create_patchFileButton");
  create_initButton = findChild<QPushButton *>("create_initButton");
  create_sourceFileLabel = findChild<QLabel *>("create_sourceFileLabel");
  create_newFileLabel = findChild<QLabel *>("create_newFileLabel");
  create_patchFileLabel = findChild<QLabel *>("create_patchFileLabel");

  // assign pointer elements (apply)
  QPushButton *apply_oldFileButton;
  QPushButton *apply_patchFileButton;
  QPushButton *apply_newFileButton;
  QPushButton *apply_initButton;
  QLabel *apply_oldFileLabel;
  QLabel *apply_patchFileLabel;
  QLabel *apply_newFileLabel;
  apply_oldFileButton = findChild<QPushButton *>("apply_oldFileButton");
  apply_patchFileButton = findChild<QPushButton *>("apply_patchFileButton");
  apply_newFileButton = findChild<QPushButton *>("apply_newFileButton");
  apply_initButton = findChild<QPushButton *>("apply_initButton");
  apply_oldFileLabel = findChild<QLabel *>("apply_oldFileLabel");
  apply_patchFileLabel = findChild<QLabel *>("apply_patchFileLabel");
  apply_newFileLabel = findChild<QLabel *>("apply_newFileLabel");

  // connect functions to buttons (create)
  connect(create_sourceFileButton, &QPushButton::clicked, [=] {
    clickFileDialogButton(this, true, create_sourceFileLabel,
                          &create_sourceFilePath);
  });
  connect(create_newFileButton, &QPushButton::clicked, [=] {
    clickFileDialogButton(this, true, create_newFileLabel, &create_newFilePath);
  });
  connect(create_patchFileButton, &QPushButton::clicked, [=] {
    clickFileDialogButton(this, false, create_patchFileLabel,
                          &create_patchFilePath);
  });

  // connect functions to buttons (apply)
  connect(apply_oldFileButton, &QPushButton::clicked, [=] {
    clickFileDialogButton(this, true, apply_oldFileLabel,
                          &apply_oldFilePath);
  });
  connect(apply_patchFileButton, &QPushButton::clicked, [=] {
    clickFileDialogButton(this, true, apply_patchFileLabel,
                          &apply_patchFilePath);
  });
  connect(apply_newFileButton, &QPushButton::clicked, [=] {
    clickFileDialogButton(this, false, apply_newFileLabel, &apply_newFilePath);
  });
}

MainWindow::~MainWindow() { delete ui; }
