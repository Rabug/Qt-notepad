#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>

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


private:
    QPlainTextEdit* txtEditor_;
    QMenuBar* mainMenu_;
    QMenu* mnuArchivo_;
    QAction* actArchivoAbrir_;
    QAction* actArchivoGuardar_;


    QAction* actArchivoSalir_;


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
