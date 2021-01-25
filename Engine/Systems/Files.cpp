#include "Files.hpp"

namespace Lk {
    File::File(const std::string& filename) {
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

    void File::Load(const std::string& filename) {
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
        
    void File::Save(const std::string& filename, const std::string& data) {
        std::ofstream myfile(filename);
        if(myfile.is_open()) {
            myfile << data;
            myfile.close();
        }
    }

    std::string File::GetData() {
        return m_data;
    }
};