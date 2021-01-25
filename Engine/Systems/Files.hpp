#pragma once
#ifndef LUKAN_FILES
#define LUKAN_FILES

#include "../Engine.hpp"

namespace Lk {
    class File {
    public:
        File(const std::string& filename);

        void Load(const std::string& filename);
        void Save(const std::string& filename, const std::string& data);

        std::string GetData();

    private:
        std::string m_line;
        std::string m_data;
    };
};

#endif