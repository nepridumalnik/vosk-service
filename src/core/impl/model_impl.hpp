#include <interfaces/model.hpp>

namespace vosk_server
{
namespace core
{

class ModelImpl : public Model
{
public:
    std::unique_ptr<Listener> GetRecognizer();
};

} // namespace core
} // namespace vosk_server
