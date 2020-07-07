#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

typedef struct Page_Elements {
  QPushButton *oldFileButton;
  QPushButton *patchFileButton;
  QPushButton *newFileButton;
  QPushButton *initButton;
  QLabel *oldFileLabel;
  QLabel *patchFileLabel;
  QLabel *newFileLabel;
} Page_Elements;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
