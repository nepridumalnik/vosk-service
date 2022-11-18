#include <interfaces/model.hpp>

#include <types/data_types.hpp>

namespace vosk_server
{
namespace core
{

class ModelImpl : public Model
{
public:
    ModelImpl(const std::string &path);

    std::unique_ptr<Listener> GetRecognizer();

    ~ModelImpl() = default;

private:
    ModelPtr model_;
};

} // namespace core
} // namespace vosk_server
