#pragma once

#include <model.hpp>

#include <memory>
#include <string>

struct Core
{
    /// @brief Получить языковую модель
    /// @param [in] language Язык модели
    /// @return Модель
    virtual std::shared_ptr<Model> GetModel(const std::string &language) = 0;

    /// @brief Добавить языковую модель
    /// @param [in] path Путь до файлов обученной модели
    /// @param [in] language Язык модели
    virtual void AddModel(const std::string &path, const std::string &language) = 0;
};
