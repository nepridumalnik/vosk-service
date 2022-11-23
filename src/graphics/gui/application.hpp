#pragma once

#include <types/macro.hpp>

#include <QWidget>

namespace graphics
{
namespace gui
{

class Application : public QWidget
{
    Q_OBJECT

public:
    EXPORT explicit Application(QWidget *parent = nullptr);
};

} // namespace gui
} // namespace graphics
