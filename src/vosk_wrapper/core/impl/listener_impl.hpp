#include <vosk_wrapper/core/interfaces/listener.hpp>

#include <vosk_wrapper/core/types/data_types.hpp>

namespace vosk_wrapper
{
namespace core
{

class ListenerImpl : public Listener
{
public:
    /// @brief Конструктор
    /// @param recognizer Распознаватель
    explicit ListenerImpl(RecognizerPtr recognizer, ModelPtr model);

    /// @see Listener
    std::string Recognize(const std::string &audio) override;

    /// @brief Деструктор
    ~ListenerImpl();

private:
    /// @brief Модель, хранится здесь, чтобы не уничтожиться раньше распознавателя
    ModelPtr model_;

    /// @brief Распознаватель
    RecognizerPtr recognizer_;
};

} // namespace core
} // namespace vosk_wrapper
