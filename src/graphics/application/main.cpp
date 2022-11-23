#include <graphics/gui/application.hpp>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app{argc, argv};

    graphics::gui::Application window;
    window.show();

    return app.exec();
}
