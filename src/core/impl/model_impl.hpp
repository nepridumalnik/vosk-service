#include <interfaces/model.hpp>

#include <types/data_types.hpp>

namespace vosk_server
{
namespace core
{

class ModelImpl : public Model
{
public:
    /// @brief Конструктор
    /// @param path Путь до модели
    ModelImpl(const std::string &path);

    /// @see Model
    std::unique_ptr<Listener> GetRecognizer();

    /// @brief Деструктор
    ~ModelImpl() = default;

private:
    /// @brief Модель
    ModelPtr model_;
};

} // namespace core
} // namespace vosk_server
