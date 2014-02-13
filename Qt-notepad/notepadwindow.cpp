#include "notepadwindow.h"


NotepadWindow::NotepadWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Establecemos el tamaño inicial de la ventana
    this->setGeometry(30, 30, 800, 600);

    //Establecemos el título de la ventana
    this->setWindowTitle(tr("El editor de texto de Rabú"));

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

    //menu formato
    mnuFormato_ = new QMenu(tr("&Formato"), this);
    mainMenu_->addMenu(mnuFormato_);

    actFormatoFuente_ = new QAction(tr("&Fuente"), this);
    mnuFormato_->addAction(actFormatoFuente_);

    //menu Ayuda
    mnuAyuda_ = new QMenu(tr("A&yuda"), this);
    mainMenu_->addMenu(mnuAyuda_);

   
    actAyudaAcercade_ = new QAction(tr("Ace&rca de"), this);
    actAyudaAcercade_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
    mnuAyuda_->addAction(actAyudaAcercade_);


    //preparando barra de herramientas
    barraMenu_ = addToolBar(tr("Barra de Herramientas"));
    
    botoncursiva_ = new QPushButton(QIcon("../images_qt/cursiva.png"),"");
    botonnegrita_ = new QPushButton(QIcon("../images_qt/negrita.jpg"),"");
    botonsubrayado_ = new QPushButton(QIcon("../images_qt/subrayado.jpg"),"");
    botonalineocentro_ = new QPushButton(QIcon("../images_qt/alig_centro.jpg"),"");
    botonalineoderecha_ = new QPushButton(QIcon("../images_qt/alig_derecha.png"),"");
    botonalineoizquierda_ = new QPushButton(QIcon("../images_qt/alig_izquierda.jpg"),"");

     //metemos el espacio enorme en blanco en blanco
    QWidget *spacerWidget = new QWidget(this);
    spacerWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    spacerWidget->setVisible(true);
    barraMenu_->addWidget(spacerWidget);

    barraMenu_->addWidget(botonalineocentro_);
    barraMenu_->addWidget(botonalineoizquierda_);
    barraMenu_->addWidget(botonalineoderecha_);
    barraMenu_->addWidget(botoncursiva_);
    barraMenu_->addWidget(botonnegrita_);
    barraMenu_->addWidget(botonsubrayado_);


    //conexiones de los tres botones

    connect(botoncursiva_,SIGNAL(released()),this,SLOT(herr_cursiva()));
    connect(botonnegrita_,SIGNAL(released()),this,SLOT(herr_negrita()));
    connect(botonsubrayado_,SIGNAL(released()),this,SLOT(herr_subrayado()));
    connect(botonalineocentro_,SIGNAL(released()),this,SLOT(ali_centro()));
    connect(botonalineoderecha_,SIGNAL(released()),this,SLOT(ali_derecha()));
    connect(botonalineoizquierda_,SIGNAL(released()),this,SLOT(ali_izquierda()));

    this->addToolBar(barraMenu_);




    //Agregamos la barra de menú a la ventana
    this->setMenuBar(mainMenu_);

    //Inicializamos el editor de texto
    //txtEditor_ = new QPlainTextEdit(this);
    txtEditor_ = new QTextEdit(this);

    //Conectamos las acciones de los menús con nuestros slots
    connect(actArchivoAbrir_, SIGNAL(triggered()), this, SLOT(alAbrir()));
    connect(actArchivoGuardar_, SIGNAL(triggered()), this, SLOT(alGuardar()));
    //salir
    connect(actArchivoSalir_, SIGNAL(triggered()), this, SLOT(alSalir()));

    //editar
    connect(actEditarCopiar_, SIGNAL(triggered()), txtEditor_, SLOT(copy()));
    connect(actEditarPegar_, SIGNAL(triggered()), txtEditor_, SLOT(paste()));
    connect(actEditarCortar_, SIGNAL(triggered()), txtEditor_, SLOT(cut()));
    //metodos de la clase txtEditor y ya estan creados
    connect(actEditarDeshacer_, SIGNAL(triggered()), txtEditor_, SLOT(undo()));
    connect(actEditarRehacer_, SIGNAL(triggered()), txtEditor_, SLOT(redo()));


    connect(actFormatoFuente_, SIGNAL(triggered()), this, SLOT(alFuente()));

    connect(actAyudaAcercade_,SIGNAL(triggered()), this, SLOT(alAyuda()));


    //txtEditor_->setHtml(this);


    //Agregamos el editor de texto a la ventana
    this->setCentralWidget(txtEditor_);
}

NotepadWindow::~NotepadWindow()
{
    //Liberamos los recursos
    mainMenu_->deleteLater();
    //menu archivo
    actArchivoAbrir_->deleteLater();
    actArchivoGuardar_->deleteLater();
    actArchivoSalir_->deleteLater();
    mnuArchivo_->deleteLater();
    //menu editar
    actEditarCopiar_->deleteLater();
    actEditarPegar_->deleteLater();
    actEditarCortar_->deleteLater();
    actEditarDeshacer_->deleteLater();
    mnuEditar_->deleteLater();

    //menu formato
    actFormatoFuente_->deleteLater();
    mnuFormato_->deleteLater();

    //menu ayuda
    actAyudaAcercade_->deleteLater();
    mnuAyuda_->deleteLater();

    txtEditor_->deleteLater();

}

void NotepadWindow::alAbrir()
{
    //Mostramos un dialogo de apertura de ficheros y almacenamos la selección (ruta) en una variable
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getOpenFileName(this,
                                                 tr("Abrir archivo de texto enriquecido"),
                                                 "",
                                                 //tr("Archivos de texto plano (*.txt)"),
                                                 tr("Archivo de texto enriquecido (*.html *.txt *.rtf)")
                                                 );
    if (nombreArchivo != "") {
        //Intentamos abrir el archivo
        QFile archivo;
        archivo.setFileName(nombreArchivo);
        if (archivo.open(QFile::ReadOnly)) {
            //Si se pudo abrir el archivo, lo leemos y colocamos su contenido en nuestro editor
            //txtEditor_->setPlainText(archivo.readAll());
            txtEditor_->setHtml(archivo.readAll());
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
                                                 tr("Guardar archivo de texto enriquecido"),
                                                 "",
                                                 tr("Archivos de texto enriquecido (*.rtf *.html *.txt)"));
    if (nombreArchivo != "") {
        //Intentamos abrir el archivo
        QFile archivo;
        archivo.setFileName(nombreArchivo + ".txt");
        //archivo.setFileName(nombreArchivo + ".rtf");
        //archivo.setFileName(nombreArchivo + ".html");
        if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
            //Si se pudo abrir el archivo, escribimos el contenido del editor
            //archivo.write(txtEditor_->toPlainText().toUtf8());
            archivo.write(txtEditor_->toHtml().toUtf8());
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

        //yo sufro un retraso muy profundo, entiendo que esto consigue arreglar que
        //solo el cambio de fuente afecte a la parte de texto seleccionada usando un Qtextcursor
        //al que luego le indico que cambie su formato utilizando un QTextCharFormat
        QTextCursor cursor = txtEditor_->textCursor();
        QTextCharFormat formato = cursor.charFormat();
        formato.setFont(font);
        cursor.setCharFormat(formato);

        // Si el usuario hizo click en OK, se establece la fuente seleccionada
      //  txtEditor_->setFont(font);
    }

}



void NotepadWindow::alSalir()
{

    QMessageBox msg;
    msg.move(200,200);

    msg.setText("DESEA SALIR REALMENTE?");
    msg.addButton("SI", QMessageBox::YesRole);
    msg.addButton("NO", QMessageBox::NoRole);

    if (!msg.exec())
        close();
}

void NotepadWindow::alAyuda()
{
    //QTextStream cout(stdout,QIODevice::WriteOnly);
    //cout << "MIERDA";

    QMessageBox ms;
    ms.setText("Vete a Google Muchacho!!");
    ms.addButton("OK", QMessageBox::YesRole);
    ms.exec();

}

void NotepadWindow::herr_negrita()
{


    if (txtEditor_->fontWeight())
        txtEditor_->setFontWeight(QFont::Bold);
    else
        txtEditor_->setFontWeight(QFont::Bold);
}


void NotepadWindow::herr_cursiva()
{
    if (txtEditor_->fontItalic())
        txtEditor_->setFontItalic(false);
    else
        txtEditor_->setFontItalic(true);
}

void NotepadWindow::herr_subrayado()
{
    if (txtEditor_->fontUnderline())
        txtEditor_->setFontUnderline(false);
    else
        txtEditor_->setFontUnderline(true);
}


void NotepadWindow::ali_centro()
{


   // if (txtEditor_->alignment(Qt::AlignCenter))
     //   txtEditor_->setAlignment(Qt::AlignAbsolute);
    //else
        txtEditor_->setAlignment(Qt::AlignCenter);
}

void NotepadWindow::ali_derecha()
{


    //if (txtEditor_->alignment(Qt::AlignCenter))
     //   txtEditor_->setAlignment(Qt::AlignAbsolute);
    //else
        txtEditor_->setAlignment(Qt::AlignRight);
}

void NotepadWindow::ali_izquierda()
{


    //if (txtEditor_->alignment(Qt::AlignCenter))
    //    txtEditor_->setAlignment(Qt::AlignAbsolute);
    //else
        txtEditor_->setAlignment(Qt::AlignLeft);
}
