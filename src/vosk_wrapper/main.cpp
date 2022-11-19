#include <vosk_wrapper/core/impl/core_impl.hpp>

#include <fstream>

static constexpr char ModelPath[] = "../../../vosk-api/models/vosk-model-ru-0.22";
static constexpr char ModelName[] = "russian";
static constexpr char Voice[] = "../../../vosk-api/resources/novy_god.wav";

int main(int argc, char const *argv[])
{
    auto core = std::make_unique<vosk_wrapper::core::CoreImpl>();
    core->AddModel(ModelPath, ModelName);

    std::string buffer;
    std::string result;

    // Прочитать файл
    {
        std::ifstream in{Voice, std::ios::binary};
        in.seekg(0, std::ios::end);
        buffer.resize(in.tellg());
        in.seekg(44, std::ios::beg);
        in.read(&buffer[0], buffer.size());
        in.close();
    }

    auto listener = core->GetListener(ModelName);
    result = listener->Recognize(buffer);

    // Записать файл
    {
        std::ofstream out{"test_output.txt"};
        out << result;
    }

    core->RemoveModel(ModelName);

    return 0;
}
