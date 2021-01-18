#include "Files.hpp"

namespace Lk {
    File::File(const vstring& filename) {
        m_line = "";
        m_data = "";
        std::ifstream myfile(filename);
        if(myfile.is_open()) {
            while(std::getline(myfile, m_line)) {
                m_data += m_line + "\n";
                std::cout << m_line << '\n';
            }
            myfile.close();
        }
    }

    void File::Load(const vstring& filename) {
        m_line = "";
        m_data = "";
        std::ifstream myfile(filename);
        if(myfile.is_open()) {
            while(std::getline(myfile, m_line)) {
                m_data += m_line + "\n";
                std::cout << m_line << '\n';
            }
            myfile.close();
        }
    }
        
    void File::Save(const vstring& filename, const vstring& data) {
        std::ofstream myfile(filename);
        if(myfile.is_open()) {
            myfile << data;
            myfile.close();
        }
    }
};