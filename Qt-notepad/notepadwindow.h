#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>

#include <QTextStream>

//libreria editor de texto plano
#include <QPlainTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QFontDialog>
#include <QClipboard>
#include <QKeySequence>
#include <QMessageBox>

#include <QToolBar>
#include <QToolButton>

#include <QPushButton>
#include <QWidget>

class NotepadWindow : public QMainWindow
{
    Q_OBJECT

public:
    NotepadWindow(QWidget *parent = 0);
    ~NotepadWindow();

private slots:
    void alAbrir();
    void alGuardar();
    void alFuente();
    void alSalir();
    void alAyuda();
    void herr_cursiva();
    void herr_negrita();
    void herr_subrayado();
    void ali_centro();
    void ali_izquierda();
    void ali_derecha();

private:
   // QPlainTextEdit* txtEditor_;
    QTextEdit* txtEditor_;
    QMenuBar* mainMenu_;
    QMenu* mnuArchivo_;
    QAction* actArchivoAbrir_;
    QAction* actArchivoGuardar_;


    QAction* actArchivoSalir_;


    //barra herrma
    QToolBar* barraMenu_;

    QPushButton* botonnegrita_;
    QPushButton* botoncursiva_;
    QPushButton* botonsubrayado_;
    QPushButton* botonalineocentro_;
    QPushButton* botonalineoderecha_;
    QPushButton* botonalineoizquierda_;


    //QFileDialog*
    QMenu* mnuFormato_;
    QAction* actFormatoFuente_;
    QMenu* mnuEditar_;
    QAction* actEditarCopiar_;
    QAction* actEditarPegar_;
    QAction* actEditarCortar_;
    QAction* actEditarDeshacer_;
    QAction* actEditarRehacer_;

    QMenu* mnuAyuda_;
    QAction* actAyudaAcercade_;



    QClipboard * portapapeles_;

};

#endif // NOTEPADWINDOW_H
