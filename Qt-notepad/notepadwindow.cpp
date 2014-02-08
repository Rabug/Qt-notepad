#include "notepadwindow.h"

NotepadWindow::NotepadWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Establecemos el tamaño inicial de la ventana
    this->setGeometry(30, 30, 800, 600);

    //Establecemos el título de la ventana
    this->setWindowTitle(tr("Super editor de texto"));

    //Inicializamos los menús
    mainMenu_ = new QMenuBar(this);

    mnuArchivo_ = new QMenu(tr("&Archivo"), this);
    mainMenu_->addMenu(mnuArchivo_);

    actArchivoAbrir_ = new QAction(tr("&Abrir"), this);
    actArchivoAbrir_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    mnuArchivo_->addAction(actArchivoAbrir_);

    actArchivoGuardar_ = new QAction(tr("&Guardar"), this);
    actArchivoGuardar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    mnuArchivo_->addAction(actArchivoGuardar_);

    actArchivoSalir_ = new QAction(tr("&Salir"), this);
    actArchivoSalir_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_E));
    mnuArchivo_->addAction(actArchivoSalir_);


    //añade menu editar
    mnuEditar_ = new QMenu(tr("&Editar"), this);
    mainMenu_->addMenu(mnuEditar_);

    actEditarCopiar_ = new QAction(tr("&Copiar"), this);
    actEditarCopiar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    mnuEditar_->addAction(actEditarCopiar_);

    actEditarCortar_ = new QAction(tr("Co&rtar"), this);
    actEditarCortar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_R));
    mnuEditar_->addAction(actEditarCortar_);

    actEditarPegar_ = new QAction(tr("&Pegar"), this);
    actEditarPegar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    mnuEditar_->addAction(actEditarPegar_);

    actEditarDeshacer_ = new QAction(tr("&Deshacer"), this);
    actEditarDeshacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_D));
    mnuEditar_->addAction(actEditarDeshacer_);


    actEditarRehacer_ = new QAction(tr("&Rehacer"), this);
    actEditarRehacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_R));
    mnuEditar_->addAction(actEditarRehacer_);


    mnuFormato_ = new QMenu(tr("&Formato"), this);
    mainMenu_->addMenu(mnuFormato_);

    actFormatoFuente_ = new QAction(tr("&Fuente"), this);
    mnuFormato_->addAction(actFormatoFuente_);

    //menu Ayuda
    mnuAyuda_ = new QMenu(tr("&Ayuda"), this);
    mainMenu_->addMenu(mnuAyuda_);

    actAyudaAcercade_ = new QAction(tr("&Acerca de"), this);
    actAyudaAcercade_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
    mnuAyuda_->addAction(actAyudaAcercade_);


    //Agregamos la barra de menú a la ventana
    this->setMenuBar(mainMenu_);

    //Inicializamos el editor de texto
    txtEditor_ = new QPlainTextEdit(this);

    //Conectamos las acciones de los menús con nuestros slots
    connect(actArchivoAbrir_, SIGNAL(triggered()), this, SLOT(alAbrir()));
    connect(actArchivoGuardar_, SIGNAL(triggered()), this, SLOT(alGuardar()));
   //salir
    connect(actArchivoSalir_, SIGNAL(triggered()), this, SLOT(alSalir()));


    connect(actEditarCopiar_, SIGNAL(triggered()), txtEditor_, SLOT(copy()));
    connect(actEditarPegar_, SIGNAL(triggered()), txtEditor_, SLOT(paste()));
    connect(actEditarCortar_, SIGNAL(triggered()), txtEditor_, SLOT(cut()));

    //metodos de la clase txtEditor y ya estan creados
    connect(actEditarDeshacer_, SIGNAL(triggered()), txtEditor_, SLOT(undo()));
    connect(actEditarRehacer_, SIGNAL(triggered()), txtEditor_, SLOT(redo()));


    connect(actFormatoFuente_, SIGNAL(triggered()), this, SLOT(alFuente()));

    QString msg = "Vete a google muchacho!!";
    connect(actAyudaAcercade_,SIGNAL(triggered()), txtEditor_, SLOT(show()));




    //Agregamos el editor de texto a la ventana
    this->setCentralWidget(txtEditor_);
}

NotepadWindow::~NotepadWindow()
{
    //Liberamos los recursos
    mainMenu_->deleteLater();
    actArchivoAbrir_->deleteLater();
    actArchivoGuardar_->deleteLater();
    actArchivoSalir_->deleteLater();
    mnuArchivo_->deleteLater();
    actEditarCopiar_->deleteLater();
    actEditarPegar_->deleteLater();
    actEditarCortar_->deleteLater();
    actEditarDeshacer_->deleteLater();
    mnuEditar_->deleteLater();
    actFormatoFuente_->deleteLater();
    mnuFormato_->deleteLater();
    mnuAyuda_->deleteLater();
    actAyudaAcercade_->deleteLater();
    txtEditor_->deleteLater();

}

void NotepadWindow::alAbrir()
{
    //Mostramos un dialogo de apertura de ficheros y almacenamos la selección (ruta) en una variable
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getOpenFileName(this,
                                                 tr("Abrir archivo de texto plano"),
                                                 "",
                                                 tr("Archivos de texto plano (*.txt)"));
    if (nombreArchivo != "") {
        //Intentamos abrir el archivo
        QFile archivo;
        archivo.setFileName(nombreArchivo);
        if (archivo.open(QFile::ReadOnly)) {
            //Si se pudo abrir el archivo, lo leemos y colocamos su contenido en nuestro editor
            txtEditor_->setPlainText(archivo.readAll());
            //Se cierra el fichero
            archivo.close();
        }
    }
}

void NotepadWindow::alGuardar()
{
    //Mostramos un dialogo de guardado de ficheros y almacenamos la selección (ruta) en una variable
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getSaveFileName(this,
                                                 tr("Guardar archivo de texto plano"),
                                                 "",
                                                 tr("Archivos de texto plano (*.txt)"));
    if (nombreArchivo != "") {
        //Intentamos abrir el archivo
        QFile archivo;
        archivo.setFileName(nombreArchivo + ".txt");
        if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
            //Si se pudo abrir el archivo, escribimos el contenido del editor
            archivo.write(txtEditor_->toPlainText().toUtf8());
            //Se cierra el fichero
            archivo.close();
        }
    }
}

void NotepadWindow::alFuente()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, txtEditor_->font(), this);
    if (ok) {
        // Si el usuario hizo click en OK, se establece la fuente seleccionada
        txtEditor_->setFont(font);
    }
}

void NotepadWindow::alSalir()
{

    QMessageBox msg;
    msg.addButton("SI", QMessageBox::YesRole);
    msg.addButton("NO", QMessageBox::NoRole);

    if (!msg.exec())
        close();


}

//void NotepadWindow::alCortar()
//{

//}
