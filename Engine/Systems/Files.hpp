#pragma once
#ifndef LUKAN_FILES
#define LUKAN_FILES

#include "../Engine.hpp"

namespace Lk {
    class File {
    public:
        File(const vstring& filename);

        void Load(const vstring& filename);
        void Save(const vstring& filename, const vstring& data);

    private:
        std::string m_line;
        std::string m_data;
    };
};

#endif